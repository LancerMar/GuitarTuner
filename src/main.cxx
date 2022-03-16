#include "i2s_mems_mic.h"
// #include "MyDataProcessThread.h"

#include <iostream>

int main(int argc, char *argv[]) {

    I2SmicHasSample mic;
    mic.open_pcm();
    mic.set_params();
    mic.run();
    mic.close_pcm();



    // I2Smic* i2smic;
    // i2smic = &mic;
    // MyDataProcessThread dataProcess(0,i2smic);
    // dataProcess.testRun();
    
    // Record record;
    // record.record_start();
}
