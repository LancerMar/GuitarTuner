
#include "MyDataProcessThread.h"

#include <iostream>

int main(int argc, char *argv[]) {

    I2Smic* i2smic;
    MyDataProcessThread dataProcess(0,i2smic);
    dataProcess.testRun();
    
    // Record record;
    // record.record_start();
}
