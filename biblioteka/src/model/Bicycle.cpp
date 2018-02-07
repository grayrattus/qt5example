#include "Bicycle.h"

Bicycle::Bicycle(const string id, const unsigned int baseRentPrice) : Vehicle(id, baseRentPrice) {
}

int Bicycle::actualRentalPrice() {
	return this->getBaseRentPrice();
}


Bicycle::~Bicycle() {
}


string Bicycle::getTypeLabel() {
    return this->TYPE_LABEL;
}
VehicleType Bicycle::getType() {
	return VehicleType::BICYCLE;
};
