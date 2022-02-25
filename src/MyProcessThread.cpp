#include "MyProcessThread.h"

#include <iostream>

void MyProcessThread::run(){
    //for test
    std::cout<<"hello MyProcessThread test"<<std::endl;
};

void MyProcessThread::testRun(){
    std::cout<<" this is just for debuging the run functions"<< std::endl;
}