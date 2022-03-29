//#include "window.h"

#include <cstdint>
#include <iostream>
#include <QApplication>

#include "App.h"
#include "window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);   
    App app;

    app.setup();
    app.run();
    
    return a.exec();
    /*
    QApplication a(argc, argv);

    //create the window
    Window window;
    window.show();

    return a.exec();
*/
}
