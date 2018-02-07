#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

enum class VehicleType {
	CAR, MOPE, BICYCLE
};


class Vehicle {
public:
    Vehicle(const string id, const unsigned int baseRentPrice);
    Vehicle(const Vehicle& orig);
    virtual ~Vehicle();
    unsigned int getBaseRentPrice();
    void setBaseRentPrice(unsigned int baseRentPrice);
    string vehicleInfo();
    string getId();
    virtual VehicleType getType() = 0;
    bool rent(bool rentFlag); 
    bool isRented(); 
    bool operator==(Vehicle& v) const;
    virtual string getTypeLabel() = 0;

private:
    string id;
    bool rented;
    unsigned int baseRentPrice;
};

#endif /* VEHICLE_H */

