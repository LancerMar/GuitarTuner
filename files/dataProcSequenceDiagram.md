@startuml

main -> myDriverThread : start driver thread
myDriverThread -> myDriverThread : set parameters
main -> myDataProcessThread : start process data thread

loop
    myDriverThread -> myDriverThread : read data from sensor
    myDriverThread -> myDataProcessThread : data (call back)
end

loop
myDataProcessThread -> myDataProcessThread : FFT
myDataProcessThread -> UI : Time and frequency \n domain data(callback)
end

@enduml