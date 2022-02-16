#ifndef DEMO_THREAD_H
#define DEMO_THREAD_H

#include "CppThread.h"

class MyThread : public CppThread {

public:
	MyThread(int _offset) {
		offset = _offset;
	}

private:
	void run();

private:
	int offset;
};

#endif
