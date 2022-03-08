#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

#include <fftw3.h>
#include "record.h"

class MyDataProcessThread : public CppThread{

public:
    MyDataProcessThread(int _offset,Record record) {
        offset = _offset;
        record_Process = record;
    }

    void testRun();
private:
    void run();

private:
    int offset;
    Record record_Process;
};



#endif // !PROCESS_THREAD_H
