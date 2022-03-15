#ifndef WINDOW_H
#define WINDOW_H

#include "i2s_mems_mic.h"

#include <QtCore/qglobal.h>
#include <cstdint>
#include <qobject.h>
#include <qwt/qwt_thermo.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QWidget>

#include <QBoxLayout>
#include <QPushButton>

class Window : public QWidget
{
    Q_OBJECT;//dont understand

private:

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
public:

    /*
     * Initialise GUI and sets up mic
     */
    Window();

    /*
     *  
     */
    void run();

    /*
     * Destructor
     */
    ~Window();

//internal variable for this class
private:
    static constexpr int plotDataSize = 100;


    QPushButton  *button;
    QwtThermo    *thermo;
    QwtPlot      *plot;
    QwtPlotCurve *curve;

    QVBoxLayout  *vLayout; // vertical layout
    QHBoxLayout  *hLayout; // horizontal layout

    double xData[plotDataSize];
    double yData[plotDataSize];   
    
    void reset();
    void addSample(int32_t);
    void timerEvent(QTimerEvent *);

    I2S_MEMS* i2s_mems;
};
#endif

