#ifndef HASHTABLE_ENCADEAMENTOINTERNO_H
#define HASHTABLE_ENCADEAMENTOINTERNO_H

#include "Node.h"

class HashTable_EncadeamentoInterno {
private:
    Node** htable;
    const int TABLE_SIZE = 8;
    void insert_position(int key, int value, int position);
    int search_previous(int key, int value);
    int hashFunction(int key);
    bool isFull();
public:

    HashTable_EncadeamentoInterno();
    ~HashTable_EncadeamentoInterno();
    void insert(int key, int value);
    void remove(int key, int value);
    int search(int key, int value);
    void displayAll();
    
};

#endif /* HASHTABLE_ENCADEAMENTOINTERNO_H */