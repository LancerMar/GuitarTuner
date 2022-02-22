/* Use the newer ALSA API */
#define ALSA_PCM_NEW_HW_PARAMS_API

#include "record.h"

void Record::open_pcm(){

    /* Open PCM device for recording (capture) */
    rc = snd_pcm_open(&handle, "plughw:2",
                   SND_PCM_STREAM_CAPTURE, 0); /* checked but not sure about open_mode */
    if (rc < 0) {
        fprintf(stderr,
                "unable to open pcm device: %s\n",
                snd_strerror(rc));
        exit(1);
    }

  
}

void Record::alloca_to_obj() {
    /* Allocate a hardware parameters object. */
    snd_pcm_hw_params_alloca(&params); 

    /* Fill it in with default values. */
    rc = snd_pcm_hw_params_any(handle, params);
    if (rc < 0) {
        fprintf(stderr,
               "Broken configuration for this PCM: no configurations avaliable: %s",
                snd_strerror(rc));
        exit(1);
    }

}

void Record::interleave() {
    /* Interleaved mode */
    rc = snd_pcm_hw_params_set_access(handle, params,
                        SND_PCM_ACCESS_RW_INTERLEAVED); /* checked */
    if (rc < 0) {
        fprintf(stderr,
                "%s",
                snd_strerror(rc));
        exit(1);
    }


}

void Record::format(){
    /* format */
    /* Signed 32-bit little-endian format */
    snd_pcm_hw_params_set_format(handle, params,
                                SND_PCM_FORMAT_S32_LE);
}

void Record::mono_channel() {
    /* (mono) */
    snd_pcm_hw_params_set_channels(handle, params, 1);
}

void Record::set_sampling() {
    /* 44100 bits/second sampling rate (CD quality) */
    val = 44100;
    snd_pcm_hw_params_set_rate_near(handle, params,
                                    &val, &dir);
}

void Record::period_size() {
    /* Set period size to 32 frames. */
    frames = 32;
    snd_pcm_hw_params_set_period_size_near(handle,
                                params, &frames, &dir);

}

void Record::write_to_driver() {
    /* Write the parameters to the driver */
    rc = snd_pcm_hw_params(handle, params);
    if (rc < 0) {
      fprintf(stderr,
              "unable to set hw parameters: %s\n",
              snd_strerror(rc));
      exit(1);
  }
}

void Record::get_buffer() {
    /* Use a buffer large enough to hold one period */
    snd_pcm_hw_params_get_period_size(params,
                                        &frames, &dir);
    size = frames * 4; /* 4 bytes/sample, 1 channels */ /* 32 samples/period */
    buffer = (char *) malloc(size);
}

void Record::cal_period() {
    /* We want to loop for 5 seconds */
    snd_pcm_hw_params_get_period_time(params,
                                           &val, &dir); /* return val as approximate peroid duration in us */
}

void Record::record_start(){
    /* setting params */
    open_pcm();
    alloca_to_obj();
    interleave();
    format();
    mono_channel();
    set_sampling();
    period_size();
    write_to_driver();
    get_buffer();
    cal_period();

    loops = 5000000 / val;

    while (loops > 0) {
      loops--;
      rc = snd_pcm_readi(handle, buffer, frames);
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

void Record::close_pcm() {
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);

}
