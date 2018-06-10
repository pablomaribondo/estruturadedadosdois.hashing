#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    this->key = "";
    this->value = "";
    this->next = NULL;
}

Node::Node(String key, String value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

Node::Node(String key, String value, Node* next) {
    this->key = key;
    this->value = value;
    this->next = next;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() {
    return next;
}

void Node::setValue(String value) {
    this->value = value;
}

String Node::getValue() {
    return value;
}

void Node::setKey(String key) {
    this->key = key;
}

String Node::getKey() {
    return key;
}