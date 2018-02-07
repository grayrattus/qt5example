/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NewMope.h
 * Author: grayrattus
 *
 * Created on January 9, 2018, 11:22 AM
 */

#ifndef _NEWMOPE_H
#define _NEWMOPE_H

#include "ui_NewMope.h"
#include <Vehicle.h>
#include <memory>

class NewMope : public QDialog {
    Q_OBJECT
public:
    NewMope();
    virtual ~NewMope();
signals:
    void newMope(std::shared_ptr<Vehicle>);
private:
    Ui::NewMope widget;
private slots:
    void accept();
};

#endif /* _NEWMOPE_H */
