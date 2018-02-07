#include <boost/test/unit_test.hpp>
#include <VehicleManager.h>
#include <RentsManager.h>
#include <Rent.h>
#include <memory.h>
#include <Client.h>
#include <Address.h>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    RentsManager rentsManager;
    VehicleManager vehicleRepo;

    boost::posix_time::ptime returnTimePtime = boost::posix_time::time_from_string("2018-10-17 23:59:59.000");
    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("UTC-01"));
    localDateTimePtr data1 = localDateTimePtr(new boost::local_time::local_date_time(returnTimePtime, zone));
    localDateTimePtr data2 = localDateTimePtr(new boost::local_time::local_date_time(returnTimePtime, zone));
    localDateTimePtr data3 = localDateTimePtr(new boost::local_time::local_date_time(returnTimePtime, zone));

    shared_ptr<Client> client1 = make_shared<Client>("Artur", "Dziedziczak", "5325235", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")));

    shared_ptr<Rent> rent1(new Rent(client1, vehicleRepo.returnVehicleById("OKL 673SP"), std::move(data1)));
    shared_ptr<Rent> rent2(new Rent(client1, vehicleRepo.returnVehicleById("EBR 69P3la"), std::move(data2)));
    shared_ptr<Rent> rent3(new Rent(client1, vehicleRepo.returnVehicleById("OKL 909V"), std::move(data3)));


    rentsManager.createRent(rent1);
    rentsManager.createRent(rent2);
    rentsManager.createRent(rent3);
    
        
    vector<shared_ptr<Rent>> currentRents = rentsManager.getCurrentRents();    
    
	BOOST_CHECK_EQUAL(currentRents.size(), 3); 
    
    
    rentsManager.removeRent(rent1);

    vector<shared_ptr<Rent>> archivedRents = rentsManager.getArchiveRents();
    
    BOOST_CHECK_EQUAL(archivedRents.size(), 1); 

}

