#include "MyProcessThread.h"

#include <iostream>
#include <fftw3.h>
#include <fstream>

void MyProcessThread::run(){
    //for test
    std::cout<<"hello MyProcessThread test"<<std::endl;
};

void MyProcessThread::testRun(){
    //std::cout<<" this is just for debuging the run functions"<< std::endl;

    fftw_complex *record_data;
    fftw_complex *dft_out_data;
    fftw_plan fft_processor;

    int N=1000;
    record_data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);
    std::ifstream file("testdata.dat");

    for(int i=0;i<N;i++)
    {
        record_data[i][0]=file.get
    }


}