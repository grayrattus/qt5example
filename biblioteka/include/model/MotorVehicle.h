#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle {
public:
    MotorVehicle(const int engineDisplacement, const string id, const unsigned int baseRentPrice); 
    float calcEngineDisplacementModifier();
    virtual ~MotorVehicle();
    int actualRentalPrice();
    virtual string getTypeLabel() = 0;
    int getEngineDisplacement();

private:
    int engineDisplacement;
};

#endif /* MOTORVEHICLE_H */

