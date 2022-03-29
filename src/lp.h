#ifndef LP_H
#define LP_H

#include <Iir.h>
#include <iir/Butterworth.h>
#define CUTOFF 350

class Lp {

    public:
        Lp(int);
        double filter(int v);
    private:
        Iir::Butterworth::LowPass<> lp;
};

#endif
