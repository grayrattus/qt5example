/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newForm.cpp
 * Author: grayrattus
 *
 * Created on December 27, 2017, 10:16 PM
 */

#include <qt5/QtWidgets/qdialog.h>
#include <QMessageBox>
#include "newForm.h"
#include "model/Client.h"
#include <modules/mainWindow/mainWindow.h>

newForm::newForm() {
    mainWindow* instance = mainWindow::GetInstance();
    QObject::connect(this, SIGNAL(newClient(std::shared_ptr<Client>)), instance, SLOT(sAddClient(std::shared_ptr<Client>)), Qt::UniqueConnection);
    widget.setupUi(this);
}

void newForm::accept() {
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
	this->newClient(tmpClient);
	this->close();
    }
}

newForm::~newForm() {
}
