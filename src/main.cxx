#include <stdio.h>

#include "i2s_mems_mic.h"

int main() {
    I2Smic rec;
    rec.open_pcm();
    rec.set_params();
    rec.record_start();
    
    return 0;
}
