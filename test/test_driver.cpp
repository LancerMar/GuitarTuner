#define BOOST_TEST_MODULE DriverTests
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "i2s_mems_mic.h"

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    I2Smic mic;
    mic.open_pcm();
    BOOST_CHECK_EQUAL(0, mic.get_rc());
}

BOOST_AUTO_TEST_CASE(PCM_SET_PARAMS_TEST)
{
    I2Smic mic;
    mic.open_pcm();
    mic.set_params();
    std::cout<<"rc_result: "<<mic.get_rc()<<std::endl;
    BOOST_CHECK_EQUAL(0, mic.get_rc());
}
