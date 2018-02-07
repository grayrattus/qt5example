/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArchivedRents.h
 * Author: grayrattus
 *
 * Created on December 30, 2017, 5:33 PM
 */

#ifndef _ARCHIVEDRENTS_H
#define _ARCHIVEDRENTS_H

#include "ui_ArchivedRents.h"

class ArchivedRents : public QDialog {
    Q_OBJECT
public:
    ArchivedRents();
    virtual ~ArchivedRents();
private:
    Ui::ArchivedRents widget;
    void fillTable();
    enum tableLabels {
	RENT_ID, CLIENT_ID, RENT_PRICE, VEHICLE_INFO
    };
};

#endif /* _ARCHIVEDRENTS_H */
