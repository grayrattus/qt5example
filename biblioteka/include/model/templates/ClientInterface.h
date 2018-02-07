#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

template <class T>
class ClientInterface {
    virtual T getAddress() = 0;
    virtual T getRegisteredAddress() = 0;
    virtual T clientinfo() = 0;
    virtual T getFirstName() = 0;
    virtual T getLastName() = 0;
    virtual T getPersonalId() = 0;
    virtual double getDiscount() = 0;
    virtual int getMaxRents() = 0;
    virtual T getAddressStreet() = 0;
    virtual T getAddressNumber() = 0 ;
    virtual T getRegisteredAddressStreet() = 0;
    virtual T getRegisteredAddressNumber() = 0;

};

#endif /* CLIENTINTERFACE_H */
