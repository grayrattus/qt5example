#include "RentException.h"

using namespace std;

RentException::RentException(const string &arg) : logic_error(arg) {
}

static const string ERROR_WRONG_PRICE = "Zła cena.";
