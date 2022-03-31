#include "lp.h"

//lowpass constructor
Lp::Lp(int sample_rate) {
    lp.setup(sample_rate, CUTOFF);
}

//filter data
double Lp::filter(int v) {
    return lp.filter(v);
}

