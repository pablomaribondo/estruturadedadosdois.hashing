#ifndef NODE_H
#define NODE_H

class Node {
private:
    int key;
    int value;
    Node* next;
public:

    Node();
    Node(int key, int value);
    void setNext(Node*);
    Node* getNext();
    void setValue(int value);
    int getValue();
    void setKey(int key);
    int getKey();

};

#endif /* NODE_H */