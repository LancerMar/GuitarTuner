#ifndef RECORD_H
#define RECORD_H


#define ALSA_PCM_NEW_HW_PARAMS_API

#define SAMPLE_RATE 8000
#define frames_number 1024

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <cstdint>
#include <errno.h>
#include <thread>
#include <mutex>

#include "Global.h"


typedef int32_t samp_t;

static struct snd_params{
    snd_pcm_format_t format = SND_PCM_FORMAT_S32_LE;
    unsigned int channels = 1;
    unsigned int rate = SAMPLE_RATE;
} hwparams;

class I2Smic {

public:
    /* directlly add abstract callback method in driver class, 
     * called when a buffer is avaliable
     */
    virtual void hasSample(int32_t* buff_samples, int sample_length) = 0;
    
    /**
     * open PCM device
     */
    void open_pcm();
    
    /**
     * set parameters 
     *
     **/
    void set_params(void);
    /**
     * close PCM device
     **/
    void close_pcm();
    
    /**
     * start to obtain sound sample
     */
    void run();
private:

    snd_pcm_t *handle;
    const int open_mode = 0;
    const snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
    char const* pcm_name = "plughw:2";
    snd_pcm_uframes_t frames; //should be 1000 samples
    unsigned int val;
    

    int size;
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;

    std::mutex readoutMtx;
    int rc;
    int32_t buffer[2][frames_number];/* 4 bytes/sample, 1 channels */ 
    unsigned currentBufIdx = 0;
};


class I2SmicHasSample : public I2Smic{
    virtual void hasSample(int32_t* buff, int len)
    {   
        global_pending_proc_audio_data = buff;
        len_global_pending_proc_audio_data = len;
        
        global_data_ready = true;
        globale_data_process_cv.notify_all();
    }
};

#endif
