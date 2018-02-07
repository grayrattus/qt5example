#ifndef CLIENTTYPE_H
#define CLIENTTYPE_H

#include <memory>

using namespace std;

class ClientType {
public:
    double getDiscount();
    int getMaxRents();
    ClientType(double discount, int maxRents);
    virtual ~ClientType();
private:
    double discount;
    int maxRents;
};

#endif 
typedef unique_ptr<ClientType> ClientTypePtr;
