#include "MyDataProcessThread.h"

#include <iostream>

#include <fftw3.h>

#include "DataProcess.h"

void MyDataProcessThread::run(){
    //for test
    std::cout<<"hello MyDataProcessThread test"<<std::endl;
    DataProcess dataprocess;

    while(!global_program_exit){
        std::unique_lock<std::mutex> lock(global_data_process_mutex);
        globale_data_process_cv.wait(lock,[]{return global_data_ready;});
        {
            dataprocess.fft_trans();
            global_data_ready = false;

            // int32_t *buffer_tmp;
            // buffer_tmp = global_pending_proc_audio_data;
            // for(int i=0;i<len_global_pending_proc_audio_data;i++){
            //     out << *buffer_tmp << std::endl;
            //     buffer_tmp++;
            // }
        }
    }
};




//test code
void MyDataProcessThread::testRun()
{
    std::cout<<" this is just for debuging the run functions"<< std::endl;

    double *in;
    fftw_complex *out;
    //=============generate the ramdon number for test==============
    int32_t buffer[32];
    for (int i=0;i<32;i++)
    {
        buffer[i] = rand()%10+5;
    }
    //=============================================================
    int32_t *buffer_tmp;
    buffer_tmp = buffer;

    int num_samples=32;
    in = (double*)fftw_malloc(sizeof(double)*num_samples);
    for(int i=0;i<num_samples;i++){
        double buffer_num=(double)*buffer_tmp;
        buffer_tmp++;
        in[i]=buffer_num;
    }

    int n_out = ((num_samples/2)+1);
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n_out);

    fftw_plan plan_forward;
    plan_forward = fftw_plan_dft_r2c_1d(num_samples,in,out,FFTW_ESTIMATE);

    fftw_execute(plan_forward);

    fftw_destroy_plan ( plan_forward );

    //print the result
    std::cout<<"input number:"<<std::endl;
    for(int i=0;i<num_samples;i++)
    {
        std::cout<<in[i]<<std::endl;
    }
    std::cout<<"output number:"<<std::endl;
    for(int i=0;i<n_out;i++)
    {
        std::cout<<out[i][0]<<std::endl;
    }


    fftw_free(in);
    fftw_free(out);
}