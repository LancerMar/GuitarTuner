#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "CppThread.h"

class MyThread : public CppThread {

    public:
        MyThread() {
        
        }
        
    private:
        void run;
};

#endif
