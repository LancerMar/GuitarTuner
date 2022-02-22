#ifndef RECORD_H
#define RECORD_H

#include <alsa/asoundlib.h>

class Record {



public:

    Record();

    void open_pcm();
    
    void alloca_to_obj();

    void interleave();

    void format();

    void mono_channel();

    void set_sampling();

    void period_size();

    void write_to_driver();

    void get_buffer();

   
    void cal_period();

    void record_start();
    
    void close_pcm();

private:

    long loops;
    int rc;
    int size;
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
    unsigned int val;
    int dir;
    snd_pcm_uframes_t frames;
    char *buffer;
    
};

#endif
