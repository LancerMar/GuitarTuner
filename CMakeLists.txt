cmake_minimum_required(VERSION 3.16.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(GuitarTuner)

find_package(FFTW3)
find_package(Threads)

set(SRC
    src/main.cxx
    src/MyProcessThread.cpp
    src/DataProcess.cpp)

add_executable(guitartuner ${SRC})

if(FFTW3_FOUND)
    include_directories(${FFTW3_INCLUDE_DIRS})
    link_directories(${FFTW3_LIBRARY_DIRS})
    target_link_libraries(guitartuner fftw3)
else(FFTW3_FOUND)
    message(FATAL_ERROR "FFTW3 not found")
endif(FFTW3_FOUND)

target_link_libraries(guitartuner 
                        asound 
                        ${CMAKE_THREAD_LIBS_INIT})
