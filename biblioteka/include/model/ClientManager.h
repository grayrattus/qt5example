#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "ClientRepository.h"
#include <string>


class ClientManager: public ClientRepository {
public:
    ClientManager();
    ClientManager(const ClientManager& orig);
    virtual ~ClientManager();
    
    void changeClientType(int , ClientTypePtr); 
    void update(shared_ptr<Client> item) override;
    const shared_ptr<Client> getClient(string personalID);
};

#endif /* CLIENTMANAGER_H */

