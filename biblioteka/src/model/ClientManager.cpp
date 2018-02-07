#include "ClientManager.h"

ClientManager::ClientManager() {
}

ClientManager::ClientManager(const ClientManager& orig) {
}

ClientManager::~ClientManager() {
}
void ClientManager::changeClientType(int pos, ClientTypePtr type) {
}



const shared_ptr<Client> ClientManager::getClient(string personalID) {
    for (auto client : items) {
        if (client->getPersonalId() == personalID) {
            return client;
        }
    }
    return NULL;
}

void ClientManager::update(shared_ptr<Client> item) {
    for (auto &i:items) {
	if (i->getPersonalId() == item->getPersonalId()) {
	    i = item;
	}
    }

}
