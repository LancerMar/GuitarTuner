#include "window.h"
#include <qlabel.h>
#include <qpalette.h>

Window::Window(double *array, double *max_fre) {
    
    startTimer(40);
    buffer = array;
    this->max = max_fre;

    QLabel *label = new QLabel(this);
    label->setStyleSheet("QLabel { background-color : white; }");
    label->setText("red: too high! green: tuned! yellow: too loose!");

    label2 = new QLabel(this);
    label2->setStyleSheet("QLabel { background-color : white; }");
    
    label3 = new QLabel(this);
    label3->setStyleSheet("QLabel { background-color : white; }");

    thermo = new QwtThermo;
    thermo->setFillBrush( QBrush(Qt::red) );
    thermo->setScale(0,500);
    thermo->show();
    
    LCD = new QLCDNumber;
    LCD->setPalette(Qt::red);
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

    string_1 = new QPushButton("E4");
    connect(string_1, &QPushButton::clicked, this, &Window::setE4);
    string_2 = new QPushButton("B3");
    connect(string_2, &QPushButton::clicked, this, &Window::setB3);
    string_3 = new QPushButton("G3");
    connect(string_3, &QPushButton::clicked, this, &Window::setG3);
    string_4 = new QPushButton("D3");
    connect(string_4, &QPushButton::clicked, this, &Window::setD3);
    string_5 = new QPushButton("A2");
    connect(string_5, &QPushButton::clicked, this, &Window::setA2);
    string_6 = new QPushButton("E2");
    connect(string_6, &QPushButton::clicked, this, &Window::setE2);    
    

    // widgets displaying button
    v1Layout = new QVBoxLayout();
    v1Layout->addWidget(string_1);
    v1Layout->addWidget(string_2);
    v1Layout->addWidget(string_3);
    v1Layout->addWidget(string_4);
    v1Layout->addWidget(string_5);
    v1Layout->addWidget(string_6);

    v2Layout = new QVBoxLayout();
    v2Layout->addWidget(label);
    v2Layout->addWidget(thermo);
    v2Layout->addWidget(label2);
    v2Layout->addWidget(label3);
    v2Layout->addWidget(LCD);

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

    label2->setText("standard frequency: "+ QString::number(fre));

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
    int a = value - fre;
    LCD->display(a);
    if (a > 0)
        label3->setText("high");
    else
        label3->setText("low");

}


void Window::setE4() {
    fre_min = E4MIN;
    fre_max = E4MAX;
    fre = E4;
}

void Window::setB3() {
    fre_min = B3MIN;
    fre_max = B3MAX;
    fre = B3;
}

void Window::setG3() {
    fre_min = G3MIN;
    fre_max = G3MAX;
    fre = G3;
}

void Window::setD3() {
    fre_min = D3MIN;
    fre_max = D3MAX;
    fre = D3;
}

void Window::setA2() {
    fre_min = A2MIN;
    fre_max = A2MAX;
    fre = A2;
}

void Window::setE2() {
    fre_min = E2MIN;
    fre_max = E2MAX;
    fre = E2;
}
