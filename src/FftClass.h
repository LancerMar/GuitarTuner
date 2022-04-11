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

 //   Q_OBJECT

public:
    /*!
     * constructor:
     */
    FftClass(int buffer_size = FFT_BUFFER_SIZE);
    
    /*!
     * destructor:
     */
    ~FftClass();

public:
     /*!
     * fill the buffer
     */
    void fill_buffer(int *);
    double update();

    double array[513];

private:
    double *in;
    fftw_complex *out;

    double *x;
    double *y;
    
    double mag;
    double yMax;
    int max_fre;
    int num_samples;
    int n_out;
    int nFreqSamples;
};

#endif 
