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
        /*!
        * this is the constructor of Application class , this constructor Initialize
        * the FFT processing class, IIR processing class and  Init the UI
        */
        App();

        /*!
        * FFT processor
        *
        * This function is used to fast Fourier transform the audio data
        *
        * @param int* Pointer to the first address of the audio data to be processed
        * @param int The length of the audio data to be processed
        */
        void fftData(int*, int) override;

        /*!
        * IIR filter
        * 
        * This function is used to iir filter the audio data
        *
        * @param int* Pointer to the first address of the audio data to be processed
        */
        int* lpData(int* ) override;

        /*!
        * driver setup
        *
        * This function is used to  call the driver class's setup method to properly 
        * connect the mic
        * including register the callback function; open the data read and write channel 
        * of mic; Set data channel parameters to mic
        */
        void setup();

        /*!
        * receiving data
        *
        * This function is used to start the continuously process of recieving data from 
        * the mic. Should be called separately in a thread to prevent blocking the execution 
        * of the main process task
        */
        void run();
        
        /*!
        * destructor
        *
        * All the memory applied for on the heap are released here, otherwise it will 
        * cause memory overflow, thereby reducing the stability of the program
        */
        ~App();

    private:
        // pointer to the fft class
        FftClass *fft; 
        I2Smic mic; //default-initialise object
        // pointer to the iir filter class
        Lp *lp;
        // pointer to the UI class
        Window *window;
       
        // origin audio data
        int data[FFT_BUFFER_SIZE];
};

#endif

