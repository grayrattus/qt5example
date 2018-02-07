#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include "VehicleRepository.h"
#include <string>
#include <Client.h>


class VehicleManager: public VehicleRepository {
public:
    VehicleManager();
    VehicleManager(const VehicleManager& orig);
    virtual ~VehicleManager();
    const vector<shared_ptr<Vehicle>> getVehicles();
    const shared_ptr<Vehicle> getVehicle(string id);
    shared_ptr<Vehicle> returnVehicleById(string id);
    string vehicleRaport();
    const vector<shared_ptr<Vehicle>> getVehiclesByType(VehicleType type);
};


#endif /* VEHICLEMANAGER_H */

