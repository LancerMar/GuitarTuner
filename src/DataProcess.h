
#include "i2s_mems_mic.h"

class DataProcess{
public:
    void registerI2smicCallback(I2Smic* i2wmic);
    void process();

public:
    static int32_t* buffer_samples;
    static int length;

};