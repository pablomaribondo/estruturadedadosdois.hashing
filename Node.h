#ifndef NODE_H
#define NODE_H

typedef std::string String;

class Node {
private:
    String key;
    String value;
    Node* next;
public:

    Node();
    Node(String key, String value);
    Node(String key, String value, Node* next);
    void setNext(Node*);
    Node* getNext();
    void setValue(String value);
    String getValue();
    void setKey(String key);
    String getKey();

};

#endif /* NODE_H */