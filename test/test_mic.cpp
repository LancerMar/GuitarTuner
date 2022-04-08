#define BOOST_TEST_MODULE TSTTests
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "i2s_mems_mic.h"

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    I2Smic mic;
    mic.open_pcm();
    BOOST_CHECK_EQUAL(0, mic.get_rc());
}

// BOOST_AUTO_TEST_CASE(SET_PCM_PARAMS_TEST)
// {s
//     BOOST_CHECK_EQUAL(1, mic.set_params());
// }