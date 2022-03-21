#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

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
};



#endif // !PROCESS_THREAD_H
