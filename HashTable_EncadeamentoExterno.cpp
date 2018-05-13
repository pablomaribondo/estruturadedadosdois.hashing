#include <cstdlib>
#include <iostream>
#include "List.cpp"

using namespace std;
const int TABLE_SIZE = 4;

class HashTable_EncadeamentoExterno {
private:
    List* htable;
public:

    HashTable_EncadeamentoExterno() {
        htable = new List[TABLE_SIZE];
    }

    ~HashTable_EncadeamentoExterno() {
        delete[] htable;
    }

    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int hash_val = hashFunc(key);
        htable[hash_val].insert_sorted(key, value);
    }

    void remove(int key, int value) {
        int hash_val = hashFunc(key);
        int position = htable[hash_val].search(key, value);
        if (position == -1) {
            cout << "This element does not exist!" << endl;
        } else {
            htable[hash_val].remove_position(position);
        }
    }

    int search(int key, int value) {
        int hash_val = hashFunc(key);
        int position = htable[hash_val].search(key, value);
        return position;
    }
    
    void displayAll() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Printing row number " << i+1 << ":" << endl;
            htable[i].display();
        }
    }
};

