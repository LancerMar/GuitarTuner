#define BOOST_TEST_MODULE IIRTests
#include <boost/test/unit_test.hpp>

#include "lp.h"

BOOST_AUTO_TEST_CASE(IIR_TEST)
{
    Lp *lp;
    lp = new Lp(1000);
    BOOST_CHECK_EQUAL(0, lp->filter(0));

    delete lp;
}