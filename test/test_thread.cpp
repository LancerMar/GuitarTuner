#define BOOST_TEST_MODULE THREADTests
#include <boost/test/unit_test.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>
#include <string>

#include "CppThread.h"

char test_result[2];
char* ptest_result = test_result;

class MyTestThread: public CppThread{
public:
    MyTestThread(char test_param,int time) {
        _test_param=test_param;
        _time=time;
    }
private:
    void run();
private:
    char _test_param;
    int _time;
};

void MyTestThread::run(){
    std::this_thread::sleep_for(std::chrono::milliseconds(_time));
    *ptest_result = _test_param;
    ptest_result=ptest_result+1;
}

BOOST_AUTO_TEST_CASE(MULTI_THREAD_TEST)
{
    MyTestThread thread01('b',20);
    MyTestThread thread02('a',10);
    thread01.start();
    thread02.start();
    thread01.join();
    thread02.join();

    std::string result = test_result;
    BOOST_CHECK(result == "ab");
}