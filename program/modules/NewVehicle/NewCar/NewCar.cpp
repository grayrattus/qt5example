/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NewCar.cpp
 * Author: grayrattus
 *
 * Created on December 30, 2017, 1:11 AM
 */

#include "NewCar.h"
#include <Car.h>
#include <Segment.h>
#include <QString>
#include <Vehicle.h>
#include <Segment.h>
#include <QIntValidator>
#include <modules/mainWindow/mainWindow.h>

NewCar::NewCar() {
    mainWindow* instance = mainWindow::GetInstance();
    QObject::connect(this, SIGNAL(newCar(std::shared_ptr<Vehicle>)), instance, SLOT(sAddVehicle(std::shared_ptr<Vehicle>)));
    widget.setupUi(this);
    this->widget.engineDisplacement->setValidator(new QIntValidator(0, 8000, this));
    this->widget.baseRentPrice->setValidator(new QIntValidator(0, 500000, this));
    this->widget.segment->addItem("A");
    this->widget.segment->addItem("B");
    this->widget.segment->addItem("C");
    this->widget.segment->addItem("D");
    this->widget.segment->addItem("E");
}

NewCar::~NewCar() {
}

void NewCar::accept() {
    QString engineDisplacement = this->widget.engineDisplacement->text();
    QString id = this->widget.id->text();
    QString baseRentPrice = this->widget.baseRentPrice->text();
    QString segment = this->widget.segment->itemData(this->widget.segment->currentIndex()).toString();

    shared_ptr<Car> tmpCar(new Car(
            engineDisplacement.toInt(),
            id.toStdString(),
            baseRentPrice.toInt(),
            SegmentPtr(new Segment(segment.data()->toLatin1()))
            ));

    this->newCar(tmpCar);
    this->close();

}