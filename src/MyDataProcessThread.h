#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H
#include "../lib/cppThread/CppThread.h" 

#include <fstream>

class MyDataProcessThread : public CppThread{

public:
    MyDataProcessThread(int _offset) {
        offset = _offset;
        out.open("test.txt");
    }

    void testRun();
private:
    void run();

private:
    int offset;
    std::ofstream out;
};



#endif // !PROCESS_THREAD_H
