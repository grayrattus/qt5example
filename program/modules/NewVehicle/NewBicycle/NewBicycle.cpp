/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NewBicycle.cpp
 * Author: grayrattus
 *
 * Created on January 9, 2018, 11:23 AM
 */

#include "NewBicycle.h"
#include "model/Bicycle.h"
#include <QString>
#include <Vehicle.h>
#include <QIntValidator>
#include <modules/mainWindow/mainWindow.h>

NewBicycle::NewBicycle() {
    mainWindow* instance = mainWindow::GetInstance();
    QObject::connect(this, SIGNAL(newBicycle(std::shared_ptr<Vehicle>)), instance, SLOT(sAddVehicle(std::shared_ptr<Vehicle>)));
    widget.setupUi(this);
    this->widget.baseRentPrice->setValidator(new QIntValidator(0, 8000, this));
}

NewBicycle::~NewBicycle() {
}
void NewBicycle::accept() {
    QString id = this->widget.id->text();
    QString baseRentPrice = this->widget.baseRentPrice->text();

    shared_ptr<Bicycle> tmpBicycle(new Bicycle(
            id.toStdString(),
            baseRentPrice.toInt()
            ));

    this->newBicycle(tmpBicycle);
    this->close();
}
