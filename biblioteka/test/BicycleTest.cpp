#include <boost/test/unit_test.hpp>
#include <Bicycle.h>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    Bicycle rower("EBR 21GSL", 10000);
    BOOST_CHECK_EQUAL(rower.actualRentalPrice(), 10000);
    BOOST_CHECK_EQUAL(rower.getId(), "EBR 21GSL");
}
