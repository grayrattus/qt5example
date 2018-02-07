/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NewMope.cpp
 * Author: grayrattus
 *
 * Created on January 9, 2018, 11:22 AM
 */

#include "NewMope.h"
#include <Mope.h>
#include <QString>
#include <Vehicle.h>
#include <QIntValidator>
#include <modules/mainWindow/mainWindow.h>


NewMope::NewMope() {
     mainWindow* instance = mainWindow::GetInstance();
     QObject::connect(this, SIGNAL(newMope(std::shared_ptr<Vehicle>)), instance, SLOT(sAddVehicle(std::shared_ptr<Vehicle>)));
     widget.setupUi(this);
     this->widget.engineDisplacement->setValidator(new QIntValidator(0, 8000, this));
     this->widget.baseRentPrice->setValidator(new QIntValidator(0, 8000, this));
}

NewMope::~NewMope() {
}

void NewMope::accept() {
    QString engineDisplacement = this->widget.engineDisplacement->text();
    QString id = this->widget.id->text();
    QString baseRentPrice = this->widget.baseRentPrice->text();

    shared_ptr<Mope> tmpMope(new Mope(
            engineDisplacement.toInt(),
            id.toStdString(),
            baseRentPrice.toInt()
            ));

    this->newMope(tmpMope);
    this->close();

}