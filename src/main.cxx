//#include "window.h"

#include <cstdint>
#include <iostream>
#include <QApplication>

#include "App.h"
#include "MyThread.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyFFtThread app;
    app.start();
    a.exec();
    return 0;

}
