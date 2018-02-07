#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H
#include "Client.h"
#include "ClientType.h"
#include "templates/VectorRepository.h"
#include <vector>
#include <string>

using namespace std;

class ClientRepository: public VectorRepository<shared_ptr<Client>> {
public:
    ClientRepository();
    ClientRepository(const ClientRepository& orig);
    virtual ~ClientRepository();
};

#endif /* CLIENTREPOSITORY_H */

