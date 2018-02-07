#include "ClientException.h"

using namespace std;

ClientException::ClientException(const string &arg) : logic_error(arg) {
}

const string ClientException::ERROR_WRONS_PERSONAL_ID = "Zły numer pesel.";
