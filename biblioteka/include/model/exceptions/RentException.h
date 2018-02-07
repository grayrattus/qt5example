#ifndef RENTEXCEPTION_H
#define RENTEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class RentException: public logic_error {
public:
    static const string ERROR_WRONG_PRICE ;
    RentException(const string &arg);
private:

};

#endif /* RENTEXCEPTION_H */

