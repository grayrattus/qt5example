#include <boost/test/unit_test.hpp>
#include <Address.h>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    Address adres("Moniuszki", "4");
    BOOST_CHECK_EQUAL(adres.getNumber(), "4");
    BOOST_CHECK_EQUAL(adres.getStreet(), "Moniuszki");
    BOOST_CHECK_EQUAL(adres.toString(), "Moniuszki 4");
}

BOOST_AUTO_TEST_CASE(ModyfikowanieAdresu) {
    Address adres("", "");
    adres.setNumber("4");
    BOOST_CHECK_EQUAL(adres.toString(), " 4");
    BOOST_CHECK_EQUAL(adres.getNumber(), "4");
    BOOST_CHECK_EQUAL(adres.getStreet(), "");
    adres.setStreet("Moniuszki");
    BOOST_CHECK_EQUAL(adres.toString(), "Moniuszki 4");
    BOOST_CHECK_EQUAL(adres.getNumber(), "4");
    BOOST_CHECK_EQUAL(adres.getStreet(), "Moniuszki");
}

