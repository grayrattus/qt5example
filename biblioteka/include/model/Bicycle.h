#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"


class Bicycle:public Vehicle {
public:
    Bicycle(const string id, const unsigned int baseRentPrice);
    int actualRentalPrice();
    string getTypeLabel();
    virtual ~Bicycle();
    virtual VehicleType getType() override;
private:
    const string TYPE_LABEL = "rower";

};

#endif /* BICYCLE_H */

