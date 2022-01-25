# GuitarTuner
Tune the each open string of Guitar to standard pitch.

## Introduction
After using guitar for a long time, the string of the guitar will easily to be loose.The loose strings will cause the guitar string to be out of tune. In that way, we need a tuner to help us to redjust the string of each string.

The most convenient way to retune the guitar is to adjust each string when they are open. The standard frequency of each string is presented.

We run our software on **Raspberry Pi MOdel 4b**, and connect **a I2S microphone** on it. In that way we can receive the sound of guitar and analyse them in real-time.  

## Flow chart


## References

Use standard microphone get the real-time voice singnal of guitar，it help guitar users to calibrate the tones of each string.

According to Equal temperament(12 Equal temperament(12-TET)), we use 440Hz as our reference pitch, we got open tunings of each string.
![](standardTuning.PNG)

Calculation Method:

Open string 1 E4 440.0000 / 2 ^ ( 5 / 12 ) = 329.6276 Hz

Open string 2 B3 440.0000 / 2 ^ ( 10 / 12 ) = 246.9417 Hz

Open string 3 G3 440.0000 / 2 ^ ( 14 / 12 ) = 195.9977 Hz

Open string 4 D3 440.0000 / 2 ^ ( 19 / 12 ) = 146.8324 Hz

Open string 5 A2 440.0000 / 2 ^ ( 24 / 12 ) = 110.0000 Hz

Open string 6 E2 440.0000 / 2 ^ ( 29 / 12 ) = 82.4069 Hz

## Sensor References

## FAQ
ALSA Library : sound driver ; get data from sound card(Linux)

arecord : can read the source, it`s helpful to write our own driver

FFtw 3 lib : FFT Processing library

display: recommended use QT 
 
