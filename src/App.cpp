#include "App.h"
#include "window.h"
#include <array>

App::App() {
    fft = new FftClass();
    lp = new Lp(SAMPLE_RATE);
    window = new Window(fft->array);
    window->show();
}

/*
 * lowpass process data
 */
int* App::lpData(int *buffer_tmp){
    for(int i = 0; i < FFT_BUFFER_SIZE;i++){
        data[i] = lp->filter((*buffer_tmp));
        buffer_tmp++;
    }
    return data;   
}

/*
 * fft process data
 */
void App::fftData(int* buffer, int frames) {
    fft->fill_buffer(buffer);
    fft->update();
}

/*
 * plot frequency buffer data
 *
void App::plotBuffer(double *arr) {
    window->updateBuffer(arr);
}
*/
/*
 * setup driver params
 */
void App::setup(){
    mic.registercallback(this);
    mic.open_pcm();
    mic.set_params();
}

/*
 * start data acquistion
 */
void App::run(){
    mic.run();
}

App::~App(){
    delete fft;
    delete lp;
    delete window;
}
