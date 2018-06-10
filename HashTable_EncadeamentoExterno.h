#ifndef HASHTABLE_ENCADEAMENTOEXTERNO_H
#define HASHTABLE_ENCADEAMENTOEXTERNO_H

#include "List.h"

class HashTable_EncadeamentoExterno {
private:
    List* htable;
    const int TABLE_SIZE = 12000;
    int hashFunction(String key);
    int stringTransposition(String key);
public:
    HashTable_EncadeamentoExterno();
    ~HashTable_EncadeamentoExterno();
    void insert(String key, String value);
    void remove(String key, String value);
    void remove_position(int position);
    int find(String key, String value);
    void displayAll();
};

#endif /* HASHTABLE_ENCADEAMENTOEXTERNO_H */