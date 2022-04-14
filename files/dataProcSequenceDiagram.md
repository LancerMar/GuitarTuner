@startuml
main -> myFFTThread : start driver thread
main -> UI : start UI thread
myFFTThread -> myFFTThread : set parameters

loop
    myFFTThread -> myFFTThread : read data from sensor
    myFFTThread -> myFFTThread : lowpass iir filter filter the  \r high freqency harmonics 
    myFFTThread -> myFFTThread : FFT
    myFFTThread -> UI : data: \r (data in frequency domain)\r (highest amplitude samples)
    UI-> UI: refresh the UI
end


@enduml