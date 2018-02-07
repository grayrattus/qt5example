/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientEditForm.h
 * Author: grayrattus
 *
 * Created on December 29, 2017, 10:56 PM
 */

#ifndef _CLIENTEDITFORM_H
#define _CLIENTEDITFORM_H

#include "ui_ClientEditForm.h"
#include <Client.h>

class ClientEditForm : public QDialog {
    Q_OBJECT
public:
    const QString APPLICATION_NAME = "Edytuj klienta";
    ClientEditForm(shared_ptr<Client> client);
    virtual ~ClientEditForm();
signals:
    void editClient(std::shared_ptr<Client>);
private:
    Ui::ClientEditForm widget;
private slots:
    void accept();
};

#endif /* _CLIENTEDITFORM_H */
