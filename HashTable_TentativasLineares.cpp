#include <cstdlib>
#include <iostream>
#include "HashTable_TentativasLineares.h"

using namespace std;

HashTable_TentativasLineares::HashTable_TentativasLineares() {
    htable = new Node*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        htable[i] = NULL;
    }
}

HashTable_TentativasLineares::~HashTable_TentativasLineares() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete htable[i];
    }
    delete[] htable;
}

int HashTable_TentativasLineares::hashFunction(int key) {
    return key % TABLE_SIZE;
}

int HashTable_TentativasLineares::reHashFunction(int index) {
    return (index + 1) % TABLE_SIZE;
}

void HashTable_TentativasLineares::insert(int key, int value, int position) {
    if (find(key, value) == -1) {
        if (!this->isFull()) {
            static int index;
            if (position == -2) {
                position = hashFunction(key);
                index = key;
            }
            if (htable[position] == NULL) {
                Node* newNode = new Node(key, value);
                htable[position] = newNode;
            } else {
                position = reHashFunction(index++);
                if (position != hashFunction(key)) {
                    insert(key, value, position);
                } 
            }
        } else {
            cout << "The Hash Table is full!" << endl;
        }
    } else {
        cout << "This Element already exists!" << endl;
    }
}

void HashTable_TentativasLineares::remove(int key, int value) {
    int position = find(key, value);
    if (position == -1) {
        cout << "This element does not exist!" << endl;
    } else {
        delete htable[position];
        htable[position] = NULL;
    }
}

int HashTable_TentativasLineares::find(int key, int value) {
    int position = -1;
    int hash_val = hashFunction(key);
    if (htable[hash_val] == NULL) {
        return position;
    } else if (htable[hash_val]->getKey() == key && htable[hash_val]->getValue() == value) {
        return hash_val;
    } else {
        int index = key;
        int aux = reHashFunction(index);
        while (aux != hash_val) {
            if (htable[aux] == NULL) {
                aux = reHashFunction(++index);
                continue;
            } else if (htable[aux]->getKey() == key && htable[aux]->getValue() == value) {
                position = aux;
                break;
            }
            aux = reHashFunction(++index);
        }
    }
    return position;
}

void HashTable_TentativasLineares::displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (htable[i] == NULL) {
            cout << "Empty" << endl;
        } else {
            cout << "[Key: " << htable[i]->getKey() << " Value: " << htable[i]->getValue() << "]" << endl;
        }
    }
}

bool HashTable_TentativasLineares::isFull() {
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