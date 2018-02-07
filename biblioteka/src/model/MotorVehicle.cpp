#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(const int engineDisplacement, const string id, const unsigned int baseRentPrice) : Vehicle(id, baseRentPrice), engineDisplacement{engineDisplacement} {
}
float MotorVehicle::calcEngineDisplacementModifier() {
	if (this->engineDisplacement < 1000) {
		return 1.0;
	} else 	if (this->engineDisplacement >= 1000 && this->engineDisplacement < 2000) {
		return (1.0 * this->engineDisplacement)/ 1000;
	} else {
		return 1.5;
	}
};
int MotorVehicle::actualRentalPrice() {
	return this->getBaseRentPrice() * this->calcEngineDisplacementModifier();
}

int MotorVehicle::getEngineDisplacement() {
	return this->engineDisplacement;
};

MotorVehicle::~MotorVehicle() {
}

