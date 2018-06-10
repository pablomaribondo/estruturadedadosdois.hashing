#include <cstdlib>
#include <iostream>
#include "HashTable_HashingDuplo.h"

using namespace std;

HashTable_HashingDuplo::HashTable_HashingDuplo() {
    htable = new Node*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        htable[i] = NULL;
    }
}

HashTable_HashingDuplo::~HashTable_HashingDuplo() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete htable[i];
    }
    delete[] htable;
}

int HashTable_HashingDuplo::hashFunction(String key) {
    return stringTransposition(key) % TABLE_SIZE;
}

int HashTable_HashingDuplo::doubleHashFunction(String key) {
    return 1 + (stringTransposition(key) % (TABLE_SIZE - 1));
}

int HashTable_HashingDuplo::reHashFunction(int index, String key) {
    return (index + doubleHashFunction(key)) % TABLE_SIZE;
}

int HashTable_HashingDuplo::stringTransposition(String key) {
    int sum = 0, numericValue;
    for (int i = 0; i < key.length(); i++) {
        numericValue = int (key.at(i));
        sum += numericValue << i % 8;
    }
    return (abs(sum) % TABLE_SIZE) + 1;
}

void HashTable_HashingDuplo::insert(String key, String value) {
    if (find(key, value) == -1) {
        if (!isFull()) {
            int index, hash_val, position = hashFunction(key);
            if (htable[position] == NULL) {
                Node* newNode = new Node(key, value);
                htable[position] = newNode;
            } else {
                index = hash_val = hashFunction(key);
                position = reHashFunction(index, key);
                do {
                    if (htable[position] == NULL) {
                        Node* newNode = new Node(key, value);
                        htable[position] = newNode;
                        break;
                    } else {
                        position = reHashFunction(++index, key);
                    }
                } while (position != reHashFunction(hash_val, key));
            }
        } else {
            cout << "The Hash Table is full!" << endl;
        }
    } else {
        cout << "This Element already exists!" << endl;
    }
}

void HashTable_HashingDuplo::remove(String key, String value) {
    int position = find(key, value);
    if (position == -1) {
        cout << "This element does not exist!" << endl;
    } else {
        delete htable[position];
        htable[position] = NULL;
    }
}

int HashTable_HashingDuplo::find(String key, String value) {
    int aux_position = -1;
    int hash_val = hashFunction(key);
    if (htable[hash_val] == NULL) {
        return aux_position;
    } else if (htable[hash_val]->getKey() == key && htable[hash_val]->getValue() == value) {
        return hash_val;
    } else {
        int index = hash_val;
        int position = reHashFunction(index, key);
        do {
            if (htable[position] == NULL) {
                position = reHashFunction(++index, key);
            } else if (htable[position]->getKey() == key && htable[position]->getValue() == value) {
                aux_position = position;
                break;
            } else {
                position = reHashFunction(++index, key);
            }
        } while (position != reHashFunction(hash_val, key));
    }
    return aux_position;
}

void HashTable_HashingDuplo::displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (htable[i] == NULL) {
            cout << "Empty" << endl;
        } else {
            cout << "[Key: " << htable[i]->getKey() << " Value: " << htable[i]->getValue() << "]" << endl;
        }
    }
}

bool HashTable_HashingDuplo::isFull() {
    bool flag = true;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (htable[i] != NULL) {
            continue;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}