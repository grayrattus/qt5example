/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientQtAdapter.h
 * Author: grayrattus
 *
 * Created on January 9, 2018, 9:06 PM
 */

#ifndef CLIENTQTADAPTER_H
#define CLIENTQTADAPTER_H

#include <Client.h>
#include <Address.h>
#include <ClientInterface.h>
#include <QString>
#include <memory>

class ClientQtAdapter: public ClientInterface<QString>{
    public:
    ClientQtAdapter(const shared_ptr<Client> client); 
    ClientQtAdapter(const ClientQtAdapter& orig); 
    ~ClientQtAdapter(); 

    QString getAddress();
    QString getRegisteredAddress();
    QString clientinfo();
    QString getFirstName();
    QString getLastName();
    QString getPersonalId();
    double getDiscount();
    int getMaxRents();
    QString getAddressStreet();
    QString getAddressNumber();
    QString getRegisteredAddressStreet();
    QString getRegisteredAddressNumber();


    private:
	shared_ptr<Client> client;
};

#endif /* CLIENTQTADAPTER_H */

