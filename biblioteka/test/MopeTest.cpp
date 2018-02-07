#include <boost/test/unit_test.hpp>
#include <Mope.h>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    Mope motocykl(1000, "EBR 21GSL", 10000);
    BOOST_CHECK_EQUAL(motocykl.actualRentalPrice(), 10000);
    BOOST_CHECK_EQUAL(motocykl.getId(), "EBR 21GSL");
}

BOOST_AUTO_TEST_CASE(KonstruktorZmianaEngineDisplacement) {
    Mope motocykl(1200, "EBR 21GSL", 10000);
    BOOST_CHECK_EQUAL(motocykl.actualRentalPrice(), 12000);
}

BOOST_AUTO_TEST_CASE(KonstruktorZmianaEngineDisplacement2) {
    Mope motocykl(1999, "EBR 21GSL", 10000);
    BOOST_CHECK_EQUAL(motocykl.actualRentalPrice(), 19990);
}
