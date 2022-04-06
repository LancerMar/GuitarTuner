#ifndef I2S_H
#define I2S_H

#define ALSA_PCM_NEW_HW_PARAMS_API

#define SAMPLE_RATE 8000

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <cstdint>
#include <errno.h>
#include <thread>
#include <mutex>

#include "DriverCallback.h"

//buffer size
#define frames_number 1024

static struct snd_params{
    snd_pcm_format_t format = SND_PCM_FORMAT_S32_LE;
    unsigned int channels = 1;
    unsigned int rate = SAMPLE_RATE;
} hwparams;

class I2Smic {

public:
    
   
    /*
     * open PCM device
     */
    int open_pcm();
    
    /**
     * set parameters 
     *
     **/
    int set_params(void);
    /**
     * close PCM device
     **/
    void close_pcm();
    
    /*
     * start to obtain sound sample
     */
    void run();
    
    /*
     * register callback
     */
    void registercallback(DriverCallback* cb);
    
    /*
     * destructor
     */
    ~I2Smic() {
        this->close_pcm();
    }
private:

    snd_pcm_t *handle;
    const int open_mode = 0;
    const snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
    char const* pcm_name = "plughw:2";//sound device name
    snd_pcm_uframes_t frames; 
    unsigned int val;
    
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
   
    DriverCallback* callback;
    int rc;
    std::mutex readoutMtx;
    int buffer[2][frames_number];
    unsigned currentBufIdx = 0;
};

#endif
