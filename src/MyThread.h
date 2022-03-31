#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "CppThread.h"
#include "App.h"

class MyFFtThread: public CppThread {
public:
    MyFFtThread() {
         app = new App();
    }
    void run();

private:
    App *app;
};
#endif
