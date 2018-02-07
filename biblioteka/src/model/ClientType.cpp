#include "ClientType.h"

ClientType::ClientType(double discount, int maxRents) : discount{discount}, maxRents{maxRents}
{
};

ClientType::~ClientType() {
};

int ClientType::getMaxRents() {
    return this->maxRents;
}

double ClientType::getDiscount() {
    return this->discount;
}