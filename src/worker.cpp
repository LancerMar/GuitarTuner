#include "worker.h"

#include <iostream>

#include "Global.h"

void worker::worker_thread(){
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock,[]{return ready;});

    std::cout<< "Worker thread is processing data"<<std::endl;
    data+= "has already been proced";

    processed =true;
    std::cout<<"worker thread signaled that data has been already proced"<<std::endl;

    lock.unlock();
    cv.notify_all();
}