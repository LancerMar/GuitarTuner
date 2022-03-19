#include "window.h"

#include <iostream>
#include <qwindowdefs.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //create the window
    Window window;
    window.show();

    window.run();

    window.startTimer(40);

    return app.exec();


}
