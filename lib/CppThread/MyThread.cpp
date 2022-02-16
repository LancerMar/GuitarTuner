#include "MyThread.h"

#include <stdio.h>
#include <chrono>
#include <thread>

void MyThread::run() {
	for(int i=0;i<10;i++) {
		printf("%d\n",i+offset);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
