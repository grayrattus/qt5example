/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NewBicycle.h
 * Author: grayrattus
 *
 * Created on January 9, 2018, 11:23 AM
 */

#ifndef _NEWBICYCLE_H
#define _NEWBICYCLE_H

#include "ui_NewBicycle.h"
#include "Vehicle.h"
#include <memory>

class NewBicycle : public QDialog {
    Q_OBJECT
public:
    NewBicycle();
    virtual ~NewBicycle();
signals:
    void newBicycle(std::shared_ptr<Vehicle>);
private:
    Ui::NewBicycle widget;
private slots:
    void accept();
};

#endif /* _NEWBICYCLE_H */
