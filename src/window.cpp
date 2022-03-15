#include "window.h"

Window::Window() {
    i2s_mems = new I2S_MEMS(this);
    
    // set up the thermometer
    thermo = new QwtThermo;
    thermo->setFillBrush( QBrush(Qt::red));
    thermo->setScale(0, 10);
    thermo->show();
    
    // initial random input data
    for(int i = 0; i < plotDataSize; i++) {
        xData[i] = i;
        yData[i] = 1;
    }

    curve = new QwtPlotCurve;
    plot = new QwtPlot;
    // make a plot curve from real time data and attach it
    curve->setSamples(xData, yData, plotDataSize);
    curve->attach(plot);

    plot->replot();
    plot->show();

    button = new QPushButton("Reset");
    connect(button, &QPushButton::clicked, this, &Window::reset);

    // widgets displaying button and thermo
    vLayout = new QVBoxLayout();
    vLayout->addWidget(button);
    vLayout->addWidget(thermo);

    // plot the vlayout on the left and thermo on right
    hLayout = new QHBoxLayout();
    hLayout->addLayout(vLayout);
    hLayout->addWidget(plot);

    setLayout(hLayout);
}

void Window::reset() {
    // set up the initial plot data
    for( int i = 0; i < plotDataSize; i++) {
        xData[i] = i;
        yData[i] = 0;
    }
}
void Window::run() {

}

Window::~Window(){
    i2s_mems->close_pcm();
}

void Window::addSample(int32_t v){
    //add sample value to plot
    memmove(yData, yData+1, (plotDataSize - 1)*sizeof(int32_t));
    yData[plotDataSize-1] = v;
}

void Window::timerEvent(QTimerEvent *) {
    curve->setSamples(xData, yData, plotDataSize);
    plot->replot();
    thermo->setValue(yData[0]);
    update();
}
