#define BOOST_TEST_MODULE SqrTests
#include <boost/test/unit_test.hpp>

#include "lp.h"

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    Lp *lp;
    lp = new Lp(1000);
    BOOST_CHECK_EQUAL(0, lp->filter(0));
    BOOST_CHECK_EQUAL(0, lp->filter(1));
    BOOST_CHECK_EQUAL(0, lp->filter(2));
    BOOST_CHECK_EQUAL(0, lp->filter(3));
}