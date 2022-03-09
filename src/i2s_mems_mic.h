#ifndef RECORD_H
#define RECORD_H

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <errno.h>
#include <thread>

#define WAV_FORMAT SND_PCM_FORMAT_S32_LE

/**
 * Callback for new samples which needs to be implemented by main
 * program. The function hasSample needs to be overloaded in the main
 * program.
 **/
class I2Scallback {
public:
    /**
     * Called when a sample is avaliable.
     * It needs to be implemented in a derived 
     * class.
     **/
    virtual void hasSample(float sample) = 0;
};

static struct params{
    snd_pcm_format_t format = WAV_FORMAT;
    unsigned int channels = 1;
    unsigned int rate = 44100;
} hwparams;

class I2Smic {

public:
    
   
    /*
     * open PCM device
     */
    void open_pcm();
    
    /**
     * set parameters 
     *
     **/
    void set_params(void);
    
    /**
     * start data aquistion
     **/
    void start();
    
    /**
     * close PCM device
     **/
    void close_pcm();
    
    /**
     * Register the callback which is called whenever there is a sample.
     **/
    void registerCallback(I2Scallback* cb);
    void run();

private:

    snd_pcm_t *handle;
    const int open_mode = 0;
    const snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
    char const* pcm_name = "plughw:2";
    snd_pcm_uframes_t frames = 32; 
    unsigned int val;

    int size;
    std::thread* dacthread = nullptr;
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
    /*
    static void exec(I2Smic* i2smic) {
        i2smic->run();
    }
    */
    int rc;
    I2Scallback* i2scallback = nullptr;
    int32_t buffer[2][32];/* 4 bytes/sample, 1 channels */ 
    unsigned currentBufIdx = 0;
};

#endif
