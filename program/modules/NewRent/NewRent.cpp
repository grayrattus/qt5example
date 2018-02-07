/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NewRent.cpp
 * Author: grayrattus
 *
 * Created on December 30, 2017, 12:47 AM
 */

#include "NewRent.h"
#include <modules/mainWindow/mainWindow.h>
#include "Rent.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <QDate>

using namespace std;

NewRent::NewRent() {
    widget.setupUi(this);
    mainWindow* instance = mainWindow::GetInstance();
    
    this->widget.dateTimeEdit->setDate(QDate::currentDate());
    this->widget.dateTimeEdit->setMinimumDate(QDate::currentDate());

    const vector<shared_ptr < Client>> clients = instance->getClients();
    const vector<shared_ptr < Vehicle>> availableVehicles = instance->getAvailableVehicles();

    for (auto client : clients) {
        this->widget.clients->addItem(QString::fromStdString(client->getPersonalId()));
    }
    for (auto vehicle : availableVehicles) {
        this->widget.availableVehicles->addItem(QString::fromStdString(vehicle->getId()));
    }

}

NewRent::~NewRent() {
}

void NewRent::accept() {
    string clientId = this->widget.clients->currentText().toStdString();
    string vehicleId = this->widget.availableVehicles->currentText().toStdString();
    string date = this->widget.dateTimeEdit->dateTime().toString("yyyy-M-d h:m:s.z").toStdString();

    mainWindow* instance = mainWindow::GetInstance();
    auto vehicle = instance->getVehicleById(vehicleId);
    auto client = instance->getClientById(clientId);

    QString tmpErrorMsg = "";

    if (vehicle == NULL) {
        tmpErrorMsg.append("Nie ma takiego samochodu (");
        tmpErrorMsg.append(QString::fromStdString(vehicleId));
        tmpErrorMsg.append("). Skontaktuj się z administracją aplikacji.\n");
    }
    if (client == NULL) {
        tmpErrorMsg.append("Nie ma takiego klienta (");
        tmpErrorMsg.append(QString::fromStdString(clientId));
        tmpErrorMsg.append(")Skontaktuj się z administracją aplikacji.\n");
    }
    if (!tmpErrorMsg.isEmpty()) {
        QMessageBox::information(this, APPLICATION_NAME, tmpErrorMsg);
    } else {
        localDateTimePtr tmpDate = Rent::convertStrToRentTime(date);

        shared_ptr<Rent> tmpRent(new Rent(client, vehicle, std::move(tmpDate)));
        instance->createRent(tmpRent);
		instance->refreshCurrentRepositoryTable();

        this->close();
    }

};
