#define BOOST_TEST_MODULE SqrTests
#include <boost/test/unit_test.hpp>

#include "i2s_mems_mic.h"

I2Smic mic;

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    BOOST_CHECK_EQUAL(1, mic.test_Test());
}

// BOOST_AUTO_TEST_CASE(SET_PCM_PARAMS_TEST)
// {
//     BOOST_CHECK_EQUAL(1, mic.set_params());
// }