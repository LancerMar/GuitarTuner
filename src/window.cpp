#include "window.h"
#include "i2s_mems_mic.h"
#include <qwt/qwt_plot.h>
#include <qwt/qwt_text.h>

Window::Window() {
    i2s_mems = new I2S_MEMS(this);
    
    // set up the thermometer
    thermo = new QwtThermo;
    thermo->setFillBrush(QBrush(Qt::red));
    thermo->setScale(0, 10);
    thermo->show();
    
    // initial random input data
    for(int i = 0; i < plotDataSize; i++) {
        xData[i] = i;
        yData[i] = 1;
    }

    // plot1 is time domain, plot2 is frequency domain
    plot1 = new QwtPlot();
    plot1->setTitle("time domain");
    plot1->setAxisTitle(QwtPlot::xBottom,"time");
    plot1->setAxisTitle(QwtPlot::yLeft, "amplititude");
    plot2 = new QwtPlot();
    plot2->setTitle("frequency domain");
    plot2->setAxisTitle(QwtPlot::xBottom,"frequency");
    plot2->setAxisTitle(QwtPlot::yLeft,"amplititude");

    // make a plot curve from real time data and attach it
    // curve->setSamples(xData, yData, plotDataSize);
    // curve->attach(plot);

    plot1->replot();
    plot1->show();

    plot2->replot();
    plot2->show();

    button = new QPushButton("Reset");
    connect(button, &QPushButton::clicked, this, &Window::reset);

    // widgets displaying button and thermo
    v1Layout = new QVBoxLayout();
    v1Layout->addWidget(button);
    v1Layout->addWidget(thermo);

    v2Layout = new QVBoxLayout();
    v2Layout->addWidget(plot1);
    v2Layout->addWidget(plot2);

    // plot the vlayout on the left and thermo on right
    hLayout = new QHBoxLayout();
    hLayout->addLayout(v1Layout);
    hLayout->addLayout(v2Layout);


    setLayout(hLayout);
}

void Window::reset() {
    // set up the initial plot data
    for( int i = 0; i < plotDataSize; i++) {
        xData[i] = i;
        yData[i] = 0;
    }
}

/*
void Window::run() {
    i2s_mems->open_pcm();
    i2s_mems->set_params();
    i2s_mems->run();
    startTimer(40);
}
*/
/*
Window::~Window(){
    i2s_mems->close_pcm();
}
*/
void Window::addSample(int32_t v){
    //add sample value to plot
    memmove(yData, yData+1, (plotDataSize - 1)*sizeof(int32_t));
    yData[plotDataSize-1] = v;
}

void Window::timerEvent(QTimerEvent *) {
    curve->setSamples(xData, yData, plotDataSize);
    plot1->replot();
    plot2->replot();
    thermo->setValue(yData[0]);
    update();
}
