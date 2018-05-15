#include <cstdlib>
#include <iostream>
#include "HashTable_EncadeamentoExterno.h"
#include "HashTable_EncadeamentoInterno.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    HashTable_EncadeamentoInterno h;
    h.insert(4, 100);
    h.insert(4, 200);
    h.insert(4, 300);
    h.insert(5, 300);
    
    
    h.displayAll();
    
    return 0;
  
}



