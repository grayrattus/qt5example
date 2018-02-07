/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   mainWindow.cpp
 * Author: grayrattus
 *
 * Created on December 27, 2017, 11:29 PM
 */

#include "mainWindow.h"
#include "model/templates/VectorRepository.h"
#include <QMessageBox>
#include <string>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QTableWidget>
#include <boost/uuid/uuid_io.hpp>
#include <modules/Clients/Clients.h>
#include <modules/newForm/newForm.h>
#include <modules/NewRent/NewRent.h>
#include <modules/NewVehicle/NewCar/NewCar.h>
#include <modules/NewVehicle/NewMope/NewMope.h>
#include <modules/NewVehicle/NewBicycle/NewBicycle.h>
#include <modules/Vehicles/Vehicles.h>
#include <modules/ArchivedRents/ArchivedRents.h>
#include <modules/Serialization/ClientSerialization.cpp>
#include <Car.h>
#include <Mope.h>
#include <Bicycle.h>


mainWindow::mainWindow() {
    widget.setupUi(this);
}

mainWindow::~mainWindow() {
}

mainWindow* mainWindow::GetInstance() {
    if (mainWindow::mainInstance == NULL) {
        mainWindow::mainInstance = new mainWindow();
    }
    return mainWindow::mainInstance;
}

void mainWindow::showClients() {
    unique_ptr<Clients> c(new Clients);
    c->exec();
    c->show();
}

void mainWindow::showVehicles() {
    unique_ptr<Vehicles> v(new Vehicles);
    v->exec();
    v->show();
};

void mainWindow::showCurrentRents() {
};

void mainWindow::showArchivedRents() {
    unique_ptr<ArchivedRents> ar(new ArchivedRents);
    ar->exec();
    ar->show();
};

void mainWindow::addClient() {
    unique_ptr<newForm> nf(new newForm);
    nf->exec();
    nf->show();
};

void mainWindow::addRent() {
    unique_ptr<NewRent> nr(new NewRent);
    nr->exec();
    nr->show();
};

void mainWindow::addBicycle() {
    unique_ptr<NewBicycle> bc(new NewBicycle);
    bc->exec();
    bc->show();
};

void mainWindow::addMope() {
    unique_ptr<NewMope> m(new NewMope);
    m->exec();
    m->show();
};

void mainWindow::addCar() {
    unique_ptr<NewCar> nc(new NewCar);
    nc->exec();
    nc->show();
};

const vector<shared_ptr<Rent>> mainWindow::getCurrentRents() {
    return this->rentsManager.getCurrentRents();
}

const vector<shared_ptr<Rent>> mainWindow::getArchivedRents() {
    return this->rentsManager.getArchiveRents();
};

const vector<shared_ptr<Client>> mainWindow::getClients() {
    return this->clientRepository.getAll();
}

const vector<shared_ptr<Vehicle>> mainWindow::getVehicles() {
    return this->vehicleRepository.getAll();
};

const vector<shared_ptr<Vehicle>> mainWindow::getAvailableVehicles() {
    auto allVehicles = this->vehicleRepository.getAll();
    vector<shared_ptr < Vehicle>> availableVehicles;
    for (auto vehicle : allVehicles) {
        if (!vehicle->isRented()) {
            availableVehicles.push_back(vehicle);
        }
    }
    return availableVehicles;
};

void mainWindow::removeClient(shared_ptr<Client> client) {
    this->clientRepository.remove(client);
}

void mainWindow::removeVehicle(shared_ptr<Vehicle> vehicle) {
    this->vehicleRepository.remove(vehicle);
}

void mainWindow::sAddClient(shared_ptr<Client> client) {
    this->clientRepository.create(client);
};

void mainWindow::sAddVehicle(std::shared_ptr<Vehicle> vehicle) {
    this->vehicleRepository.create(vehicle);
};

void mainWindow::sEditClient(shared_ptr<Client> client) {
    this->clientRepository.update(client);
};

const shared_ptr<Client> mainWindow::getClientById(string id) {
    return this->clientRepository.getClient(id);
};

const shared_ptr<Vehicle> mainWindow::getVehicleById(string id) {
    return this->vehicleRepository.getVehicle(id);
};

void mainWindow::createRent(std::shared_ptr<Rent> rent) {
    this->rentsManager.createRent(rent);
};

void mainWindow::refreshCurrentRepositoryTable() {
    auto currentRents = this->rentsManager.getCurrentRents();
    this->widget.currentRepositoryTable->setRowCount(0);
    unsigned int row = 0;
    for (auto currentRent : currentRents) {
        QTableWidgetItem *rentId = new QTableWidgetItem(QString::fromStdString(boost::uuids::to_string(currentRent->getId())));
        QTableWidgetItem *clientId = new QTableWidgetItem(QString::fromStdString(currentRent->getClientId()));
        QTableWidgetItem *vehicleId = new QTableWidgetItem(QString::fromStdString(currentRent->getVehicleId()));
        QTableWidgetItem *currentCost = new QTableWidgetItem(QString::number(currentRent->currentCost()));
        QTableWidgetItem *rentPrice = new QTableWidgetItem(QString::number(currentRent->getRentPrice()));
        QTableWidgetItem *returnTime = new QTableWidgetItem(QString::fromStdString(currentRent->getReturnDate()));
        this->widget.currentRepositoryTable->insertRow(row);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::RENT_ID, rentId);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::CLIENT_ID, clientId);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::VEHICLE_ID, vehicleId);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::CURRENT_COST, currentCost);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::RENT_PRICE, rentPrice);
        this->widget.currentRepositoryTable->setItem(row, this->TABLE_LABELS::DATE, returnTime);
	row++;
    }
};
void mainWindow::saveVehicles() {
	QFile file("/home/pobi/vehicles.txt");
	
	if (!file.open(QIODevice::WriteOnly)) {
		qDebug() << "Nie mozna otworzyc pliku do zapisu klientow.";
		return;
	}

	const vector<shared_ptr<Vehicle>> cars = this->vehicleRepository.getVehiclesByType(VehicleType::CAR);
	const vector<shared_ptr<Vehicle>> mopes = this->vehicleRepository.getVehiclesByType(VehicleType::MOPE);
	const vector<shared_ptr<Vehicle>> bicycles = this->vehicleRepository.getVehiclesByType(VehicleType::BICYCLE);

	
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_1);
	
	int size = cars.size();
	out << size;
	
	for(shared_ptr<Vehicle> car : cars) {
		out << QString::fromStdString(dynamic_pointer_cast<Car>(car)->getId()) 
			<< dynamic_pointer_cast<Car>(car)->getBaseRentPrice()
			<< dynamic_pointer_cast<Car>(car)->getEngineDisplacement()
			<< QString::fromStdString(dynamic_pointer_cast<Car>(car)->getSegmentLetter());
	}
	
	size = mopes.size();
	out << size;
	
	for(auto mope : mopes) {
		out << QString::fromStdString(dynamic_pointer_cast<Mope>(mope)->getId()) 
			<< dynamic_pointer_cast<Mope>(mope)->getBaseRentPrice()
			<< dynamic_pointer_cast<Mope>(mope)->getEngineDisplacement();
	}

	size = bicycles.size();
	out << size;
	
	for(auto bicycle : bicycles) {
		out << QString::fromStdString(dynamic_pointer_cast<Bicycle>(bicycle)->getId()) 
			<< dynamic_pointer_cast<Bicycle>(bicycle)->getBaseRentPrice();
	}
	
	file.flush();
	file.close();
}


void mainWindow::loadVehicles() {
	QFile file("/home/pobi/vehicles.txt");
	
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "Nie mozna otworzyc pliku do zapisu klientow.";
		return;
	}
	
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_1);
	
	int size = 0;
	out >> size;

	QString id;
	int baseRentPrice = 0;
	int engineDisplacement = 0;
	QString letter;

	for(int i = 0 ; i < size ; i++) {
		out >> id
			>> baseRentPrice
			>> engineDisplacement
			>> letter;
		shared_ptr<Car> car(new Car(engineDisplacement, id.toStdString(), baseRentPrice, SegmentPtr( new Segment(letter.toStdString()[0]))));
		this->vehicleRepository.create(car);
	}
	
	out >> size;
	
	for(int i = 0 ; i < size ; i++) {
		out >> id
			>> baseRentPrice
			>> engineDisplacement;
		shared_ptr<Mope> mope(new Mope(engineDisplacement, id.toStdString(), baseRentPrice));
		this->vehicleRepository.create(mope);
	
	}

	out >> size;
	
	for(int i = 0 ; i < size ; i++) {
		out >> id
			>> baseRentPrice;
		shared_ptr<Bicycle> bicycle(new Bicycle(id.toStdString(), baseRentPrice));
		this->vehicleRepository.create(bicycle);
	}



	file.flush();
	file.close();
}

void mainWindow::saveClients() {
	QFile file("/home/pobi/clients.txt");
	if (!file.open(QIODevice::WriteOnly)) {
		qDebug() << "Nie mozna otworzyc pliku do zapisu klientow.";
		return;
	}
	
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_1);
	
	int size = this->getClients().size();
	out << size;
	
	for(auto client : this->getClients()) {
		ClientQtAdapter clientQt(client);
		out << clientQt.getFirstName() << clientQt.getLastName() << clientQt.getPersonalId() 
			<< clientQt.getRegisteredAddressStreet() << clientQt.getRegisteredAddressNumber() 
			<< clientQt.getAddressStreet() << clientQt.getAddressNumber() 			
			<< clientQt.getDiscount() << clientQt.getMaxRents();
	}
	
	file.flush();
	file.close();
	
	
}; 
void mainWindow::loadClients() {
	QFile file("/home/pobi/clients.txt");
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "Nie mozna otworzyc pliku do zapisu klientow.";
		return;
	}
	
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_1);
	
	struct clientQt {
		QString personalId;
		QString firstName;
		QString lastName;
		QString id;
		double discount;
		int maxRents;
	};

	struct addressQt {
		QString street;
		QString number;
	};
	
	int size = 0;
	in >> size;
	
	for(int i = 0 ; i < size ; i++) {
		clientQt tmpClient;
		addressQt tmpAddress;
		addressQt tmpRegisteredAddress;

		in >> tmpClient.firstName >> tmpClient.lastName >> tmpClient.personalId
			>> tmpRegisteredAddress.street >> tmpRegisteredAddress.number 
			>> tmpAddress.street >> tmpAddress.number 
			>> tmpClient.discount >> tmpClient.maxRents;

		AddressPtr address(new Address(
				tmpAddress.street.toStdString(),
				tmpAddress.number.toStdString()
				));
		AddressPtr registeredAddress(new Address(
				tmpRegisteredAddress.street.toStdString(),
				tmpRegisteredAddress.number.toStdString()
				));            
						
		shared_ptr<Client> klient(new Client(
				tmpClient.firstName.toStdString(),
				tmpClient.lastName.toStdString(),
				tmpClient.personalId.toStdString(), std::move(address), std::move(registeredAddress)));
		this->clientRepository.create(klient);
	}
		
	file.flush();
	file.close();	
}; 



mainWindow* mainWindow::mainInstance = NULL;


