#ifndef RENTSREPOSITORY_H
#define RENTSREPOSITORY_H

#include <Vehicle.h>
#include <vector>

#include "Rent.h"
#include "templates/VectorRepository.h"

using namespace std;

class RentsRepository:public VectorRepository<shared_ptr<Rent>> {
public:
    string getClientForRentedVehicle(shared_ptr<Vehicle> vehicle);
    string rentReport();
    bool checkRented(shared_ptr<Rent> rent);
    vector<shared_ptr<Rent>> getClientRents(shared_ptr<Client> client);
    RentsRepository();
    RentsRepository(const RentsRepository& orig);
    virtual ~RentsRepository();
};

#endif /* RENTSREPOSITORY_H */