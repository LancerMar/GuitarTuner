#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>
#include <mutex>
#include <condition_variable>

//Controls whether the global program exits
extern bool global_program_exit;

// control the data generate thread and data process thread
extern std::mutex global_data_process_mutex;
extern std::condition_variable globale_data_process_cv;
extern bool global_data_ready;

// data transfer between threads
extern int32_t* global_pending_proc_audio_data;
extern int len_global_pending_proc_audio_data;


//===============for test ==================


extern std::mutex m;
extern std::condition_variable cv;
extern std::string data;
extern bool ready;
extern bool processed;
//===============for test ==================


#endif // !GLOBAL_H