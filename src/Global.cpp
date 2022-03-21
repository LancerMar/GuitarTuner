#include "Global.h"

bool global_program_exit = false;

std::mutex global_data_process_mutex;
std::condition_variable globale_data_process_cv;
bool global_data_ready = false;

int32_t* global_pending_proc_audio_data;
int len_global_pending_proc_audio_data;


//===============for test ==================
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready;
bool processed;
//===============for test ==================