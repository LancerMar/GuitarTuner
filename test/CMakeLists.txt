find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${GuitarTuner_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS}
                    )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (DRIVER_TEST test_driver.cpp)
target_link_libraries (DRIVER_TEST
                        driver_test
                        asound 
                        ${CMAKE_THREAD_LIB_INIT}
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )

add_executable(IIR_TEST test_iir.cpp)
target_link_libraries (IIR_TEST
                        iir_test
                        iir 
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )

add_executable(FFT_TEST test_fft.cpp)
target_link_libraries (FFT_TEST
                        fft_test
                        fftw3 
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )


add_executable(THREAD_TEST test_thread.cpp)
target_link_libraries (THREAD_TEST
                        ${CMAKE_THREAD_LIB_INIT}
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )

