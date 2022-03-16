#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include <stdint.h>

class DataProcess{
public:
    void process();

public:
    int32_t* buffer_samples;
    int length;

};

#endif // !DATA_PROCESS_H