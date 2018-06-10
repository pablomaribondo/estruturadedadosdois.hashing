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

int HashTable_EncadeamentoExterno::hashFunction(String key) {
    return stringTransposition(key) % TABLE_SIZE;
}

int HashTable_EncadeamentoExterno::stringTransposition(String key) {
    int sum = 0, numericValue;
    for (int i = 0; i < key.length(); i++) {
        numericValue = int (key.at(i));
        sum += numericValue << i % 8;
    }
    return (abs (sum) % TABLE_SIZE) + 1;
}

void HashTable_EncadeamentoExterno::insert(String key, String value) {
    int hash_val = hashFunction(key);
    htable[hash_val].insert_sorted(key, value);
}

void HashTable_EncadeamentoExterno::remove(String key, String value) {
    int hash_val = hashFunction(key);
    int position = htable[hash_val].search(key, value);
    if (position == -1) {
//        cout << "This element does not exist!" << endl;
    } else {
        htable[hash_val].remove_position(position);
    }
}

void HashTable_EncadeamentoExterno::remove_position(int position) {
    htable[position].remove_position(1);
}

int HashTable_EncadeamentoExterno::find(String key, String value) {
    int hash_val = hashFunction(key);
    int position = htable[hash_val].search(key, value);
    return position;
}

void HashTable_EncadeamentoExterno::displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Printing row number " << i + 1 << ":" << endl;
        htable[i].display();
    }
}