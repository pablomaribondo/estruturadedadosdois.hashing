#ifndef HASHTABLE_TENTATIVASLINEARES_H
#define HASHTABLE_TENTATIVASLINEARES_H

#include "Node.h"

class HashTable_TentativasLineares {
private:
    Node** htable;
    const int TABLE_SIZE = 30000;
    int hashFunction(String key);
    int reHashFunction(int index);
    int stringTransposition(String key);
    bool isFull();
public:
    HashTable_TentativasLineares();
    ~HashTable_TentativasLineares();
    void insert(String key, String value);
    void remove(String key, String value);
    void remove_position(int position);
    int find(String key, String value);
    void displayAll();
};

#endif /* HASHTABLE_TENTATIVASLINEARES_H */