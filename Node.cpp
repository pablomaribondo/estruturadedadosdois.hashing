#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    this->key = 0;
    this->value = 0;
    this->next = NULL;
}

Node::Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() {
    return next;
}

void Node::setValue(int value) {
    this->value = value;
}

int Node::getValue() {
    return value;
}

void Node::setKey(int key) {
    this->key = key;
}

int Node::getKey() {
    return key;
}