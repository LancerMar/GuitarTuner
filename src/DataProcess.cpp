#include <iostream>

#include "DataProcess.h"
#include "Global.h"

void DataProcess::fft_trans(){
    buffer_tmp = global_pending_proc_audio_data;
    int num_samples=len_global_pending_proc_audio_data;
    
    time_domain_data = (double*)fftw_malloc(sizeof(double)*num_samples);
    for(int i=0;i<num_samples;i++){
        double buffer_num=(double)*buffer_tmp;
        buffer_tmp++;
        time_domain_data[i]=buffer_num;
    }
    length_frequency_domian_data = ((num_samples/2)+1);
    frequency_domian_data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * length_frequency_domian_data);
    fftw_plan plan_forward;
    plan_forward = fftw_plan_dft_r2c_1d(num_samples,time_domain_data,frequency_domian_data,FFTW_ESTIMATE);
    fftw_execute(plan_forward);
    fftw_destroy_plan ( plan_forward );
    //print the result
    //std::cout<<"input number:"<<std::endl;
    for(int i=0;i<num_samples;i++)
    {
        //std::cout<<time_domain_data[i]<<std::endl;
    }
    std::cout<<"output number:"<<std::endl;
    for(int i=0;i<length_frequency_domian_data;i++)
    {
        //std::cout<<frequency_domian_data[i][0]<<std::endl;
    }

    get_highest_Amplify_Freq();

    fftw_free(time_domain_data);
    fftw_free(frequency_domian_data);
}

double DataProcess::get_highest_Amplify_Freq(){
    double result_freq = 0.0;
    double frequency_resolution = SAMPLE_RATE/frames_number;
    for(int i=0;i<length_frequency_domian_data;i++){
        if(frequency_domian_data[i][0]>FREQUENCY_DOMAIN_THRESHOLD){
            std::cout<<"Frequency above "<<FREQUENCY_DOMAIN_THRESHOLD<<" is: "<<i*frequency_resolution<<std::endl;
        }
    }

    return result_freq;
}   