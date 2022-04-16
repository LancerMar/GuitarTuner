#ifndef LP_H
#define LP_H

#include <Iir.h>
#include <iir/Butterworth.h>

//cutoff frequency
#define CUTOFF 1000

class Lp {

    public:
        /*!
        * IIR filter constructor
        * 
        * this is a lowpass realtime IIR filter 
        *
        * @param int the sample rate
        */
        Lp(int);

        /*! 
        * execute real-time low-pass filtering on the current 
        * incoming audio data 
        *
        * @param int the sample
        */
        double filter(int v);

    private:
        Iir::Butterworth::LowPass<> lp;
};

#endif
