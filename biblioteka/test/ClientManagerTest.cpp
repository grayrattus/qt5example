#include <boost/test/unit_test.hpp>
#include <VehicleManager.h>
#include <RentsManager.h>
#include <ClientManager.h>
#include <Rent.h>
#include <memory.h>
#include <Client.h>
#include <Address.h>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
	ClientManager cm;
	cm.create(shared_ptr<Client>(new Client("Artur", "Dziedziczak", "532523511", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")))));
	cm.create(shared_ptr<Client>(new Client("Artur", "Dziedziczak", "111111111", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")))));
	auto klienci = cm.getAll();
	BOOST_CHECK_EQUAL(klienci.size(), 2);
	
	auto client = cm.getClient("111111111");
	BOOST_CHECK_EQUAL(client->getPersonalId(), "111111111");
	
}

