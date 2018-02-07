#include <boost/test/unit_test.hpp>
#include <VehicleManager.h>
#include <RentsManager.h>
#include <Rent.h>
#include <memory.h>
#include <Client.h>
#include <Address.h>
#include <VehicleManager.h>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
	VehicleManager vm;
	BOOST_CHECK_EQUAL(vm.getVehicles().size(), 10); 
	auto pojazd = vm.returnVehicleById("OKL 673SP");
	BOOST_CHECK_EQUAL(pojazd->getId(), "OKL 673SP"); 
	auto samochody = vm.getVehiclesByType(VehicleType::CAR);	
	BOOST_CHECK_EQUAL(samochody.size(), 4);
}

