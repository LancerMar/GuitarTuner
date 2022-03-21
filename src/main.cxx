#include "i2s_mems_mic.h"
#include "MyDataProcessThread.h"
#include "MyI2sMicThread.h"

#include <iostream>

int main(int argc, char *argv[]) {

    // setting paramaters of driver
    I2SmicHasSample i2smic;
    i2smic.open_pcm();
    i2smic.set_params();
    
    // run the data generate thread and process thread
    MyI2sMicThread i2sMic(0,&i2smic);
    i2sMic.start();
    MyDataProcessThread dataProcess(0);
    dataProcess.start();

    i2sMic.join();
    dataProcess.join();

    i2smic.close_pcm();


    //dataProcess.testRun();
    return 0;
}
