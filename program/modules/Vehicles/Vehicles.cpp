/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Vehicles.cpp
 * Author: grayrattus
 *
 * Created on December 30, 2017, 1:50 AM
 */

#include "Vehicles.h"
#include <modules/mainWindow/mainWindow.h>
#include <QPushButton>

Vehicles::Vehicles() {
    widget.setupUi(this);
    this->fillTable();

}
void Vehicles::fillTable() {
    mainWindow* instance = mainWindow::GetInstance();
    auto vehicles = instance->getVehicles();

    unsigned int row = 0;
    for (auto vehicle : vehicles) {
	QPushButton* editButton = new QPushButton();
	editButton->setText(QString("Edytuj"));
	QPushButton* deleteButton = new QPushButton();
	deleteButton->setText(QString("Usuń"));

	
        QTableWidgetItem *id = new QTableWidgetItem(QString::fromStdString(vehicle->getId()));
        QTableWidgetItem *baseRentPrice = new QTableWidgetItem(QString::number(vehicle->getBaseRentPrice()));
        this->widget.tableWidget->insertRow(row);
        this->widget.tableWidget->setItem(row, this->tableLabels::ID, id);
        this->widget.tableWidget->setItem(row, this->tableLabels::BASE_RENT_PRICE, baseRentPrice);
        this->widget.tableWidget->setItem(row, this->tableLabels::TYPE, new QTableWidgetItem(QString::fromStdString(vehicle->getTypeLabel())));
        this->widget.tableWidget->setCellWidget(row, this->tableLabels::DELETE, deleteButton);

	connect(deleteButton, &QPushButton::released, [=] {
	    instance->removeVehicle(vehicle);
	    this->widget.tableWidget->setRowCount(0);
	    this->fillTable();
	});
	row++;

    }

}

Vehicles::~Vehicles() {
}
