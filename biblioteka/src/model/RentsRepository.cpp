#include "RentsRepository.h"
#include "model/Client.h"

using namespace std;

RentsRepository::RentsRepository() {
}

RentsRepository::RentsRepository(const RentsRepository& orig) {
}

RentsRepository::~RentsRepository() {
}

string RentsRepository::rentReport() {
    string tempRentReport = "";

    for (auto rent : this->items) {
        tempRentReport.append(rent->rentInfo() + "\n");
    }

    return tempRentReport;

};

string RentsRepository::getClientForRentedVehicle(shared_ptr<Vehicle> vehicle) {
    for (auto tempRents : this->items) {
        if (tempRents->getVehicleId() == vehicle->getId())
            return tempRents->getClientInfo();
    }
    return "Nie ma takiego samochodu w bazie";
};

bool RentsRepository::checkRented(shared_ptr<Rent> rent) {
    for (auto tempRent : this->items) {
        if (tempRent->getId() == rent->getId()) {
            return true;
        }
    }
    return false;
};

vector<shared_ptr<Rent>> RentsRepository::getClientRents(shared_ptr<Client> client) {
    vector <shared_ptr < Rent>> clientRents;
    for (auto rent : this->items) {
        if (rent->getClientId() == client->getPersonalId()) {
            clientRents.push_back(rent);
        }
    }
    return clientRents;
}; 
