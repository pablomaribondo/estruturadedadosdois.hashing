#include <cstdlib>
#include <iostream>
#include "Node.cpp"

using namespace std;

class List {
private:
    Node* head;
    Node* tail;
public:

    List() {
        head = NULL;
        tail = NULL;
    }

    List(int k, int v) {
        head = new Node(k, v);
        tail = head;
    }

    virtual ~List() {
        Node *atual = head, *prox = NULL;
        while (atual != NULL) {
            prox = atual->getNext();
            delete atual;
            atual = prox;
        }
    }

    void setTail(Node* tail) {
        this->tail = tail;
    }

    Node* getTail() {
        return tail;
    }

    void setHead(Node* head) {
        this->head = head;
    }

    Node* getHead() {
        return head;
    }

    void insert_first(int k, int v) {
        Node* newNode = new Node(k, v);
        
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
    }

    void insert_position(int position, int k, int v) {
        Node* newNode = new Node(k, v);
        
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            Node* previous = new Node(k, v);
            Node* current = new Node(k, v);
            current = head;
            for (int i = 1; i < position; i++) {
                previous = current;
                current = current->getNext();
            }
            newNode->setKey(k);
            newNode->setValue(v);
            previous->setNext(newNode);
            newNode->setNext(current);
        }

    }

    void insert_sorted(int k, int v) {
        int position = 2;
        
        if (this->isEmpty() || k < head->getKey() || (k == head->getKey() && v < head->getValue())) {
            this->insert_first(k, v);
        } else {
            Node* next = new Node(k, v);
            next = head->getNext();
            while (next != NULL) {
                if ((k == next->getKey() && v > next->getValue()) || k > next->getKey()) {
                    next = next->getNext();
                    position++;
                } else {
                    break;
                }
            }
            this->insert_position(position, k, v);
        }

    }

    void insert_last(int k, int v) {
        Node* newNode = new Node(k, v);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    void remove_first() {
        if (!isEmpty()) {
            Node* newNode = new Node;
            newNode = head;
            head = head->getNext();
            delete newNode;
        }
    }

    void remove_position(int position) {
        if(position == 1) {
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

    void remove_last() {
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

    void display() {
        Node* h = head;

        if (isEmpty())
            cout << "The List is Empty!" << endl;
        else {
            while (h) {
                cout << " | Key: " << h->getKey() << " Value: " << h->getValue();
                h = h->getNext();
            }
            cout << endl;
        }
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        Node* h = head;
        int qty = 0;

        do {
            h = h->getNext();
            qty++;
        } while (h);

        return qty;
    }

    int search(int k, int v) {
        Node* h = head;
        int position = 1;

        while (h) {
            if (h->getKey() == k && h->getValue() == v) {
                return position;
            }    
            h = h->getNext();
            position++;
        }
        return -1;
    }
    
    bool isEmpty() {
        return (head == NULL);
    }

};

