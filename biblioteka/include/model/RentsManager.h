#ifndef RENTSMANAGER_H
#define RENTSMANAGER_H

#include <vector>
#include "Rent.h"
#include "Vehicle.h"
#include "RentsRepository.h"
#include "ClientRepository.h"

using namespace std;

class RentsManager {
public:
    void createRent(shared_ptr<Rent> rent);
    void removeRent(shared_ptr<Rent> rent);
    void changeClientType(shared_ptr<Client> client);
    string getClientForRentedVehicle(shared_ptr<Vehicle> vehicle);
    vector<shared_ptr<Rent>> getAllClientRents(shared_ptr<Client> client); 
    string rentReport();
    RentsManager();
    RentsManager(const RentsManager& orig);
    vector<shared_ptr<Rent>> getClientRents(shared_ptr<Client> client);
    double checkClientRentBallance(shared_ptr<Client> client);
    virtual ~RentsManager();

    const vector<shared_ptr<Rent>> getCurrentRents();
    const vector<shared_ptr<Rent>> getArchiveRents();
private:
    RentsRepository currentRents;
    RentsRepository archiveRents;
};

#endif /* RENTSMANAGER_H */

