#include "record.h"
#include "MyProcessThread.h"

#include <iostream>

int main() {
    // MyProcessThread dataProcess(0);
    // dataProcess.start();
    // dataProcess.join();

    MyProcessThread dataProcess(0);
    dataProcess.testRun();
    
    Record record;
    record.record_start();
}
