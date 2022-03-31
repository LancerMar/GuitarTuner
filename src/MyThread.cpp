#include "MyThread.h"
#include <qapplication.h>

void MyFFtThread::run() {
    app->setup();
    app->run();
}
