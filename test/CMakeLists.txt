find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${GuitarTuner_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS}
                    )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (Test test.cpp)
target_link_libraries (Test
                        source_test
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


