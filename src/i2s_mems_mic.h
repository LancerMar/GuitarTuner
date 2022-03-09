#ifndef RECORD_H
#define RECORD_H

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <errno.h>
#include <thread>

#define WAV_FORMAT SND_PCM_FORMAT_S32_LE

static snd_pcm_t *handle;
static int open_mode = 0;
static snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
static char const* pcm_name = "plughw:2";
static snd_pcm_uframes_t frames = 32; // to be modified
static unsigned int val;

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
    virtual void hasSample(int32_t* samples, int length) = 0;
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

public:
    //store state of the processing  
    static bool data_process_start;

private:

    int size;
    std::thread* dacthread = nullptr;
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
    char *buffer;
    void run();
    static void exec(I2Smic* i2smic) {
        i2smic->run();
    }
    int rc;
    I2Scallback* i2scallback = nullptr;

};

#endif