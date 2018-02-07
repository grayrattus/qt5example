#include <boost/test/unit_test.hpp>
#include "Rent.h"
#include "Segment.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bicycle.h"
#include "Mope.h"
#include "CurrentRentsRepository.h"
#include "VehicleRepository.h"
#include "Client.h" 
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(RentContructorTest) {

    shared_ptr<Car> car1(new Car(1000, "EBR 69P3", 5400, SegmentPtr(new Segment('C'))));
    shared_ptr<Mope> mope1(new Mope(1000, "EBR 6923", 5400));
    shared_ptr<Bicycle> bicycle1(new Bicycle("1234", 5400));

    boost::posix_time::ptime returnTimePtime = boost::posix_time::time_from_string("2017-10-17 23:59:59.000");
    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("UTC-01"));
    localDateTimePtr testowaData(new boost::local_time::local_date_time(returnTimePtime, zone));
    localDateTimePtr testowaData2(new boost::local_time::local_date_time(returnTimePtime, zone));

    shared_ptr<Client> klient2(new Client("Artur", "Dziedziczak", "95323430", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4"))));
    shared_ptr<Client> klient1(new Client("Monika", "Nawój", "95323430", AddressPtr(new Address("Moniuszki", "4")), AddressPtr(new Address("Moniuszki", "4"))));

    Rent* rent1 = new Rent(klient1, car1, std::move(testowaData));
    Rent* rent2 = new Rent(klient2, mope1, std::move(testowaData2));
    
    BOOST_CHECK_EQUAL(rent1 == rent1, true);
    BOOST_CHECK_EQUAL(rent1 == rent2, false);

}
