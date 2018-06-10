#ifndef HASHTABLE_TENTATIVASLINEARES_H
#define HASHTABLE_TENTATIVASLINEARES_H

#include "Node.h"

class HashTable_TentativasLineares {
private:
    Node** htable;
    const int TABLE_SIZE = 8;
    int hashFunction(int key);
    int reHashFunction(int index);
    bool isFull();
public:
    HashTable_TentativasLineares();
    ~HashTable_TentativasLineares();
    void insert(int key, int value, int = - 2);
    void remove(int key, int value);
    int find(int key, int value);
    void displayAll();
};

#endif /* HASHTABLE_TENTATIVASLINEARES_H */