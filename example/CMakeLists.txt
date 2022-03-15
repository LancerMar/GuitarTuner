cmake_minimum_required(VERSION 3.1.0)
find_package (Threads)
add_executable (i2s_printer i2s_printer.cpp)
target_link_libraries (i2s_printer 
                    i2smic
                    asound  
                    ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(i2s_printer PRIVATE ..)

