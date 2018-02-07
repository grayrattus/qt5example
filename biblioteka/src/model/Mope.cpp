#include "Mope.h"

Mope::Mope(const int engineDisplacement, const string id, const unsigned int baseRentPrice) : MotorVehicle(engineDisplacement, id, baseRentPrice) {
}

Mope::~Mope() {
}

string Mope::getTypeLabel() {
    return this->TYPE_LABEL;
}
VehicleType Mope::getType() {
	return VehicleType::MOPE;
};
