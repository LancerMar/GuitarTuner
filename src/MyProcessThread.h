#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

#include <fftw3.h>

class MyProcessThread : public CppThread{

public:
    MyProcessThread(int _offset) {
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
