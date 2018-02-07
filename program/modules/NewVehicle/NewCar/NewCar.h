/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NewCar.h
 * Author: grayrattus
 *
 * Created on December 30, 2017, 1:11 AM
 */

#ifndef _NEWCAR_H
#define _NEWCAR_H

#include "ui_NewCar.h"
#include <memory>
#include <Vehicle.h>

class NewCar : public QDialog {
    Q_OBJECT
public:
    NewCar();
    virtual ~NewCar();
signals:
    void newCar(std::shared_ptr<Vehicle>);
private:
    Ui::NewCar widget;
private slots:
    void accept();
};

#endif /* _NEWCAR_H */
