#ifndef MOPE_H
#define MOPE_H

#include "MotorVehicle.h"

class Mope: public MotorVehicle {
public:
    Mope(const int engineDisplacement, const string id, const unsigned int baseRentPrice);
    virtual ~Mope();
    string getTypeLabel();
    virtual VehicleType getType() override;
private:
    const string TYPE_LABEL = "motor";
};

#endif /* MOPE_H */

