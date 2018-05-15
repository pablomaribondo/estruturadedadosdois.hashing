#include <cstdlib>
#include <iostream>
#include "HashTable_EncadeamentoInterno.h"

using namespace std;

HashTable_EncadeamentoInterno::HashTable_EncadeamentoInterno() {
    htable = new Node*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        htable[i] = NULL;
    }
}

HashTable_EncadeamentoInterno::~HashTable_EncadeamentoInterno() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete htable[i];
    }
    delete[] htable;
}

int HashTable_EncadeamentoInterno::hashFunc(int key) {
    return key % (TABLE_SIZE / 2);
}

void HashTable_EncadeamentoInterno::insert(int key, int value) {
    if (this->search(key, value) == -1) {
        if (!this->isFull()) {
            int hash_val = hashFunc(key);
            Node* newNode = new Node(key, value);
            if (htable[hash_val] == NULL) {
                htable[hash_val] = newNode;
            } else if (htable[hash_val]->getNext() == NULL) {
                for (int i = TABLE_SIZE / 2; i < TABLE_SIZE; i++) {
                    if (htable[i] == NULL) {
                        htable[i] = newNode;
                        htable[hash_val]->setNext(newNode);
                        break;
                    }
                }
            } else {
                int position = search(htable[hash_val]->getNext()->getKey(), htable[hash_val]->getNext()->getValue());
                insert_position(key, value, position);
            }
        } else {
            cout << "The Hash Table is full!" << endl;
        }
    } else {
        cout << "This Element already exists!" << endl;
    }
}

void HashTable_EncadeamentoInterno::insert_position(int key, int value, int position) {
    Node* newNode = new Node(key, value);
    if (htable[position] == NULL) {
        htable[position] = newNode;
    } else if (htable[position]->getNext() == NULL) {
        for (int i = position; i < TABLE_SIZE; i++) {
            if (htable[i] == NULL) {
                htable[i] = newNode;
                htable[position]->setNext(newNode);
                break;
            }
        }
    } else {
        int newPosition = search(htable[position]->getNext()->getKey(), htable[position]->getNext()->getValue());
        insert_position(key, value, newPosition);
    }
}

void HashTable_EncadeamentoInterno::remove(int key, int value) {
    int hash_val = hashFunc(key);
    int position = search(key, value);
    if (position == -1) {
        cout << "This element does not exist!" << endl;
    } else {
        Node* previous = htable[search_previous(key, value)];
        Node* current = htable[position]; 
        Node* next = current->getNext();
        if (search_previous(key, value) == -1) {
            if (next == NULL) {
                delete current;
                current = NULL;  
            } else {
                delete current;
                current = next;
            }
        } else {
            if (next == NULL) {
                delete current;
                current = NULL;
                previous->setNext(NULL);
            } else {
                delete current;
                current = next;
                previous->setNext(next);
            }
        }
    }
}

int HashTable_EncadeamentoInterno::search(int key, int value) {
    if (!isEmpty()) {
        int position = -1;
        int hash_val = hashFunc(key);
        if (htable[hash_val]->getKey() == key && htable[hash_val]->getValue() == value) {
            return hash_val;
        } else {
            for (int i = (TABLE_SIZE / 2); i < TABLE_SIZE; i++) {
                if (htable[i] == NULL) {
                    break;
                } else if (htable[i]->getKey() == key && htable[i]->getValue() == value) {
                    position = i;
                    break;
                }
            }
            return position;
        }
    } else {
        return -1;
    }
}

int HashTable_EncadeamentoInterno::search_previous(int key, int value) {
    if (!isEmpty()) {
        int position = -1;
        for (int i = 0; i < TABLE_SIZE; i++) {
                if (htable[i]->getNext()->getKey() == key && htable[i]->getNext()->getValue() == value) {
                    position = i;
                    break;
                }
            }
        return position;
    } else {
        return -1;
    }
}

void HashTable_EncadeamentoInterno::displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (htable[i] == NULL) {
            cout << "Empty" << endl;
            continue;
        }
        cout << "[Key: " << htable[i]->getKey() << " Value: " << htable[i]->getValue() << "]";
        if (htable[i]->getNext() != NULL) {
            cout << " -> [Key: " << htable[i]->getNext()->getKey() << "]";
        }
        cout << endl;
    }
}

bool HashTable_EncadeamentoInterno::isFull() {
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

bool HashTable_EncadeamentoInterno::isEmpty() {
    bool flag = true;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (htable[i] == NULL) {
            continue;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}



