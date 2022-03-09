# GuitarTuner
tune the each open string of Guitar to standard pitch

## Introduction
After using guitar for a long time, the string of the guitar will easily to loose.The loosen strings will cause the guitar string to be out of tune. In that way, we need a tuner to help us to redjust the string of each String

The most convenient way to retune the guit is to adjust each string when they are open. the standard frequency of each string is in the references

we can run our software on raspberry pi, and connect a microphone on it. In that way we can coloct the voice of Guitar and analyse them in real-time.  

## flow chart


## References

use standard microphone get the real-time voice singnal of guitar，
help guitar users to calibrate the tones of each string

according to Equal temperament(12 Equal temperament(12-TET)), we use 440Hz as our reference pitch, we got open tunings of each string.
![](standardTuning.PNG)

calculation Method:

open string 1 E4 440.0000 / 2 ^ ( 5 / 12 ) = 329.6276 Hz

open string 2 B3 440.0000 / 2 ^ ( 10 / 12 ) = 246.9417 Hz

open string 3 G3 440.0000 / 2 ^ ( 14 / 12 ) = 195.9977 Hz

open string 4 D3 440.0000 / 2 ^ ( 19 / 12 ) = 146.8324 Hz

open string 5 A2 440.0000 / 2 ^ ( 24 / 12 ) = 110.0000 Hz

open string 6 E2 440.0000 / 2 ^ ( 29 / 12 ) = 82.4069 Hz

## sensor references

## FAQ
ALSA Library : sound driver ; get data from sound card(Linux)

arecord : can read the source, it`s helpful to write our own driver

FFtw 3 lib : FFT Processing library

display: recommended use QT
## QT plot below
 
