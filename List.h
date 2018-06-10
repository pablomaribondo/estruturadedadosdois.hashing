#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
    const int TABLE_SIZE = 12000;
    Node* head;
    Node* tail;
public:
    List();
    List(String key, String value);
    ~List();
    void setTail(Node* tail);
    Node* getTail();
    void setHead(Node* head);
    Node* getHead();
    int stringTransposition(String key);
    void insert_first(String key, String value);
    void insert_position(int position, String key, String value);
    void insert_sorted(String key, String value);
    void insert_last(String key, String value);
    void remove_first();
    void remove_position(int position);
    void remove_last();
    void display();
    int size();
    int search(String key, String value);
    bool isEmpty();
};

#endif /* LIST_H */