#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    head = NULL;
    tail = NULL;
}

List::List(String key, String value) {
    head = new Node(key, value);
    tail = head;
}

List::~List() {
    Node* atual = head;
    Node* prox = NULL;
    while (atual != NULL) {
        prox = atual->getNext();
        delete atual;
        atual = prox;
    }
}

void List::setTail(Node* tail) {
    this->tail = tail;
}

Node* List::getTail() {
    return tail;
}

void List::setHead(Node* head) {
    this->head = head;
}

Node* List::getHead() {
    return head;
}

int List::stringTransposition(String key) {
    int sum = 0, numericValue;
    for (int i = 0; i < key.length(); i++) {
        numericValue = int (key.at(i));
        sum += numericValue << i % 8;
    }
    return (abs(sum) % TABLE_SIZE) + 1;
}

void List::insert_first(String key, String value) {
    Node* newNode = new Node(key, value);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
}

void List::insert_position(int position, String key, String value) {
    Node* newNode = new Node(key, value);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        Node* previous = new Node(key, value);
        Node* current = new Node(key, value);
        current = head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->getNext();
        }
        newNode->setKey(key);
        newNode->setValue(value);
        previous->setNext(newNode);
        newNode->setNext(current);
    }

}

void List::insert_sorted(String key, String value) {
    int position = 2;
    if (search(key, value) == -1) {
        if (this->isEmpty() || stringTransposition(key) < stringTransposition(head->getKey()) || (key == head->getKey() && stringTransposition(value) < stringTransposition(head->getValue()))) {
            this->insert_first(key, value);
        } else {
            Node* next = new Node(key, value);
            next = head->getNext();
            while (next != NULL) {
                if ((key == next->getKey() && stringTransposition(value) > stringTransposition(next->getValue())) || stringTransposition(key) > stringTransposition(next->getKey())) {
                    next = next->getNext();
                    position++;
                } else {
                    break;
                }
            }
            this->insert_position(position, key, value);
        }
    } else {
        cout << "This element already exists" << endl;
    }
}

void List::insert_last(String key, String value) {
    Node* newNode = new Node(key, value);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

void List::remove_first() {
    if (!isEmpty()) {
        Node* newNode = new Node;
        newNode = head;
        head = head->getNext();
        delete newNode;
    }
}

void List::remove_position(int position) {
    if (position == 1) {
        this->remove_first();
    } else {
        Node* current = new Node;
        Node* previous = new Node;
        current = head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(current->getNext());
    }
}

void List::remove_last() {
    if (!isEmpty()) {
        Node* current = new Node;
        Node* previous = new Node;
        current = head;
        while (current->getNext() != NULL) {
            previous = current;
            current = current->getNext();
        }
        tail = previous;
        previous->setNext(NULL);
        delete current;
    }
}

void List::display() {
    Node* hd = head;

    if (isEmpty())
        cout << "The List is Empty!" << endl;
    else {
        while (hd) {
            cout << "[Key: " << hd->getKey() << " | Value: " << hd->getValue() << "] ";
            hd = hd->getNext();
        }
        cout << endl;
    }
}

int List::size() {
    if (isEmpty()) {
        return 0;
    }
    Node* hd = head;
    int qty = 0;

    do {
        hd = hd->getNext();
        qty++;
    } while (hd);

    return qty;
}

int List::search(String key, String value) {
    Node* hd = head;
    int position = 1;

    while (hd) {
        if (hd->getKey() == key && hd->getValue() == value) {
            return position;
        }
        hd = hd->getNext();
        position++;
    }
    return -1;
}

bool List::isEmpty() {
    return (head == NULL);
}