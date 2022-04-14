#ifndef WINDOW_H
#define WINDOW_H

#include "i2s_mems_mic.h"

#include <QFrame>
#include <qboxlayout.h>
#include <QLabel>
#include <qmainwindow.h>
#include <QLCDNumber>
#include <qobject.h>
#include <qtimer.h>
#include <qwidget.h>
#include <qwt/qwt_text.h>
#include <qwt/qwt_thermo.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QWidget>
#include <qobjectdefs.h>
#include <qpushbutton.h>

/*
 * set frequency range
 */
#define DELAY 128

#define E4MIN 325
#define E4    329
#define E4MAX 335
#define B3MIN 240
#define B3    247
#define B3MAX 250
#define G3MIN 190
#define G3    196
#define G3MAX 200
#define D3MIN 140
#define D3    146
#define D3MAX 150
#define A2MIN 105
#define A2    110
#define A2MAX 115
#define E2MIN 75
#define E2    82
#define E2MAX 85

class Window : public QWidget
{
    Q_OBJECT; /*!< qt global macro */
public:
    /*!
    * constructor
    * 
    * Initialise the UI
    *
    * @param double* The first address pointer of the array of audio 
    * data in the frequency domain
    */
    Window(double *);


    /*! QT's timer trigger event
     *  
     * Trigger data refresh and UI refresh every 40ms
     * 
     *  @param QTimerEvent* QT's timer events
     */
    void timerEvent(QTimerEvent*);


//internal variable for this class
private:
    static constexpr int plotDataSize = 513;
    static constexpr double resolution = (double)SAMPLE_RATE / frames_number;

    QTimer* counter;
    double* max;

    QLCDNumber *LCD;

    QPushButton  *string_1;
    QPushButton  *string_2;
    QPushButton  *string_3;
    QPushButton  *string_4;
    QPushButton  *string_5;
    QPushButton  *string_6;
    
    //QwtPlot      *plot1;
    QwtPlot      *plot2;
    QwtPlotCurve *curve1;
    QwtPlotCurve *curve2;
    
    QwtThermo    *thermo;
    
    QLabel *label2;
    QLabel *label3;

    QVBoxLayout  *v1Layout;
    QVBoxLayout  *v2Layout; // vertical layout
    QVBoxLayout  *v3Layout;
    QHBoxLayout  *hLayout; // horizontal layout

    uint num=4;
    double xData[plotDataSize];
    double yData[plotDataSize];
    double *buffer;
    
    int fre_min=E4MIN, fre_max=E4MAX, fre = E4;

    void setE4();
    void setB3();
    void setG3();
    void setD3();
    void setA2();
    void setE2();

    

};
#endif

