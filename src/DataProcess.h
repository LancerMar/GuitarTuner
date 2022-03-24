#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#define FREQUENCY_DOMAIN_THRESHOLD 2000000000

#include "i2s_mems_mic.h"
#include <fftw3.h>


class DataProcess{
public:
    void fft_trans();
    double get_highest_Amplify_Freq();

private:
    double *time_domain_data;
    fftw_complex *frequency_domian_data;
    int length_frequency_domian_data;
    
    int32_t *buffer_tmp;    // original data from driver
};

#endif // !DATA_PROCESS_H