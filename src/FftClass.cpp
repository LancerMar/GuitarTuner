#include "FftClass.h"

#include <cmath>
#include <cstdint>


/*
 * used for fft process
 */
FftClass::FftClass(int buffer_size){
    num_samples=buffer_size;
    max_fre = 0;

    /* malloc a fft buffer */
    in = (double*)fftw_malloc(sizeof(double)*num_samples);

    /* nyquist frequency output theory  */
    n_out = ((num_samples/2)+1);
    
    /* claim a buffer */
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n_out);
    nFreqSamples = num_samples / 2;
    
    x = new double[nFreqSamples];
    y = new double[nFreqSamples];
    for(int i = 0; i < nFreqSamples;i++) {
        x[i] = 0.0;
        y[i] = 0.0;
    }
}

double FftClass::update(){

    fftw_plan plan_forward;

    /* real in complex out */
    plan_forward = fftw_plan_dft_r2c_1d(num_samples,in,out,FFTW_ESTIMATE);

    /* do it */
    fftw_execute(plan_forward);
    
    //destroy plan
    fftw_destroy_plan(plan_forward);
    
    yMax = 0.0;
    //print the output
    for(int i=0;i<n_out;i++)
    {   
        /* only care about its magnitude */
        mag = std::sqrt(out[i][0]*out[i][0] + out[i][1]*out[i][1]);
        array[i] = mag;
        if ((mag > yMax) &&  (i > 9)){
            yMax=mag;

            max_fre = i*((double)SAMPLE_RATE / FFT_BUFFER_SIZE);
        }
    }
    array[0] = 0;
    std::cout << max_fre << std::endl;
    return max_fre;
}

FftClass::~FftClass(){
    fftw_free(in);
    fftw_free(out);
    delete []x;
    delete []y;
}

/*!
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
