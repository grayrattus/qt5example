/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehicles.h
 * Author: grayrattus
 *
 * Created on December 30, 2017, 1:50 AM
 */

#ifndef _VEHICLES_H
#define _VEHICLES_H

#include "ui_Vehicles.h"

class Vehicles : public QDialog {
    Q_OBJECT
public:
    Vehicles();
    virtual ~Vehicles();
private:
    Ui::Vehicles widget;
    void fillTable();
    enum tableLabels {
	ID, BASE_RENT_PRICE, TYPE, DELETE
    };
};

#endif /* _VEHICLES_H */
