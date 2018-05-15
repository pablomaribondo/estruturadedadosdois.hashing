#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
    Node* head;
    Node* tail;
public:

    List();
    List(int key, int value);
    ~List();
    void setTail(Node* tail);
    Node* getTail();
    void setHead(Node* head);
    Node* getHead();
    void insert_first(int key, int value);
    void insert_position(int position, int key, int value);
    void insert_sorted(int key, int value);
    void insert_last(int key, int value);
    void remove_first();
    void remove_position(int position);
    void remove_last();
    void display();
    int size();
    int search(int key, int value);
    bool isEmpty();

};

#endif /* LIST_H */