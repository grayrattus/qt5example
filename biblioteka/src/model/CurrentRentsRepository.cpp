#include "CurrentRentsRepository.h"

using namespace std;

CurrentRentsRepository::CurrentRentsRepository() {
}

CurrentRentsRepository::CurrentRentsRepository(const CurrentRentsRepository& orig) {
}

CurrentRentsRepository::~CurrentRentsRepository() {
}

void CurrentRentsRepository::createRent(shared_ptr<Rent> rent) {
    // Zabezpieczenie aby nie mozna bylo doda 2 razy tego samego wypozyczenia
    bool pushFlag = true;
    for (auto tempRent : this->rents) {
        if (tempRent->getId() == rent->getId())
            pushFlag = false;
        break;
    }
    if (pushFlag == true)
        this->rents.push_back(rent);
}

void CurrentRentsRepository::removeRent(shared_ptr<Rent> rent) {
    for (vector<shared_ptr<Rent>>::iterator it = this->rents.begin(); it != this->rents.end();) {
        if ((*it)->getId() == rent->getId()) {
            it = this->rents.erase(it);
        } else {
            ++it;
        }
    }
}

string CurrentRentsRepository::rentReport() {
    string tempRentReport = "";

    for (auto rent : this->rents) {
        tempRentReport.append(rent->rentInfo() + "\n");
    }

    return tempRentReport;

};

string CurrentRentsRepository::getClientForRentedVehicle(shared_ptr<Vehicle> vehicle) {
    for (auto tempRents : this->rents) {
        if (tempRents->getVehicleId() == vehicle->getId())
            return tempRents->getClientInfo();
    }
    return "Nie ma takiego samochodu w bazie";
};
