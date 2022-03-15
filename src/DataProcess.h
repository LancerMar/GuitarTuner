
#include "i2s_mems_mic.h"

class DataProcess:public I2Smic{
public:
    virtual void hasSample(int32_t* , int);
    void process();

private:
    int32_t* buffer_samples;
    int length;

};