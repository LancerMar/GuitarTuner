#ifndef FFTCALLBACK_H
#define FFTCALLBACK_H

class FftCallback {
    public:
        //plot frequency data buffer
        virtual void plotBuffer(double *) = 0;
};

#endif
