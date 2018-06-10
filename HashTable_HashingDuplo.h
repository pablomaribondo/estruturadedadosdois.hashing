#ifndef HASHTABLE_HASHINGDUPLO_H
#define HASHTABLE_HASHINGDUPLO_H

#include "Node.h"

class HashTable_HashingDuplo {
private:
    Node** htable;
    const int TABLE_SIZE = 8;
    int hashFunction(int key);
    int doubleHashFunction(int key);
    int reHashFunction(int index, int key);
    bool isFull();
public:
    HashTable_HashingDuplo();
    ~HashTable_HashingDuplo();
    void insert(int key, int value);
    void remove(int key, int value);
    int find(int key, int value);
    void displayAll();
};

#endif /* HASHTABLE_HASHINGDUPLO_H */

