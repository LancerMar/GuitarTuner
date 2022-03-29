#ifndef WINDOW_H
#define WINDOW_H

#include "i2s_mems_mic.h"

#include <QtCore/qglobal.h>
#include <cstdint>
#include <qboxlayout.h>
#include <qmainwindow.h>
#include <qobject.h>
#include <qtimer.h>
#include <qwt/qwt_text.h>
#include <qwt/qwt_thermo.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QWidget>

#include <QBoxLayout>
#include <QPushButton>

/*
 * set frequency range
 */
#define DELAY 128

#define E4MIN 325
#define E4MAX 335
#define B3MIN 240
#define B3MAX 250
#define G3MIN 190
#define G3MAX 200
#define D3MIN 140
#define D3MAX 150
#define A2MIN 105
#define A2MAX 115
#define E2MIN 75
#define E2MAX 85

class Window : public QMainWindow
{
    Q_OBJECT;//qt global macro

private:
/*
    class I2S_MEMS : public I2Smic {
        public:
            I2S_MEMS(Window* w) : window(*w) {}
            virtual void hasSample(int32_t* buffer, int length) {
                for(int i = 0; i < length; i++){
                    window.addSample(buffer[i]);
                }
            }
        private:
            Window& window;//don't understand
    };
*/ 
public:

    /*
     * Initialise GUI and sets up mic
     */
    Window();

    /*
     *  
     */
    double* updateBuffer(double*);

    /*
     * Destructor
     */
   // ~Window();

//internal variable for this class
private:
    static constexpr int plotDataSize = 513;
    
    QTimer* counter;

    QPushButton  *E4;
    QPushButton  *B3;
    QPushButton  *G3;
    QPushButton  *D3;
    QPushButton  *A2;
    QPushButton  *E2;
    
    QwtPlot      *plot1;
    QwtPlot      *plot2;
    QwtPlotCurve *curve1;
    QwtPlotCurve *curve2;

    QVBoxLayout  *v1Layout;
    QVBoxLayout  *v2Layout; // vertical layout
    QHBoxLayout  *hLayout; // horizontal layout

    double xData[plotDataSize];
    double yData[plotDataSize];
   
    void setE4();
    void setB3();
    void setG3();
    void setD3();
    void setA2();
    void setE2();

private slots:
    void update();
};
#endif

