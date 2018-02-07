#include "RentsManager.h"
#include "model/client_types/FrequentClient.h"

using namespace std;

RentsManager::RentsManager() {
}

RentsManager::RentsManager(const RentsManager& orig) {
}

RentsManager::~RentsManager() {
}

void RentsManager::createRent(shared_ptr<Rent> rent) {
    try {
        if (this->currentRents.checkRented(rent)) {
            throw "To wypożyczenie już istnieje";
        }
        this->currentRents.create(rent);
    } catch (string error) {
    }
}

void RentsManager::removeRent(shared_ptr<Rent> rent) {
    this->currentRents.remove(rent);
    this->archiveRents.create(rent);
}

vector<shared_ptr<Rent>> RentsManager::getAllClientRents(shared_ptr<Client> client) {
    return this->archiveRents.getClientRents(client);
};

double RentsManager::checkClientRentBallance(shared_ptr<Client> client) {
    double totalPrice = 0;
    for (auto rent : this->archiveRents.getClientRents(client)) {
        totalPrice += rent->getRentPrice();
    }
    for (auto rent : this->currentRents.getClientRents(client)) {
        totalPrice += rent->getRentPrice();
    }
    return totalPrice;
};

void RentsManager::changeClientType(shared_ptr<Client> client) {
    // Sprawdza jezeli suma wypozyczeń jest > 1000 i ilość wszystkich wypożyczeń > 4 
    // to ustawia typ klienta na FrequentClient
    if (this->checkClientRentBallance(client) > 1000 && this->getAllClientRents(client).size() > 4) {
        client->changeType(ClientTypePtr(new FrequentClient()));
    }
};

const vector<shared_ptr<Rent>> RentsManager::getCurrentRents() {
    return this->currentRents.getAll();
};

const vector<shared_ptr<Rent>> RentsManager::getArchiveRents() {
    return this->archiveRents.getAll();
};
