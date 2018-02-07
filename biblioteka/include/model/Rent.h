#ifndef RENT_H
#define RENT_H

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;

typedef unique_ptr<boost::local_time::local_date_time> localDateTimePtr;

class Vehicle;
class Client;

class Rent {
public:
    Rent(shared_ptr<Client> client, shared_ptr<Vehicle> vehicle, localDateTimePtr returnTime);

    Rent(const Rent& orig);

    virtual ~Rent();

    static localDateTimePtr convertStrToRentTime(string date);

    string rentInfo();
    int rentDuration();
    int currentCost();
    string getVehicleInfo();
    string getClientInfo();
    string getClientId();
    int getRentPrice();
    string getReturnDate();
    boost::uuids::uuid getId();
    void returnVehicle(localDateTimePtr returnDate);
    string getVehicleId();
    bool operator==(Rent& r) const;

private:
    shared_ptr<Client> client;
    shared_ptr<Vehicle> vehicle;
    string local_date_time;
    boost::uuids::uuid id;
    localDateTimePtr returnTime;
    localDateTimePtr rentalTime;
    int rentPrice;
};


#endif /* RENT_H */

