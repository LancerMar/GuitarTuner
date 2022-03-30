#ifndef APP_H
#define APP_H

#include "DriverCallback.h"
#include "FftCallback.h"
#include "i2s_mems_mic.h"
#include "FftClass.h"
#include "lp.h"
#include "window.h"
#include "FftCallback.h"
#include <array>


class App : public DriverCallback, public FftCallback{

    public:
        App();
        void fftData(int32_t*, int) override;
        int* lpData(int *) override;
        void setup();
        void run();

    private:
        FftClass *fft;
        I2Smic mic; //default-initialise object
        Lp *lp;
        Window *window;
       
        int data[FFT_BUFFER_SIZE];
};

#endif

