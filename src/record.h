#ifndef RECORD_H
#define RECORD_H

#include <alsa/asoundlib.h>

class DataProcessCallback{
public:
    virtual void hasSamples(int32_t &samples, int length) = 0;
};

class Record {

public:

    void registercallback(DataProcessCallback* dp);
    void unregistercallback();
    void record_start();

private:
    DataProcessCallback* data_process_callback;
};

#endif
