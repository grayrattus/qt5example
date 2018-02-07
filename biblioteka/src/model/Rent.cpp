#include <string>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/local_time/local_time_io.hpp>
#include <boost/date_time/local_timezone_defs.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"

using namespace std;

Rent::Rent(shared_ptr<Client> client, shared_ptr<Vehicle> vehicle, localDateTimePtr returnTime) :
client{client},
vehicle{vehicle},
returnTime{move(returnTime)},
rentalTime{move(unique_ptr<boost::local_time::local_date_time>(new boost::local_time::local_date_time(boost::posix_time::second_clock::local_time(), boost::local_time::time_zone_ptr(new boost::local_time::posix_time_zone("UTC-01")))))},
rentPrice{this->getRentPrice()}
{
    try {
        if (this->vehicle->isRented())
	    throw "Pojazd jest już wypożyczony";
        else
            this->vehicle->rent(true);
        this->client->rentVehicle(this);
        boost::uuids::random_generator gen;
        this->id = gen();

    } catch (string error) {
    }
};

Rent::Rent(const Rent & orig) {
};

Rent::~Rent() {
    this->vehicle->rent(false);
};

string Rent::getVehicleInfo() {
    return this->vehicle->getId();
}

string Rent::getVehicleId() {
    return this->vehicle->getId();
}


string Rent::getClientInfo() {
    return this->client->getFirstName() + " " + this->client->getLastName();
}

int Rent::getRentPrice() {
    return this->vehicle->getBaseRentPrice() * this->rentDuration();
}

int Rent::rentDuration() {
    boost::local_time::local_time_period rentTimePeriod(*this->rentalTime, *this->returnTime);

    int rentDuration = rentTimePeriod.length().hours() / 24;
    if (rentDuration < 0) {
        return 0;
    }
    if (rentTimePeriod.length().seconds() % 86400 != 0) {
        rentDuration++;
    }
    return rentDuration;
}

int Rent::currentCost() {
    return this->rentDuration() * this->vehicle->getBaseRentPrice();
}

string Rent::rentInfo() {
    return boost::uuids::to_string(this->id) + " " + this->rentalTime->to_string() + " " +
            to_string(this->rentDuration()) + this->client->clientinfo() + this->vehicle->vehicleInfo();
};

void Rent::returnVehicle(localDateTimePtr returnDate) {
    this->returnTime = move(returnDate);
    this->client->rentVehicle(nullptr);
    this->vehicle->rent(false);
};

boost::uuids::uuid Rent::getId() {
    return this->id;
};

string Rent::getClientId() {
    return this->client->getPersonalId();
}
bool Rent::operator==(Rent& r) const {
    return (this->id == r.getId());
};

string Rent::getReturnDate() {
	return to_simple_string(this->returnTime->utc_time());
}

localDateTimePtr Rent::convertStrToRentTime(string date) {
    boost::posix_time::ptime returnTimePtime = boost::posix_time::time_from_string(date);
    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("UTC-01"));
    localDateTimePtr tmpDate(new boost::local_time::local_date_time(returnTimePtime, zone));
    return tmpDate;
}
