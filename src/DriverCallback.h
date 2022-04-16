#ifndef DRIVERCALLBACK_H
#define DRIVERCALLBACK_H


class DriverCallback {
    public:
        //virtual functions to be override
        /*!
	    * This virtual method is used to fast Fourier transform the raw data and 
        * output the frequency domain data
	    */
        virtual void fftData(int *, int) = 0;

        /*!
	    * This virtual method is used to iir filter the raw data in realtime
	    */
        virtual int* lpData(int *) = 0;
};

#endif
