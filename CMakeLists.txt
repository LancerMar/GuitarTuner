cmake_minimum_required(VERSION 3.7.0)

project(GuitarTuner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(FFTW3)
find_package(iir)

add_subdirectory(test)
enable_testing()

set(SRC
    src/FftClass.cpp
    src/i2s_mems_mic.cpp
    src/App.cpp
    src/lp.cpp  
    src/main.cxx
    src/window.cpp
    src/MyThread.cpp
    src/Global.cpp)

add_library(driver_test src/i2s_mems_mic.cpp src/Global.cpp)
add_library(fft_test src/FftClass.cpp)
add_library(iir_test src/lp.cpp)
add_executable(guitartuner ${SRC})

add_test(NAME DriverTest COMMAND DRIVER_TEST)
add_test(NAME IIRTest COMMAND IIR_TEST)
add_test(NAME FFTTest COMMAND FFT_TEST)
add_test(NAME ThreadTest COMMAND THREAD_TEST)

if(FFTW3_FOUND)
    include_directories(${FFTW3_INCLUDE_DIRS})
    link_directories(${FFTW3_LIBRARY_DIRS})
    target_link_libraries(guitartuner fftw3)
else(FFTW3_FOUND)
    message(FATAL_ERROR "FFTW3 not found")
endif(FFTW3_FOUND)

target_link_libraries(guitartuner iir)
target_link_libraries(guitartuner Qt5::Widgets asound ${CMAKE_THREAD_LIB_INIT})
target_link_libraries(guitartuner qwt-qt5)
