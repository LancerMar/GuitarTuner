#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

#include <fftw3.h>

class DataProcessCallback{
public:
    virtual void hasSamples(int32_t &samples, int length) = 0;
};

class MyDataProcessThread : public CppThread{

public:
    MyDataProcessThread(int _offset) {
        offset = _offset;
    }

    void testRun();
private:
    void run();

private:
    int offset;
    double *in;
    fftw_complex *out;
};



#endif // !PROCESS_THREAD_H
