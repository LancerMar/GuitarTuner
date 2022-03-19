
#include <thread>

#include "Global.h"
#include "worker.h"

int main()
{
    worker worker_local;
    std::thread thread_worker(&worker::worker_thread,worker_local);
}