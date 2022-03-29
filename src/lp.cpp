#include "lp.h"

Lp::Lp(int sample_rate) {
    lp.setup(sample_rate, CUTOFF);
}

double Lp::filter(int v) {
    return lp.filter(v);
}

