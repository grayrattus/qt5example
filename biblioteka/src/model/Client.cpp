#include "Client.h"
#include <NormalClient.h>
#include <iostream>

class Rent;

using namespace std;

Client::Client(string firstName, string lastName, string personalID, AddressPtr address, AddressPtr registeredAddress) :
firstName{firstName},
lastName{lastName},
address{move(address)},
registeredAddress{move(registeredAddress)},
rent{nullptr},
type{unique_ptr<ClientType>(new NormalClient())}
{
    try {
    if (personalID.length() != 9)
        throw ClientException(ClientException::ERROR_WRONS_PERSONAL_ID);
    else
        this->personalID = personalID;
    } catch (ClientException ce) {
			
    };
}

Client::~Client() {
}

string Client::getAddress() {
    if (this->address != nullptr) {
        return this->address->toString();
    }
    return "";
}

string Client::getRegisteredAddress() {
    if (this->registeredAddress != nullptr) {
        return this->registeredAddress->toString();
    }
    return "";
}

string Client::getFirstName() {
    return this->firstName;
}

string Client::getLastName() {
    return this->lastName;
}

string Client::getPersonalId() {
    return this->personalID;
}

string Client::clientinfo() {
    string concatedAddress;
    if (this->address != nullptr) {
        concatedAddress = this->address->toString();
    }
    if (this->registeredAddress != nullptr) {
        concatedAddress.append(this->address->toString());
    }

    return this->firstName + " " + this->lastName + " " + this->personalID + " " + concatedAddress;
}

void Client::setCurrentRentId(shared_ptr<boost::uuids::uuid> currentRentId) {
    this->currentRentId = move(currentRentId);
}

string Client::printRents() {
    if (this->rent) {
        return this->rent->rentInfo();
    }
    return "Nie wynajmuje niczego";
}

void Client::rentVehicle(Rent* rent) {
    this->rent = rent;
}

double Client::getDiscount() {
    return this->type->getDiscount();
};

int Client::getMaxRents() {
    return this->type->getMaxRents();
};

void Client::changeType(ClientTypePtr type) {
    this->type = move(type);
};
bool Client::operator==(Client& c) const {
    return (this->personalID == c.getPersonalId());
};

string Client::getAddressStreet() {
	return this->address->getStreet();
};

string Client::getAddressNumber() {
	return this->address->getNumber();
};

string Client::getRegisteredAddressStreet() {
	return this->registeredAddress->getStreet();
};

string Client::getRegisteredAddressNumber() {
	return this->registeredAddress->getNumber();
};
