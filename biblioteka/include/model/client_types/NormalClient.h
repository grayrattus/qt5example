#ifndef NORMALCLIENT_H
#define NORMALCLIENT_H

#include <ClientType.h>

class NormalClient : public ClientType {
public:
    NormalClient();
    ~NormalClient();
private:
    static constexpr double DEFAULT_DISCOUNT = 0;
    static constexpr int DEFAULT_MAX_RENTS = 1;
};

#endif /* NORMALCLIENT_H */

