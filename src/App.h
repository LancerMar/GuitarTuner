#ifndef APP_H
#define APP_H

#include "DriverCallback.h"
#include "i2s_mems_mic.h"
#include "FftClass.h"
#include "lp.h"
#include "window.h"
#include <array>


class App : public DriverCallback{

    public:
        /* constructor */
        App();

        /* implement fft process function */
        void fftData(int32_t*, int) override;

        /* implement lowpass data function*/
        int* lpData(int *) override;

        /* setup application */
        void setup();

        /* start application */
        void run();
        
        /* destructor */
        ~App();

    private:
        FftClass *fft;
        I2Smic mic; //default-initialise object
        Lp *lp;
        Window *window;
    
        int data[FFT_BUFFER_SIZE];
};

#endif

