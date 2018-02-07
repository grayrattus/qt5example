#ifndef FREQUENTCLIENT_H
#define FREQUENTCLIENT_H

#include <ClientType.h>

class FrequentClient : public ClientType {
public:
    FrequentClient();
    virtual ~FrequentClient();
private:
    static constexpr double DEFAULT_DISCOUNT = 0.3;
    static constexpr int DEFAULT_MAX_RENTS = 2;
};

#endif /* FREQUENTCLIENT_H */

