#ifndef HASHTABLE_ENCADEAMENTOEXTERNO_H
#define HASHTABLE_ENCADEAMENTOEXTERNO_H

#include "List.h"

class HashTable_EncadeamentoExterno {
private:
    List* htable;
    const int TABLE_SIZE = 4;
public:

    HashTable_EncadeamentoExterno();
    ~HashTable_EncadeamentoExterno();
    int hashFunc(int key);
    void insert(int key, int value);
    void remove(int key, int value);
    int search(int key, int value);
    void displayAll();
    
};

#endif /* HASHTABLE_ENCADEAMENTOEXTERNO_H */