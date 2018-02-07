/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientQtAdapter.cpp
 * Author: grayrattus
 * 
 * Created on January 9, 2018, 9:06 PM
 */

#include "ClientQtAdapter.h"

ClientQtAdapter::ClientQtAdapter(const shared_ptr<Client> client): client{client} {
}

ClientQtAdapter::ClientQtAdapter(const ClientQtAdapter& orig) {
}

ClientQtAdapter::~ClientQtAdapter() {
}

QString ClientQtAdapter::getAddress() {
	return QString::fromStdString(this->client->getAddress());
};
QString ClientQtAdapter::getRegisteredAddress() {
	return QString::fromStdString(this->client->getRegisteredAddress());
};
QString ClientQtAdapter::clientinfo() {
	return QString::fromStdString(this->client->clientinfo());
};
QString ClientQtAdapter::getFirstName() {
	return QString::fromStdString(this->client->getFirstName());
};
QString ClientQtAdapter::getLastName() {
	return QString::fromStdString(this->client->getLastName());
};
QString ClientQtAdapter::getPersonalId() {
	return QString::fromStdString(this->client->getPersonalId());
};
double ClientQtAdapter::getDiscount() {
	return this->client->getDiscount();
}
int ClientQtAdapter::getMaxRents() {
	return this->client->getMaxRents();
}

QString ClientQtAdapter::getAddressStreet() {
	return QString::fromStdString(this->client->getAddressStreet());
};
QString ClientQtAdapter::getAddressNumber() {
		return QString::fromStdString(this->client->getAddressNumber());
};
QString ClientQtAdapter::getRegisteredAddressStreet() {
	return QString::fromStdString(this->client->getRegisteredAddressStreet());
};
QString ClientQtAdapter::getRegisteredAddressNumber() {
		return QString::fromStdString(this->client->getRegisteredAddressNumber());
};


