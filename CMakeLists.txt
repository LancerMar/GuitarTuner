cmake_minimum_required(VERSION 3.16.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GuitarTuner)

# add header files 

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/CppThread)

include_directories(${PROJECT_SOURCE_DIR}/src)
