#ifndef LP_H
#define LP_H

#include <Iir.h>
#include <iir/Butterworth.h>

//cutoff frequency
#define CUTOFF 1000

class Lp {

    public:
        Lp(int);
        double filter(int v);

    private:
        Iir::Butterworth::LowPass<> lp;
};

#endif
