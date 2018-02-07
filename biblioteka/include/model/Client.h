#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Address.h"
#include "Rent.h"
#include "ClientType.h"
#include "ClientInterface.h"
#include "templates/ClientInterface.h"
#include <memory>
#include <exceptions/ClientException.h>
#include <ClientInterface.h>

using namespace std;

class Client: public ClientInterface<string> {
public:
    virtual ~Client();
    Client(string firstName, string lastName, string personalID, AddressPtr addres, AddressPtr registeredAddress);

    static const unsigned int PESEL_LENGHT = 9;

    void rentVehicle(Rent* rent);
    void setCurrentRentId(shared_ptr<boost::uuids::uuid> currentRentId);
    string printRents();

    string getAddress();
    string getRegisteredAddress();
    string getAddressStreet();
    string getAddressNumber();
    string getRegisteredAddressStreet();
    string getRegisteredAddressNumber();

    string clientinfo();
    string getFirstName();
    string getLastName();
    string getPersonalId();
    bool operator==(Client& c) const;

    double getDiscount();
    int getMaxRents();
    void changeType(ClientTypePtr type);
private:
    ClientTypePtr type;
    Rent* rent;
    string firstName;
    shared_ptr<boost::uuids::uuid> currentRentId;
    string lastName;
    string personalID;
    AddressPtr registeredAddress;
    AddressPtr address;
};

#endif 
