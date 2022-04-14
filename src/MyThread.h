#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "CppThread.h"
#include "App.h"

class MyFFtThread: public CppThread {
public:
    /*! thread constructure
    * 
    * Thread for performing all background processing, including audio data 
    * obtaining, real-time low-pass filtering of audio data, fast Fourier 
    * transform of audio data
    */
    MyFFtThread() {
         app = new App();
    }

    /*! thread execution function 
    *
    * Methods that need to be executed in a thread: execute parameter settings
    * for mic; continuously read data from an open data channel
    */
    void run();

private:
    App *app;
};
#endif
