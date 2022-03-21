

#include <thread>
#include <iostream>
#include <string>


#include "Global.h"
#include "worker.h"


int main()
{
    worker worker_local;
    std::thread thread_worker(&worker::worker_thread,worker_local);

    data = "Example data";
    {
        std::lock_guard<std::mutex> lock(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock,[]{return processed;});
    }

    std::cout<< "data = "<< data <<std::endl;


}