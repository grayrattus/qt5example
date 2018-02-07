#ifndef CLIENTEXCEPTION_H
#define CLIENTEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class ClientException: public logic_error {
public:
    static const string ERROR_WRONS_PERSONAL_ID ;

    ClientException(const string &arg);
};


#endif /* CLIENTEXCEPTION_H */

