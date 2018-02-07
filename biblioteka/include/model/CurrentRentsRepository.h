#ifndef CURRENTRENTSREPOSITORY_H
#define CURRENTRENTSREPOSITORY_H

#include <Vehicle.h>
#include <vector>

#include "Rent.h"

using namespace std;

class CurrentRentsRepository {
public:
    void createRent(shared_ptr<Rent> rent);
    void removeRent(shared_ptr<Rent> rent);
    string getClientForRentedVehicle(shared_ptr<Vehicle> vehicle);
    string rentReport();
    CurrentRentsRepository();
    CurrentRentsRepository(const CurrentRentsRepository& orig);
    virtual ~CurrentRentsRepository();
private:
    vector<shared_ptr<Rent> > rents;
};

#endif /* CURRENTRENTSREPOSITORY_H */

