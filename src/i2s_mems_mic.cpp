/* Use the newer ALSA API */
#include "i2s_mems_mic.h"

#include <cmath>

#include "Global.h"

#define ALSA_PCM_NEW_HW_PARAMS_API


void I2Smic::open_pcm(){

    //open PCM device
    rc = snd_pcm_open(&handle, pcm_name,
                   stream, open_mode);
    if (rc < 0) {
        fprintf(stderr,
                "unable to open pcm device: %s\n",
                snd_strerror(rc));
        exit(1);
    }
    
}


void I2Smic::set_params(void) {
    snd_pcm_hw_params_t *params;

    /* allocate a hardware params obj  */
    snd_pcm_hw_params_alloca(&params);
    int err;
    
    //snd_pcm_hw_params_alloca(&params); 
    err = snd_pcm_hw_params_any(handle, params);
    if (err < 0) {
        fprintf(stderr,
               "Broken configuration for this PCM: no configurations avaliable: %s",
                snd_strerror(rc));
        exit(1);
    }
    
    /* Interleaved mode */
    err = snd_pcm_hw_params_set_access(handle, params,
                        SND_PCM_ACCESS_RW_INTERLEAVED); 
    if (err < 0) {
        fprintf(stderr,
                "Access type not available: %s",
                snd_strerror(rc));
        exit(1);
    }

    /* format */
    err = snd_pcm_hw_params_set_format(handle, params,
                                hwparams.format);
    if (err < 0) {
        fprintf(stderr,
                "Sample format non available: %s",
                snd_strerror(err));
        exit(1);
    }

    /* one channel (mono)*/
    err = snd_pcm_hw_params_set_channels(handle, params, hwparams.channels);
    if (err < 0) {
        fprintf(stderr, "Channels count non avaliable");
        exit(1);
    }
    
    /* set sampling rate */
    err = snd_pcm_hw_params_set_rate_near(handle, params, &hwparams.rate, 0);
    assert(err >= 0);//dont understand it
    
    /* set period size */
    frames = frames_number;
    err = snd_pcm_hw_params_set_period_size_near(handle, params, &frames, 0);
    assert(err >= 0);
    
    /* write parameters to the driver  */
    err = snd_pcm_hw_params(handle, params);
    if (err < 0) {
        fprintf(stderr, "unable to installl hw params: ");
        exit(1);
    }

    /* Use a buffer large enough to hold period */
    snd_pcm_hw_params_get_period_size(params, &frames, 0); 
    size = frames * sizeof(samp_t);
    
    
    /* get period time */
    snd_pcm_hw_params_get_period_time(params, &val, 0);
    
}

void I2Smic::run(){
    while (!global_program_exit) {
        rc = snd_pcm_readi(handle, buffer[currentBufIdx], frames);

        if (rc == -EPIPE) {
            /* EPIPE means overrun */
            fprintf(stderr, "overrun occurred\n");
            snd_pcm_prepare(handle);
        } else if (rc < 0) {
            fprintf(stderr,
                "error from read: %s\n",
                snd_strerror(rc));
        } else if (rc != (int)frames) {
            fprintf(stderr, "short read, read %d frames\n", rc);
        }

        /* callback here, lowpass data and fft process */
        buffer[currentBufIdx] = callback->lpData(buffer[currentBufIdx]);
        callback->fftData(buffer[currentBufIdx], frames);
    
        /*
        rc = write(1, buffer, size); // write to stdout
        if (rc != size)
            fprintf(stderr,
                "short write: wrote %d bytes\n", rc); 
                */
        
        /*
         * switching buffer
         */
        readoutMtx.lock();
        currentBufIdx = !currentBufIdx;
        readoutMtx.unlock();
        
    }
}

/* register callback */
void I2Smic::registercallback(DriverCallback* cb) {
    this->callback = cb;
}

/* stop data acquisition */
void I2Smic::close_pcm() {
    global_program_exit=true;
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);
}
