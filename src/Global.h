#ifndef Global_H
#define Global_H

#include <stdint.h>

int32_t* global_pending_proc_audio_data;
int len_global_pending_proc_audio_data;


//===============for test ==================
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready =  false;
bool processed = false;
//===============for test ==================

#endif // !Global_H