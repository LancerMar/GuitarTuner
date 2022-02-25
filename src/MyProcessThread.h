#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H

#include "../lib/CppThread/CppThread.h"

class MyProcessThread : public CppThread{

public:
    MyProcessThread(int _offset) {
        offset = _offset;
    }

private:
    void run();

private:
    int offset;
};



#endif // !PROCESS_THREAD_H
