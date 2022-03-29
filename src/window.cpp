#include "window.h"
#include "i2s_mems_mic.h"
#include <alsa/seq_midi_event.h>
#include <cstring>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qtimer.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_text.h>

Window::Window() {
    
    counter = new QTimer(this);
    connect(counter,
            SIGNAL(timeout()),
            this,
            SLOT(update()));
    counter->start(DELAY);

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
    
    curve1 = new QwtPlotCurve;
    curve1->setSamples(xData, yData, plotDataSize);
    curve1->attach(plot1);

    curve2 = new QwtPlotCurve;
    curve2->setSamples(xData, yData, plotDataSize);
    curve2->attach(plot2);
    
    E4 = new QPushButton("E4");
    connect(E4, &QPushButton::clicked, this, &Window::setE4);
    B3 = new QPushButton("B3");
    connect(B3, &QPushButton::clicked, this, &Window::setB3);
    G3 = new QPushButton("G3");
    connect(G3, &QPushButton::clicked, this, &Window::setG3);
    D3 = new QPushButton("D3");
    connect(D3, &QPushButton::clicked, this, &Window::setD3);
    A2 = new QPushButton("A2");
    connect(A2, &QPushButton::clicked, this, &Window::setA2);
    E2 = new QPushButton("E2");
    connect(E2, &QPushButton::clicked, this, &Window::setE2);    

    // widgets displaying button and thermo
    v1Layout = new QVBoxLayout();
    v1Layout->addWidget(E4);
    v1Layout->addWidget(B3);
    v1Layout->addWidget(G3);
    v1Layout->addWidget(D3);
    v1Layout->addWidget(A2);
    v1Layout->addWidget(E2);

    v2Layout = new QVBoxLayout();
    v2Layout->addWidget(plot1);
    v2Layout->addWidget(plot2);

    // plot the vlayout on the left and thermo on right
    hLayout = new QHBoxLayout();
    hLayout->addLayout(v1Layout);
    hLayout->addLayout(v2Layout);


    setLayout(hLayout);
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
double* Window::updateBuffer(double *arr){
    //if copy array
    for(int i = 0 ; i< 513;i++) {
        yData[i] = arr[i];
    }
}

void Window::update() {
    plot1->replot();
    plot2->replot();
}


void Window::setE4() {
    int min = E4MIN;
    int max = E4MAX;
}

void Window::setB3() {
    int min = B3MIN;
    int max = B3MAX;
}

void Window::setG3() {
    int min = G3MIN;
    int max = G3MAX;
}

void Window::setD3() {
    int min = D3MIN;
    int max = D3MAX;
}

void Window::setA2() {
    int min = A2MIN;
    int max = A2MAX;
}

void Window::setE2() {
    int min = E2MIN;
    int max = E2MAX;
}

