#include "Car.h"

using namespace std;

Car::Car(const int engineDisplacement, const string id, const unsigned int baseRentPrice, SegmentPtr segment) : MotorVehicle(engineDisplacement, id, baseRentPrice) {
	this->segment = move(segment);
}

int Car::actualRentalPrice() {
	return this->getBaseRentPrice() * this->calcEngineDisplacementModifier() * this->segment->getValue();
}

Car::~Car() {
}


string Car::getTypeLabel() {
    return this->TYPE_LABEL;
};

VehicleType Car::getType() {
	return VehicleType::CAR;
};

string Car::getSegmentLetter() {
	string test;
	test.push_back(this->segment->getLetter());
	return test;
};
