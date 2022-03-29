cmake_minimum_required(VERSION 3.7.0)

project(qwt-plot VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(FFTW3)
find_package(iir)

add_executable(qt5
  FftClass.cpp 
  i2s_mems_mic.cpp
  App.cpp
  lp.cpp  
  main.cxx
  window.cpp
)

include_directories(${FFTW3_INCLUDE_DIRS})
link_directories(${FFTW3_LIBRARY_DIRS})

target_link_libraries(qt5 fftw3 iir)
target_link_libraries(qt5 Qt5::Widgets asound ${CMAKE_THREAD_LIB_INIT})
target_link_libraries(qt5 qwt-qt5)
