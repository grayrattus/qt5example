#include <boost/test/unit_test.hpp>
#include <Client.h>
#include <Address.h>

#include "model/client_types/FrequentClient.h"
#include "model/client_types/NormalClient.h"

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    Client klient("Artur", "Dziedziczak", "95323430", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    BOOST_CHECK_EQUAL(klient.getFirstName(), "Artur");
    BOOST_CHECK_EQUAL(klient.getLastName(), "Dziedziczak");
    BOOST_CHECK_EQUAL(klient.getAddress(), "Moniuszki 4");
    BOOST_CHECK_EQUAL(klient.getRegisteredAddress(), "Moniuszki 4");
    BOOST_CHECK_EQUAL(klient.printRents(), "Nie wynajmuje niczego");
}

BOOST_AUTO_TEST_CASE(ZmianaTypuKlienta) {
    Client klient("Artur", "Dziedziczak", "953234309", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    BOOST_CHECK_EQUAL(klient.getDiscount(), 0);
    BOOST_CHECK_EQUAL(klient.getMaxRents(), 1);
    klient.changeType(ClientTypePtr(new FrequentClient()));
    BOOST_CHECK_EQUAL(klient.getDiscount(), 0.3);
    BOOST_CHECK_EQUAL(klient.getMaxRents(), 2);

}
BOOST_AUTO_TEST_CASE(PorownywanieKliento) {
    Client klient1("Artur", "Dziedziczak", "953234309", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    Client klient2("Tomasz", "Nawój", "953234309", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    Client klient3("Monika", "Nawój", "643123456", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));

    BOOST_CHECK_EQUAL(klient1 == klient2 , true);
    BOOST_CHECK_EQUAL(klient1 == klient3 , false);
}
