#ifndef HASHTABLE_ENCADEAMENTOINTERNO_H
#define HASHTABLE_ENCADEAMENTOINTERNO_H

#include "Node.h"

class HashTable_EncadeamentoInterno {
private:
    Node** htable;
    const int TABLE_SIZE = 8;
public:

    HashTable_EncadeamentoInterno();
    ~HashTable_EncadeamentoInterno();
    int hashFunc(int key);
    void insert(int key, int value);
    void insert_position(int key, int value, int position);
    void remove(int key, int value);
    int search(int key, int value);
    int search_previous(int key, int value);
    void displayAll();
    bool isFull();
    
};

#endif /* HASHTABLE_ENCADEAMENTOINTERNO_H */