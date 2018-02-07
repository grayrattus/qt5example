/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Clients.cpp
 * Author: grayrattus
 *
 * Created on December 28, 2017, 12:48 PM
 */

#include "Clients.h"
#include "model/Client.h"
#include <modules/mainWindow/mainWindow.h>
#include <QTableWidget>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QPushButton>
#include <modules/ClientEditForm/ClientEditForm.h>

Clients::Clients() {
    widget.setupUi(this);
    this->widget.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->fillTable();
}

void Clients::fillTable() {
    mainWindow* instance = mainWindow::GetInstance();
    auto clients = instance->getClients();

    unsigned int row = 0;
    for (auto client : clients) {
	QPushButton* editButton = new QPushButton();
	editButton->setText(QString("Edytuj"));
	QPushButton* deleteButton = new QPushButton();
	deleteButton->setText(QString("Usuń"));

	
        QTableWidgetItem *firstName = new QTableWidgetItem(QString::fromStdString(client->getFirstName()));
        QTableWidgetItem *lastName = new QTableWidgetItem(QString::fromStdString(client->getLastName()));
        QTableWidgetItem *personalID = new QTableWidgetItem(QString::fromStdString(client->getPersonalId()));
        QTableWidgetItem *address = new QTableWidgetItem(QString::fromStdString(client->getAddress()));
        QTableWidgetItem *registeredAddress = new QTableWidgetItem(QString::fromStdString(client->getRegisteredAddress()));
        this->widget.tableWidget->insertRow(row);
        this->widget.tableWidget->setItem(row, this->tableLabels::FIRST_NAME, firstName);
        this->widget.tableWidget->setItem(row, this->tableLabels::LAST_NAME, lastName);
        this->widget.tableWidget->setItem(row, this->tableLabels::PERSONAL_ID, personalID);
        this->widget.tableWidget->setItem(row, this->tableLabels::ADDRESS, address);
        this->widget.tableWidget->setItem(row, this->tableLabels::REGISTERED_ADDRESS, registeredAddress);
        this->widget.tableWidget->setCellWidget(row, this->tableLabels::EDIT, editButton);
        this->widget.tableWidget->setCellWidget(row, this->tableLabels::DELETE, deleteButton);

	connect(editButton, &QPushButton::released, [=] {
	    unique_ptr<ClientEditForm> cef(new ClientEditForm(client));
	    cef->exec();
	    cef->show();
	    this->widget.tableWidget->setRowCount(0);
	    this->fillTable();
	});
	connect(deleteButton, &QPushButton::released, [=] {
	    instance->removeClient(client);
	    this->widget.tableWidget->setRowCount(0);
	    this->fillTable();
	});
	row++;
    }
} 

Clients::~Clients() {
}
