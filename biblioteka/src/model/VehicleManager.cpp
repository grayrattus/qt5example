#include "VehicleManager.h"
#include "Car.h"
#include "Mope.h"
#include "Bicycle.h"

VehicleManager::VehicleManager() {
}

VehicleManager::VehicleManager(const VehicleManager& orig) {
}

VehicleManager::~VehicleManager() {
}

shared_ptr<Vehicle> VehicleManager::returnVehicleById(string id) {
    for (auto &vehicle : this->items)
        if (vehicle->getId() == id)
            return vehicle;
    return nullptr;
};

string VehicleManager::vehicleRaport() {
    string tempRaport = "";

    for (auto vehicle : this->items)
        tempRaport.append(vehicle->vehicleInfo() + "\n");
    return tempRaport;
}

const vector<shared_ptr<Vehicle>> VehicleManager::getVehicles() {
    return this->items;
};
const shared_ptr<Vehicle> VehicleManager::getVehicle(string id) {
    for (auto vehicle:this->items) {
	if (vehicle->getId() == id) {
	    return vehicle;
	}
    }
    return NULL;
};


const vector<shared_ptr<Vehicle>> VehicleManager::getVehiclesByType(VehicleType type) {
	vector<shared_ptr<Vehicle>> tmpVehicles;
	
    for (auto vehicle : this->items) {
		if (vehicle->getType() == type) {
			tmpVehicles.push_back(vehicle);
		}
	}
	
	return tmpVehicles;
};
