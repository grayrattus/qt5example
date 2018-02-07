/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NewRent.h
 * Author: grayrattus
 *
 * Created on December 30, 2017, 12:47 AM
 */

#ifndef _NEWRENT_H
#define _NEWRENT_H

#include "ui_NewRent.h"
#include <string>

using namespace std;

class NewRent : public QDialog {
    Q_OBJECT
public:
    NewRent();
    virtual ~NewRent();
private:
    Ui::NewRent widget;
    const QString APPLICATION_NAME = "Dodaj wypożyczenie";
private slots:
    void accept();
};

#endif /* _NEWRENT_H */
