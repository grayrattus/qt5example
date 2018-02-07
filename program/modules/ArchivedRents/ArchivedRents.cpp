/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArchivedRents.cpp
 * Author: grayrattus
 *
 * Created on December 30, 2017, 5:33 PM
 */

#include "ArchivedRents.h"
#include <modules/mainWindow/mainWindow.h>
#include <QTableWidget>
#include <boost/uuid/uuid_io.hpp>

ArchivedRents::ArchivedRents() {
    widget.setupUi(this);
    this->fillTable();
}

void ArchivedRents::fillTable() {
    mainWindow* instance = mainWindow::GetInstance();

    auto archivedRents = instance->getArchivedRents();
    this->widget.tableWidget->setRowCount(0);

    unsigned int row = 0;

    for(auto archivedRent:archivedRents) {
        QTableWidgetItem *rentId = new QTableWidgetItem(QString::fromStdString(boost::uuids::to_string(archivedRent->getId())));
        QTableWidgetItem *clientId = new QTableWidgetItem(QString::fromStdString(archivedRent->getClientId()));
        QTableWidgetItem *rentPrice = new QTableWidgetItem(QString::number(archivedRent->getRentPrice()));
        QTableWidgetItem *vehicleInfo = new QTableWidgetItem(QString::fromStdString(archivedRent->getVehicleInfo()));
        this->widget.tableWidget->insertRow(row);
        this->widget.tableWidget->setItem(row, this->tableLabels::RENT_ID, rentId);
        this->widget.tableWidget->setItem(row, this->tableLabels::CLIENT_ID, clientId);
        this->widget.tableWidget->setItem(row, this->tableLabels::RENT_PRICE, rentPrice);
        this->widget.tableWidget->setItem(row, this->tableLabels::VEHICLE_INFO, vehicleInfo);

	row++;
    }

};

ArchivedRents::~ArchivedRents() {
}
