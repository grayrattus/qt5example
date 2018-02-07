/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ClientEditForm.cpp
 * Author: grayrattus
 *
 * Created on December 29, 2017, 10:56 PM
 */

#include "ClientEditForm.h"
#include "model/Client.h"
#include <QMessageBox>
#include <modules/mainWindow/mainWindow.h>

ClientEditForm::ClientEditForm(shared_ptr<Client> client) {
    widget.setupUi(this);
    mainWindow* instance = mainWindow::GetInstance();
    QObject::connect(this, SIGNAL(editClient(std::shared_ptr<Client>)), instance, SLOT(sEditClient(std::shared_ptr<Client>)));
    this->widget.personalID->setText(QString::fromStdString(client->getPersonalId()));
    this->widget.firstName->setText(QString::fromStdString(client->getFirstName()));
    this->widget.lastName->setText(QString::fromStdString(client->getLastName()));
    this->widget.personalID->setText(QString::fromStdString(client->getPersonalId()));
    this->widget.addresStreet->setText(QString::fromStdString(client->getAddress()));
    this->widget.addresNr->setText(QString::fromStdString(client->getAddress()));
    this->widget.registeredAddressStreet->setText(QString::fromStdString(client->getRegisteredAddress()));
    this->widget.registeredAddressNr->setText(QString::fromStdString(client->getRegisteredAddress()));
}

ClientEditForm::~ClientEditForm() {
}

void ClientEditForm::accept() {
    QString firstName = this->widget.firstName->text();
    QString lastName = this->widget.lastName->text();
    QString personalID = this->widget.personalID->text();

    QString addresStreet = this->widget.addresStreet->text();
    QString addresNr = this->widget.addresNr->text();

    QString registeredAddressStreet = this->widget.registeredAddressStreet->text();
    QString registeredAddressNr = this->widget.registeredAddressNr->text();

    QString tmpErrorMsg = "";

    if (firstName.isEmpty())
        tmpErrorMsg.append("Nie podałeś pierwszego imienia\n");
    if (lastName.isEmpty())
        tmpErrorMsg.append("Nie podałeś nazwiska\n");
    if (personalID.isEmpty())
        tmpErrorMsg.append("Nie podałeś nr. pesel\n");
    if (personalID.length() != Client::PESEL_LENGHT)
        tmpErrorMsg.append("Pesel musi zawierać 9 znaków\n");
    if (addresStreet.isEmpty())
        tmpErrorMsg.append("Nie podałeś podstawowego adresu zamieszkania\n");

    if (!tmpErrorMsg.isEmpty()) {
        QMessageBox::information(this, APPLICATION_NAME, tmpErrorMsg);
    } else {
        shared_ptr<Client> tmpClient(new Client(
                firstName.toStdString(),
                lastName.toStdString(),
                personalID.toStdString(),
                AddressPtr(new Address(addresStreet.toStdString(), addresNr.toStdString())),
                AddressPtr(new Address(registeredAddressStreet.toStdString(), registeredAddressNr.toStdString()))
                ));
	this->editClient(tmpClient);
	this->close();
    }
}