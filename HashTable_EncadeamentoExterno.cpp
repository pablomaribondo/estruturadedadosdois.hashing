#include <cstdlib>
#include <iostream>
#include "HashTable_EncadeamentoExterno.h"

using namespace std;

HashTable_EncadeamentoExterno::HashTable_EncadeamentoExterno() {
    htable = new List[TABLE_SIZE];
}

HashTable_EncadeamentoExterno::~HashTable_EncadeamentoExterno() {
    delete[] htable;
}

int HashTable_EncadeamentoExterno::hashFunc(int key) {
    return key % TABLE_SIZE;
}

void HashTable_EncadeamentoExterno::insert(int key, int value) {
    int hash_val = hashFunc(key);
    htable[hash_val].insert_sorted(key, value);
}

void HashTable_EncadeamentoExterno::remove(int key, int value) {
    int hash_val = hashFunc(key);
    int position = htable[hash_val].search(key, value);
    if (position == -1) {
        cout << "This element does not exist!" << endl;
    } else {
        htable[hash_val].remove_position(position);
    }
}

int HashTable_EncadeamentoExterno::search(int key, int value) {
    int hash_val = hashFunc(key);
    int position = htable[hash_val].search(key, value);
    return position;
}

void HashTable_EncadeamentoExterno::displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Printing row number " << i + 1 << ":" << endl;
        htable[i].display();
    }
}