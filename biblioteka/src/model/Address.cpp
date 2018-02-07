#include "Address.h"
#include <iostream>
#include <memory>

using namespace std;

string Address::getStreet(){
	return this->street;
};
void Address::setStreet(string newStreet){
	this->street = newStreet;
};
string Address::getNumber(){
	return this->number;
};
void Address::setNumber(string newNumber){
	this->number = newNumber;
};
string Address::toString() {
	return this->getStreet() + " " + this->getNumber();
}

Address::Address(string street, string number): street{street}, number{number}{
};
Address::Address() {
};
Address::~Address() {
};
