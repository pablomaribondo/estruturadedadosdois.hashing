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

int HashTable_HashingDuplo::hashFunction(int key) {
    return key % TABLE_SIZE;
}

int HashTable_HashingDuplo::doubleHashFunction(int key) {
    return 1 + (key % (TABLE_SIZE - 1));
}

int HashTable_HashingDuplo::reHashFunction(int index, int key) {
    return (index + doubleHashFunction(key)) % TABLE_SIZE;
}

void HashTable_HashingDuplo::insert(int key, int value) {
    if (find(key, value) == -1) {
        if (!isFull()) {
            int index, aux, position = hashFunction(key);
            if (htable[position] == NULL) {
                Node* newNode = new Node(key, value);
                htable[position] = newNode;
            } else {
                index = aux = hashFunction(key);
                position = reHashFunction(index, key);
                do {
                    if (htable[position] == NULL) {
                        Node* newNode = new Node(key, value);
                        htable[position] = newNode;
                        break;
                    } else {
                        position = reHashFunction(++index, key);
                    }
                } while (position != reHashFunction(aux, key));
            }
        } else {
            cout << "The Hash Table is full!" << endl;
        }
    } else {
        cout << "This Element already exists!" << endl;
    }
}

void HashTable_HashingDuplo::remove(int key, int value) {

}

int HashTable_HashingDuplo::find(int key, int value) {
    return -1;
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