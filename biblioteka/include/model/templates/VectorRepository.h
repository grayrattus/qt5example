#ifndef VECTORREPOSITORY_H
#define VECTORREPOSITORY_H

#include <vector>
#include "BaseRepository.h"
#include <iostream>

template <class T>
class VectorRepository : public BaseRepository<T> {
public:

    void create(T item) {
        items.push_back(item);
    };

    void remove(T item) {
        for (typename vector<T>::iterator it = items.begin(); it != items.end();) {
            if ((*it) == item) {
                it = items.erase(it);
            } else {
                ++it;
            }
        }
    };

    void update(T item) {
	for (auto &it:items) {
	    if (it == item) {
		it = item;
	    }
	}
    };

    bool find(T item) {
        for (typename vector<T>::iterator it = items.begin(); it != items.end();) {
            if ((*it) == item) {
                return true;
            } else {
                ++it;
            }
        }
        return false;
    };

    const vector<T> getAll() {
	return this-> items;
    }

    vector<T> items;
};

#endif 