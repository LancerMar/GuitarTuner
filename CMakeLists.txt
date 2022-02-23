cmake_minimum_required(VERSION 3.16.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GuitarTuner)

set(SRC
    src/main.cxx
    src/record.cpp)

add_executable(guitartuner ${SRC})

target_link_libraries(guitartuner asound)
