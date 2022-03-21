#ifndef I2S_MIC_THREAD_H
#define I2S_MIC_THREAD_H

#include "../lib/cppThread/CppThread.h" 

#include "i2s_mems_mic.h"

class MyI2sMicThread : public CppThread{

public:
    MyI2sMicThread(int _offset,I2SmicHasSample* _i2smic) {
        offset = _offset;
        i2smic = _i2smic;
    }
private:
    void run();

private:
    int offset;
    I2SmicHasSample* i2smic;
};


#endif // !I2S_MIC_THREAD_H