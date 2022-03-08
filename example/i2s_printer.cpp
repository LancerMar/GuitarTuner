#include <stdio.h>

#include "../i2s_mems_mic.h"


// Handler which receives the data and prints it on the
// screen

class i2s_printerCallBack : public I2Scallback {
    virtual void hasSample(float v) {
        printf("%e\n", v);
    }
};

int main() {
    i2s_printerCallBack i2sprintercallback;
    I2Smic i2smic;
    i2smic.open_pcm();
    i2smic.registerCallback(&i2sprintercallback);
    i2smic.set_params();
    i2smic.start();
    //i2smic.close_pcm();   
    return 0;
}
