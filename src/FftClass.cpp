#include <cmath>
#include <cstdint>

#include "FftCallback.h"
#include "FftClass.h"

/*
 * 
 */
FftClass::FftClass(int buffer_size)/*:QMainWindow()*/{
    /*
    times = new QTimer(this);
    connect(times, SIGNAL(timeout()), this, SLOT(update()));
    times->start(DELAY);
    */
    num_samples=buffer_size;
    max_fre = 0;
    yMax = 0;
    //real numbers in
    in = (double*)fftw_malloc(sizeof(double)*num_samples);
    n_out = ((num_samples/2)+1);//number of output
    
    //complex numbers out
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n_out);
    nFreqSamples = num_samples / 2;
    // plot
    /*
    fftPlot = new QwtPlot(this);
    fftPlot->setAxisAutoScale(QwtPlot::yLeft,true);
    fftPlot->setAxisAutoScale(QwtPlot::xBottom,true);
    fftCurve = new QwtPlotCurve("FFT");
    */
    x = new double[nFreqSamples];
    y = new double[nFreqSamples];
    for(int i = 0; i < nFreqSamples;i++) {
        x[i] = 0.0;
        y[i] = 0.0;
    }/*
    fftCurve->setRawSamples(x,y,nFreqSamples);
    fftCurve->attach(fftPlot);
    setCentralWidget(fftPlot);*/
}

void FftClass::registercallback(FftCallback *cb){
    this->callback = cb;
}

void FftClass::update(){

    fftw_plan plan_forward;

    // real in complex out
    plan_forward = fftw_plan_dft_r2c_1d(num_samples,in,out,FFTW_ESTIMATE);
    //double yMax = 0;
    // do it
    fftw_execute(plan_forward);
    //double f;
    //plot spectrum
    /*
    for(int i = 0; i < nFreqSamples;i++){
        f = ((double)i * SAMPLE_RATE/frames_number);
        x[i] = f;
        double a = out[i][0];
        double b = out[i][1];
        y[i] = sqrt(a*a+b*b);
        if(y[i] > yMax) yMax = y[i];

    }
    fftPlot->setAxisScale(QwtPlot::yLeft, 0, yMax);
    fftPlot->setAxisScale(QwtPlot::xBottom,0,f);*/
    //end of plot

    //destroy plan
    fftw_destroy_plan(plan_forward);
    //fftPlot->replot();
    //print the result
    /*
    std::cout<<"input number:"<<std::endl;
    for(int i=0;i<num_samples;i++)
    {
        std::cout<<in[i]<<std::endl;
    }
    */
    //print the output
    for(int i=0;i<n_out;i++)
    {
        mag = std::sqrt(out[i][0] * out[i][0] + out[i][1]*out[i][1]);
        //std::cout << mag << std::endl;
        array[i] = mag;
        if (mag> yMax && i > 2){
            yMax=mag;
            max_fre = i*(SAMPLE_RATE / FFT_BUFFER_SIZE);
        }
    }
    array[0] = 0;
    std::cout << max_fre << std::endl;
}

FftClass::~FftClass(){
    fftw_free(in);
    fftw_free(out);
}

/*
 * fill data into fft buffer
 */
void FftClass::fill_buffer(int* buffer_tmp){
    for(int i=0;i<num_samples;i++){
        double buffer_num=(double)*buffer_tmp;
        buffer_num /= INT32_MAX; 
        buffer_tmp++;
        in[i]=buffer_num;
    }
}
