#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
private:
    int key;
    int value;
    Node* next;
public:

    Node() {
        this->key = 0;
        this->value = 0;
        this->next = NULL;
    }

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    Node* getNext() {
        return next;
    }

    void setValue(int value) {
        this->value = value;
    }

    int getValue() {
        return value;
    }

    void setKey(int key) {
        this->key = key;
    }

    int getKey() {
        return key;
    }
};