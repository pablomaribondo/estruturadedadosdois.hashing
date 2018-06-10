#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable_EncadeamentoExterno.h"
#include "HashTable_EncadeamentoInterno.h"
#include "HashTable_TentativasLineares.h"
#include "HashTable_HashingDuplo.h"

using namespace std;
using namespace std::chrono;

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
    
    /** Encadeamento Externo*/
    HashTable_EncadeamentoExterno hash_EE;
    /** Insert*/
    auto EE_Insert_start = high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        hash_EE.insert(names[randomName()], occupations[randomOccupation()]);
    }
    auto EE_Insert_stop = high_resolution_clock::now();
    auto EE_Insert_duration = duration_cast<microseconds>(EE_Insert_stop - EE_Insert_start);
    cout << "Time taken by Insert function: " << EE_Insert_duration.count() << " microseconds" << endl;
    /** Remove*/
    auto EE_Remove_start = high_resolution_clock::now();
    for(int i = 0; i < 3000; i++) {
        hash_EE.remove_position(rand() % 10000);
    }
    auto EE_Remove_stop = high_resolution_clock::now();
    auto EE_Remove_duration = duration_cast<microseconds>(EE_Remove_stop - EE_Remove_start);
    cout << "Time taken by Remove function: " << EE_Remove_duration.count() << " microseconds" << endl;
    /** Query*/
    auto EE_Find_start = high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        hash_EE.find(names[randomName()], occupations[randomOccupation()]);
    }
    auto EE_Find_stop = high_resolution_clock::now();
    auto EE_Find_duration = duration_cast<microseconds>(EE_Find_stop - EE_Find_start);
    cout << "Time taken by Find function: " << EE_Find_duration.count() << " microseconds" << endl;

    return 0;

}