#ifndef RECORD_H
#define RECORD_H

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <errno.h>

#define WAV_FORMAT SND_PCM_FORMAT_S32_LE

static snd_pcm_t *handle;
static int open_mode = 0;
static snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
static char const* pcm_name = "plughw:2";
static snd_pcm_uframes_t frames = 32; // to be modified
static snd_pcm_uframes_t chunk_size = 1024; //to be decided
static unsigned int val;

static struct params{
    snd_pcm_format_t format = WAV_FORMAT;
    unsigned int channels = 1;
    unsigned int rate = 44100;
} hwparams;

class I2Smic {

public:

    void open_pcm();
    
    void set_params(void);

    void record_start();
    
    void close_pcm();

private:

    int size;
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
    char *buffer;
    int rc;   
};

#endif
