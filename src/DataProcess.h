#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include "i2s_mems_mic.h"


class DataProcess{
public:
    void process();

public:
    static int32_t* buffer_samples;
    static int length;

};

#endif // !DATA_PROCESS_H