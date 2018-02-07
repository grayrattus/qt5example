#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "Client.h"
#include "model/client_types/FrequentClient.h"
#include "model/client_types/NormalClient.h"

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
	
	/*
    ClientRepository repozytorium;
    shared_ptr<Client> client = make_shared<Client>("Artur", "Dziedziczak", "3423423432", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    
    repozytorium.create(client);
    BOOST_CHECK_EQUAL(repozytorium.find(client), true);
    
    repozytorium.remove(client);
    BOOST_CHECK_EQUAL(repozytorium.find(client), false);
    repozytorium.create(client);

    shared_ptr<Client> client2 = make_shared<Client>("Krystian", "Dziedziczak", "3423423432", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));
    repozytorium.update(client2);
    shared_ptr<Client> updatedClient = repozytorium.getClient(client2->getPersonalId());
    BOOST_CHECK_EQUAL(updatedClient->getFirstName(), "Krystian");
    */
}
