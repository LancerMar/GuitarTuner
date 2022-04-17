#define BOOST_TEST_MODULE IIRTests
#include <boost/test/unit_test.hpp>

#include "lp.h"

BOOST_AUTO_TEST_CASE(IIR_TEST)
{
    Lp *lp;
    lp = new Lp(8000);
    lp->filter(12);
    lp->filter(22);
    lp->filter(5);
    lp->filter(16);
    //random test
    BOOST_CHECK_EQUAL(11, lp->filter(4));

    delete lp;
}
