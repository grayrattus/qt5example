#ifndef CAR_H
#define CAR_H

#include <memory>

#include "MotorVehicle.h"
#include "Segment.h"

class Car : public MotorVehicle {
public:
    Car(const int engineDisplacement, const string id, const unsigned int baseRentPrice, unique_ptr<Segment> segment);
    virtual ~Car();
    string getTypeLabel();
    int actualRentalPrice() ;
    string getSegmentLetter();
    virtual VehicleType getType() override;

private:
	unique_ptr<Segment> segment;
	const string TYPE_LABEL = "samochód";
};

#endif /* CAR_H */
