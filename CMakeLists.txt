cmake_minimum_required(VERSION 3.16.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(GuitarTuner)

set(SRC
    src/main.cxx
    src/record.cpp
    src/MyProcessThread.cpp)

add_executable(guitartuner ${SRC})
find_package (Threads)
target_link_libraries(guitartuner 
                        asound 
                        ${CMAKE_THREAD_LIBS_INIT})
