#include "Vehicle.h"
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;

Vehicle::Vehicle(const string id, const unsigned int baseRentPrice) : id{id}, baseRentPrice{baseRentPrice}, rented{false}
{
}

Vehicle::Vehicle(const Vehicle & orig) {
}

Vehicle::~Vehicle() {
}

unsigned int Vehicle::getBaseRentPrice() {
    return this->baseRentPrice;
}

string Vehicle::getId() {
    return this->id;
}

void Vehicle::setBaseRentPrice(unsigned int baseRentPrice) {
    this->baseRentPrice = baseRentPrice;
};

string Vehicle::vehicleInfo() {
    string temp = this->id + " " + to_string(this->baseRentPrice) + " ";
    if (this->rented) {
        return temp.append("Wynajęty");
    }
    return temp.append("Nie wynajęty");
}

bool Vehicle::rent(bool rentFlag) {
    this->rented = rentFlag;
}

bool Vehicle::isRented() {
    return this->rented;
}

bool Vehicle::operator==(Vehicle& v) const {
    return (this->id == v.getId());
};