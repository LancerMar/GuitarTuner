#ifndef FFT_CLASS_H
#define FFT_CLASS_H

#include <iostream>
#include <fftw3.h>
// #include <qmainwindow.h>
// #include <qobjectdefs.h>
// #include <qtimer.h>
#include <stdint.h>
// #include <qwt/qwt_plot.h>
// #include <qwt/qwt_plot_curve.h>
// #include <QMainWindow>

#include "i2s_mems_mic.h"

#define FFT_BUFFER_SIZE 1024

class FftClass{

public:
    /*! constructor:
     * 
     * Initialize all the data that needs to be used in the Fast Fourier transform
     * 
     *  @param int The data length of the data to be processed by the Fast Fourier 
     * Transform
     */
    FftClass(int buffer_size = FFT_BUFFER_SIZE);
    
    /*! destructor:
     * 
     * All the memory applied for on the heap are released here, otherwise it will 
     * cause memory overflow, thereby reducing the stability of the program；
     * 

     */
    ~FftClass();

public:
     /*! fill the buffer
     * 
     * Put the audio data collected in real time into the array to be fast Fourier 
     * transformed
     * 
     * @param int * Pointer to the first address of the audio data
     */

    void fill_buffer(int *);

    /*! execute the Fase fourier Transform and update the Data needed to update the 
     *UI
     * 
     * @return double The largest value of amplitude in the current spectrum
     */
    double update();

    double array[513]; /*!< Stores per-sample data in the frequency domain */
    double max_fre;
    double *max_fre_p = &max_fre;

private:
    double *in; //audio data in time domain
    fftw_complex *out; // audio data in frequency domain

    double *x; //<not used>
    double *y; //<not used>
    
    double mag; //magnitude of audio data in frequency domain
    double yMax; // the maxium amplitude samples

    int num_samples;
    int n_out; //the number of samples in the output of fast fourier Transform
    int nFreqSamples; //the number of samples in frequency domain
};

#endif 
