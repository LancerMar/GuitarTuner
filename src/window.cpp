#include "window.h"
#include <qbrush.h>
#include <qnamespace.h>

Window::Window(double *array, double *max_fre) {
    
    startTimer(40);
    buffer = array;
    this->max = max_fre;

    QLabel *label = new QLabel(this);
    label->setStyleSheet("QLabel { background-color : yellow; }");
    label->setText("red: too high! green: tuned! yellow: too loose!");
    thermo = new QwtThermo;
    thermo->setFillBrush( QBrush(Qt::red) );
    thermo->setScale(0,500);
    thermo->show();

    /*
     *initial random input data
     */
    for(int i = 0; i < plotDataSize; i++) {
        xData[i] = i * resolution;
        yData[i] = 1;
    }
    
    plot2 = new QwtPlot();
    plot2->setTitle("frequency domain");
    plot2->setAxisTitle(QwtPlot::xBottom,"frequency");
    plot2->setAxisTitle(QwtPlot::yLeft,"amplititude");

    curve2 = new QwtPlotCurve;
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
    

    // widgets displaying button
    v1Layout = new QVBoxLayout();
    v1Layout->addWidget(E4);
    v1Layout->addWidget(B3);
    v1Layout->addWidget(G3);
    v1Layout->addWidget(D3);
    v1Layout->addWidget(A2);
    v1Layout->addWidget(E2);

    v2Layout = new QVBoxLayout();
    v2Layout->addWidget(label);
    v2Layout->addWidget(thermo);


    v3Layout = new QVBoxLayout();
    v3Layout->addWidget(plot2);

    // plot the vlayout on the left 
    hLayout = new QHBoxLayout();
    hLayout->addLayout(v1Layout);
    hLayout->addLayout(v2Layout);
    hLayout->addLayout(v3Layout);
    setLayout(hLayout);
}

/*
Window::~Window(){
    i2s_mems->close_pcm();
}
*/
void Window::timerEvent(QTimerEvent* event){
    curve2->setSamples(xData, buffer, plotDataSize);
    curve2->attach(plot2);
    plot2->replot();

    double value = *max;
    if(value < fre_min && value > 0){
        thermo->setFillBrush(QBrush(Qt::yellow));
        thermo->setValue(value);
    }
    else if(value >= fre_min && value <= fre_max){
        thermo->setFillBrush(QBrush(Qt::green));
        thermo->setValue(value);
    }
    else if(value < 500){
        thermo->setFillBrush(QBrush(Qt::red));
        thermo->setValue(value);
    }
}


void Window::setE4() {
    fre_min = E4MIN;
    fre_max = E4MAX;
}

void Window::setB3() {
    fre_min = B3MIN;
    fre_max = B3MAX;
}

void Window::setG3() {
    fre_min = G3MIN;
    fre_max = G3MAX;
}

void Window::setD3() {
    fre_min = D3MIN;
    fre_max = D3MAX;
}

void Window::setA2() {
    fre_min = A2MIN;
    fre_max = A2MAX;
}

void Window::setE2() {
    fre_min = E2MIN;
    fre_max = E2MAX;
}
