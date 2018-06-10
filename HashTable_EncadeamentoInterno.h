#ifndef HASHTABLE_ENCADEAMENTOINTERNO_H
#define HASHTABLE_ENCADEAMENTOINTERNO_H

#include "Node.h"

class HashTable_EncadeamentoInterno {
private:
    Node** htable;
    const int TABLE_SIZE = 12000;
    void insert_position(String key, String value, int position);
    int search_previous(String key, String value);
    int hashFunction(String key);
    int stringTransposition(String key);
    bool isFull();
public:
    HashTable_EncadeamentoInterno();
    ~HashTable_EncadeamentoInterno();
    void insert(String key, String value);
    void remove(String key, String value);
    int find(String key, String value);
    void displayAll();
};

#endif /* HASHTABLE_ENCADEAMENTOINTERNO_H */