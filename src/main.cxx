
#include "MyDataProcessThread.h"

#include <iostream>

int main() {
    // MyProcessThread dataProcess(0);
    // dataProcess.start();
    // dataProcess.join();

    I2Smic* i2smic;
    MyDataProcessThread dataProcess(0,i2smic);
    dataProcess.testRun();
    
    // Record record;
    // record.record_start();
}
