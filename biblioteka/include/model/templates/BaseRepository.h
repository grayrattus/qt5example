#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

template <class T>
class BaseRepository {
    void virtual create(T item) = 0;
    void virtual remove(T item) = 0; 
    void virtual update(T item) = 0; 
    bool virtual find(T item) = 0;
};

#endif /* BASEREPOSITORY_H */