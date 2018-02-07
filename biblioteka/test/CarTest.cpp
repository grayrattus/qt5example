#include <boost/test/unit_test.hpp>
#include <Car.h>
#include <Segment.h>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    Car samochod(1000, "EBR 21GSL", 10000, SegmentPtr(new Segment('A')));
    BOOST_CHECK_EQUAL(samochod.actualRentalPrice(), 10000);
    BOOST_CHECK_EQUAL(samochod.getId(), "EBR 21GSL");
}

BOOST_AUTO_TEST_CASE(KonstruktorZmianaEngineDisplacement) {
    Car samochod(1200, "EBR 21GSL", 10000, SegmentPtr(new Segment('A')));
    BOOST_CHECK_EQUAL(samochod.actualRentalPrice(), 12000);
}

BOOST_AUTO_TEST_CASE(KonstruktorZmianaEngineDisplacement2) {
    Car samochod(1999, "EBR 21GSL", 10000, SegmentPtr(new Segment('A')));
    BOOST_CHECK_EQUAL(samochod.actualRentalPrice(), 19990);
}

BOOST_AUTO_TEST_CASE(KonstruktorSegmentuB) {
    Car samochod(1000, "EBR 21GSL", 10000, SegmentPtr(new Segment('B')));
    BOOST_CHECK_EQUAL(samochod.actualRentalPrice(), 11000);
}

BOOST_AUTO_TEST_CASE(TestPorownaniaTypow) {
    Car samochod1(1000, "EBR 21GSL", 10000, SegmentPtr(new Segment('B')));
    Car samochod2(1000, "EBR 21GSL", 10000, SegmentPtr(new Segment('B')));
    Car samochod3(1000, "OKL 23SDP", 10000, SegmentPtr(new Segment('B')));

    BOOST_CHECK_EQUAL(samochod1 == samochod2, true);
    BOOST_CHECK_EQUAL(samochod3 == samochod2, false);
}
