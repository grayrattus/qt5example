#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include <vector>
#include <memory>
#include <string>

#include "Vehicle.h"
#include "templates/VectorRepository.h"

using namespace std;

class VehicleRepository:public VectorRepository<shared_ptr<Vehicle>> {
public:
    VehicleRepository();
    VehicleRepository(const VehicleRepository& orig);
    virtual ~VehicleRepository();
};

#endif /* VEHICLEREPOSITORY_H */

