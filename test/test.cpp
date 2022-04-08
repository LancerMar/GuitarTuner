#define BOOST_TEST_MODULE TSTTests
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "test_src.h"

BOOST_AUTO_TEST_CASE(TstTEST)
{
    test tst;
    std::cout<<"test==========="<<std::endl;
    BOOST_CHECK_EQUAL(1, tst.test001());
}