// #define BOOST_TEST_MODULE FFTTests
// #include <boost/test/unit_test.hpp>

// #include "FftClass.h"

// BOOST_AUTO_TEST_CASE(FFT_TEST)
// {
//     FftClass *fft;
//     fft = new FftClass();

//     int buffer[FFT_BUFFER_SIZE];
//     for (int i=0;i<FFT_BUFFER_SIZE;i++){
//         buffer[i] = sin(i)+2*sin(10*i)+sin(100*i);
//     }

//     fft->fill_buffer(buffer);
//     BOOST_CHECK_EQUAL(0, fft->update());
    
//     delete fft;
// }