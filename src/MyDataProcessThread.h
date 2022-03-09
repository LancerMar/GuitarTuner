#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

#include <fftw3.h>
#include "i2s_mems_mic.h"

class MyDataProcessThread : public CppThread{

public:
    MyDataProcessThread(int _offset,I2Smic i2smic) {
        offset = _offset;
        i2smic_Process = i2smic;
    }

    void testRun();
private:
    void run();

private:
    int offset;
    I2Smic i2smic_Process;
};



#endif // !PROCESS_THREAD_H
