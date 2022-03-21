#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>

// int32_t* global_pending_proc_audio_data;
// int len_global_pending_proc_audio_data;


//===============for test ==================
#include <mutex>
#include <condition_variable>

extern std::mutex m;
extern std::condition_variable cv;
extern std::string data;
extern bool ready;
extern bool processed;
//===============for test ==================


#endif // !GLOBAL_H