find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${GuitarTuner_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS}
                    )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (Test test_mic.cpp)
target_link_libraries (Test
                        source_test
                        asound 
                        iir
                        ${CMAKE_THREAD_LIB_INIT}
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )

add_test (NAME GuitarTunerTest COMMAND Test)

