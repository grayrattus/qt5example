/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mainWindow.h
 * Author: grayrattus
 *
 * Created on December 27, 2017, 11:29 PM
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "ui_mainWindow.h"
#include <memory>
#include <Client.h>
#include <Vehicle.h>
#include <ClientRepository.h>
#include <ClientManager.h>
#include <VehicleManager.h>
#include <RentsManager.h>
#include <VehicleRepository.h>

class mainWindow : public QMainWindow {
    Q_OBJECT
public:
    mainWindow();
    virtual ~mainWindow();
    void removeClient(shared_ptr<Client> client);
    void removeVehicle(shared_ptr<Vehicle> vehicle);
    void createRent(std::shared_ptr<Rent> rent);
    void refreshCurrentRepositoryTable();
public slots:
    void sAddClient(std::shared_ptr<Client> client);
    void sAddVehicle(std::shared_ptr<Vehicle> vehicle);
    void sEditClient(std::shared_ptr<Client> client);
    void addClient();
    void addRent();
    void addCar();
    void addBicycle(); 
    void addMope(); 
    void saveClients(); 
	void loadClients(); 
	void saveVehicles(); 
	void loadVehicles(); 
    void showClients();
    void showVehicles();
    void showCurrentRents();
    void showArchivedRents();
    static mainWindow* GetInstance();
    const vector<shared_ptr<Client>> getClients();
    const vector<shared_ptr<Vehicle>> getVehicles();
    const vector<shared_ptr<Vehicle>> getAvailableVehicles();
    const shared_ptr<Client> getClientById(string id);
    const shared_ptr<Vehicle> getVehicleById(string id);
    const vector<shared_ptr<Rent>> getCurrentRents();
    const vector<shared_ptr<Rent>> getArchivedRents();
private:
    static mainWindow* mainInstance;
    Ui::mainWindow widget;
    ClientManager clientRepository;
    RentsManager rentsManager;
    VehicleManager vehicleRepository;

    enum TABLE_LABELS {
        RENT_ID, CLIENT_ID, VEHICLE_ID, CURRENT_COST, RENT_PRICE, DATE
    };
};


#endif /* _MAINWINDOW_H */
