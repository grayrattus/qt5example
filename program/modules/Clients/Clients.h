/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clients.h
 * Author: grayrattus
 *
 * Created on December 28, 2017, 12:48 PM
 */

#ifndef _CLIENTS_H
#define _CLIENTS_H

#include "ui_Clients.h"

class Clients : public QDialog {
    Q_OBJECT
public:

    Clients();
    virtual ~Clients();
private:
    Ui::Clients widget;
    void fillTable();
    enum tableLabels {
	FIRST_NAME, LAST_NAME, PERSONAL_ID, ADDRESS, REGISTERED_ADDRESS, EDIT, DELETE
    };
};

#endif /* _CLIENTS_H */
