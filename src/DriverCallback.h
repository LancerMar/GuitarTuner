#ifndef DRIVERCALLBACK_H
#define DRIVERCALLBACK_H


class DriverCallback {
    public:
        //virtual functions to be overriden
        virtual void fftData(int *, int) = 0;//fft process
        virtual int32_t* lpData(int *) = 0;// low pass data

};

#endif
