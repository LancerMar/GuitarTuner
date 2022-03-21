#include "Global.h"

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready;
bool processed;