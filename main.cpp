#include <cstdlib>
#include <iostream>
#include <fstream>
#include "HashTable_EncadeamentoExterno.h"
#include "HashTable_EncadeamentoInterno.h"
#include "HashTable_TentativasLineares.h"
#include "HashTable_HashingDuplo.h"

using namespace std;

int randomName() {
    return rand() % 2755;
}
int randomOccupation() {
    return rand() % 316;
}

int main(int argc, char *argv[]) {

    /** Import names from file*/
    string name;
    string names [2755];
    ifstream infile_name;
    infile_name.open("names.txt");
    int i = 0;
    while (!infile_name.eof()) {
        getline(infile_name, name);
        names[i++] = name;
    }
    infile_name.clear();
    infile_name.close();
    /** Import occupations from file*/
    string occupation;
    string occupations [316];
    ifstream infile_occupation;
    infile_occupation.open("occupations.txt");
    int j = 0;
    while (!infile_occupation.eof()) {
        getline(infile_occupation, occupation);
        occupations[j++] = occupation;
    }
    infile_occupation.close();
    
    HashTable_EncadeamentoExterno hash_EE;
    for(int i = 0; i < 1000; i++) {
        hash_EE.insert(names[randomName()], occupations[randomOccupation()]);
    }
    
    

    return 0;

}