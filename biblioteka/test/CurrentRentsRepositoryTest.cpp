#include <boost/test/unit_test.hpp>
#include <VehicleRepository.h>
#include <CurrentRentsRepository.h>
#include <Rent.h>
#include <Client.h>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
//    CurrentRentsRepository currentRepository;
//    VehicleRepository vehicleRepo;
//
//    boost::posix_time::ptime returnTimePtime = boost::posix_time::time_from_string("2017-10-17 23:59:59.000");
//    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("UTC-01"));
//    localDateTimePtr data1 = localDateTimePtr(new boost::local_time::local_date_time(returnTimePtime, zone));
//    localDateTimePtr data2 = localDateTimePtr(new boost::local_time::local_date_time(returnTimePtime, zone));
//
//    shared_ptr<Rent> rent1(new Rent(new Client("Artur", "Dziedziczak", "5325235", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4")), ClientType(ClientTypeSet::TYPE_2)), vehicleRepo.returnVehicleById("EBR 69P3la"), std::move(data1)));
//    shared_ptr<Rent> rent2(new Rent(new Client("Karol", "Mababa", "809", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4"))), vehicleRepo.returnVehicleById("OKL 673SP"), std::move(data2)));
//    currentRepository.createRent(rent1);
//
//    BOOST_CHECK_EQUAL(currentRepository.getClientForRentedVehicle(vehicleRepo.returnVehicleById("EBR 69P3la")), "Artur Dziedziczak");
//    currentRepository.removeRent(rent1);
//    BOOST_CHECK_EQUAL(currentRepository.getClientForRentedVehicle(vehicleRepo.returnVehicleById("EBR 69P3la")), "Nie ma takiego samochodu w bazie");
//
//    currentRepository.createRent(rent1);
//    currentRepository.createRent(rent2);
//
    //BOOST_CHECK_EQUAL(currentRepository.rentReport(), "");

    //BOOST_CHECK_EQUAL(vehicleRepo.vehicleRaport(), "");

}
