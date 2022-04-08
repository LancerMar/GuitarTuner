#define BOOST_TEST_MODULE TSTTests
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "i2s_mems_mic.h"

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    //I2Smic mic;
    std::cout<<"ttt============"<<std::endl;
    //BOOST_CHECK_EQUAL(1, mic.test_Test());
    BOOST_CHECK_EQUAL(1, 1);
}

// BOOST_AUTO_TEST_CASE(SET_PCM_PARAMS_TEST)
// {s
//     BOOST_CHECK_EQUAL(1, mic.set_params());
// }