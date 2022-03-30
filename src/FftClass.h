#ifndef FFT_CLASS_H
#define FFT_CLASS_H

#include <iostream>
#include <fftw3.h>
#include <qmainwindow.h>
#include <qobjectdefs.h>
#include <qtimer.h>
#include <stdint.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QMainWindow>

#include "i2s_mems_mic.h"
#include "FftCallback.h"

#define FFT_BUFFER_SIZE 1024

class FftClass{

 //   Q_OBJECT

public:
    /*
     * constructor:
     */
    FftClass(int buffer_size = FFT_BUFFER_SIZE);
    
    /*
     * register callback
     */
    void registercallback(FftCallback* cb);

    /*
     * destructor:
     */
    ~FftClass();

public:
    
    void fill_buffer(int *);
    void update();

    double array[513];

private:
    double *in;
    fftw_complex *out;

    double *x;
    double *y;
    
    FftCallback *callback;
    QwtPlotCurve *fftCurve;
    QwtPlot* fftPlot;
    double mag;
    int max_fre;
    int yMax;
    int num_samples;
    int n_out;
    int nFreqSamples;
};

#endif 
