#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <memory>

using namespace std;

class Address {
private:
    string street;
    string number;

public:
    string getStreet();
    string getNumber();
    void setStreet(string newStreet);
    void setNumber(string newNumber);
    string toString();
    Address();
    Address(string street, string number);
    ~Address();
};
typedef unique_ptr<Address> AddressPtr;
#endif /* ADDRESS_H */

