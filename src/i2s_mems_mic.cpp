/* Use the newer ALSA API */
#define ALSA_PCM_NEW_HW_PARAMS_API

#include "i2s_mems_mic.h"

void I2Smic::open_pcm(){
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
    snd_pcm_hw_params_alloca(&params);
    int err;
    unsigned int rate;
    
    err = snd_pcm_hw_params_any(handle, params);
    if (err < 0) {
        fprintf(stderr,
               "Broken configuration for this PCM: no configurations avaliable: %s",
                snd_strerror(rc));
        exit(1);
    }

    err = snd_pcm_hw_params_set_access(handle, params,
                        SND_PCM_ACCESS_RW_INTERLEAVED); 
    if (err < 0) {
        fprintf(stderr,
                "Access type not available: %s",
                snd_strerror(rc));
        exit(1);
    }

    /* format */
    /* Signed 32-bit little-endian format */
    err = snd_pcm_hw_params_set_format(handle, params,
                                hwparams.format);
    if (err < 0) {
        fprintf(stderr,
                "Sample format non available: %s",
                snd_strerror(err));
        exit(1);
    }
    err = snd_pcm_hw_params_set_channels(handle, params, hwparams.channels);
    if (err < 0) {
        fprintf(stderr, "Channels count non avaliable");
        exit(1);
    }
    
    rate = hwparams.rate;
    err = snd_pcm_hw_params_set_rate_near(handle, params, &hwparams.rate, 0);
    assert(err >= 0);//dont understand it

    err = snd_pcm_hw_params_set_period_size_near(handle, params, &frames, 0);
    assert(err >= 0);

    err = snd_pcm_hw_params(handle, params);
    if (err < 0) {
        fprintf(stderr, "unable to installl hw params: ");
        exit(1);
    }

    /* Use a buffer large enough to hold period */
    snd_pcm_hw_params_get_period_size(params, &chunk_size, 0); 

    buffer = (char *) malloc(chunk_size * 4);/* 4 bytes/sample, 1 channels */  

    snd_pcm_hw_params_get_period_time(params, &val, 0);
}

void I2Smic::record_start(){
    int loops;
    
    open_pcm();
    set_params();

    loops = 5000000 / val;

    while (loops > 0) {
        loops--;
        rc = snd_pcm_readi(handle, buffer, frames);

        /* call back */
      
        /* end of call back */;

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

        rc = write(1, buffer, size);
        printf("\n");
        if (rc != size)
            fprintf(stderr,
                "short write: wrote %d bytes\n", rc);
    }
    close_pcm();

}

void I2Smic::close_pcm() {
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);

}
