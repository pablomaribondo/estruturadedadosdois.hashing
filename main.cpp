#include <cstdlib>
#include <iostream>
#include "HashTable_EncadeamentoExterno.h"
#include "HashTable_EncadeamentoInterno.h"
#include "HashTable_TentativasLineares.h"
#include "HashTable_HashingDuplo.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    HashTable_HashingDuplo h;
    h.insert(10, 100);
    h.insert(18, 200);
    h.insert(26, 300);
    h.insert(2, 300);
    h.insert(6, 300);
    h.insert(36, 300);
    h.insert(22, 300);
    h.insert(6, 200);
    
    h.displayAll();
    
    return 0;
  
}



