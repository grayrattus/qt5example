/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newForm.h
 * Author: grayrattus
 *
 * Created on December 27, 2017, 10:16 PM
 */

#ifndef _NEWFORM_H
#define _NEWFORM_H

#include "ui_newForm.h"
#include <QString>
#include <memory>
#include <Client.h>

class newForm : public QDialog {
    Q_OBJECT
public:
    newForm();
    virtual ~newForm();
    signals:
    void newClient(std::shared_ptr<Client>);
private:
    const QString APPLICATION_NAME = "Dodaj klienta";
    Ui::newForm widget;
private slots:
    void accept();

};

#endif /* _NEWFORM_H */
