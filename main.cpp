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
    
//    /** Encadeamento Externo*/
//    HashTable_EncadeamentoExterno hash_EE;
//    cout << "Encadeamento Externo:" << endl; 
//    /** Insert*/
//    auto EE_Insert_start = high_resolution_clock::now();
//    for(int i = 0; i < 10000; i++) {
//        hash_EE.insert(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto EE_Insert_stop = high_resolution_clock::now();
//    auto EE_Insert_duration = duration_cast<microseconds>(EE_Insert_stop - EE_Insert_start);
//    cout << "Time taken by Insert function: " << EE_Insert_duration.count() << " microseconds" << endl;
//    /** Remove*/
//    auto EE_Remove_start = high_resolution_clock::now();
//    for(int i = 0; i < 3000; i++) {
//        hash_EE.remove_position(rand() % 30000);
//    }
//    auto EE_Remove_stop = high_resolution_clock::now();
//    auto EE_Remove_duration = duration_cast<microseconds>(EE_Remove_stop - EE_Remove_start);
//    cout << "Time taken by Remove function: " << EE_Remove_duration.count() << " microseconds" << endl;
//    /** Query*/
//    auto EE_Find_start = high_resolution_clock::now();
//    for(int i = 0; i < 100000; i++) {
//        hash_EE.find(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto EE_Find_stop = high_resolution_clock::now();
//    auto EE_Find_duration = duration_cast<microseconds>(EE_Find_stop - EE_Find_start);
//    cout << "Time taken by Find function: " << EE_Find_duration.count() << " microseconds" << endl;
//    
//    /** Encadeamento Interno*/
//    HashTable_EncadeamentoInterno hash_EI;
//    cout << "\nEncadeamento Interno:" << endl;
//    /** Insert*/
//    auto EI_Insert_start = high_resolution_clock::now();
//    for(int i = 0; i < 10000; i++) {
//        hash_EI.insert(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto EI_Insert_stop = high_resolution_clock::now();
//    auto EI_Insert_duration = duration_cast<microseconds>(EI_Insert_stop - EI_Insert_start);
//    cout << "Time taken by Insert function: " << EI_Insert_duration.count() << " microseconds" << endl;
//    /** Remove*/
//    auto EI_Remove_start = high_resolution_clock::now();
//    for(int i = 0; i < 3000; i++) {
//        hash_EI.remove_position(rand() % 30000);
//    }
//    auto EI_Remove_stop = high_resolution_clock::now();
//    auto EI_Remove_duration = duration_cast<microseconds>(EI_Remove_stop - EI_Remove_start);
//    cout << "Time taken by Remove function: " << EI_Remove_duration.count() << " microseconds" << endl;
//    /** Query*/
//    auto EI_Find_start = high_resolution_clock::now();
//    for(int i = 0; i < 100000; i++) {
//        hash_EI.find(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto EI_Find_stop = high_resolution_clock::now();
//    auto EI_Find_duration = duration_cast<microseconds>(EI_Find_stop - EI_Find_start);
//    cout << "Time taken by Find function: " << EI_Find_duration.count() << " microseconds" << endl;
    
//    /** Tentativas Lineares*/
//    HashTable_TentativasLineares hash_TL;
//    cout << "\nTentativas Lineares:" << endl;
//    /** Insert*/
//    auto TL_Insert_start = high_resolution_clock::now();
//    for(int i = 0; i < 10000; i++) {
//        hash_TL.insert(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto TL_Insert_stop = high_resolution_clock::now();
//    auto TL_Insert_duration = duration_cast<microseconds>(TL_Insert_stop - TL_Insert_start);
//    cout << "Time taken by Insert function: " << TL_Insert_duration.count() << " microseconds" << endl;
//    /** Remove*/
//    auto TL_Remove_start = high_resolution_clock::now();
//    for(int i = 0; i < 3000; i++) {
//        hash_TL.remove_position(rand() % 30000);
//    }
//    auto TL_Remove_stop = high_resolution_clock::now();
//    auto TL_Remove_duration = duration_cast<microseconds>(TL_Remove_stop - TL_Remove_start);
//    cout << "Time taken by Remove function: " << TL_Remove_duration.count() << " microseconds" << endl;
//    /** Query*/
//    auto TL_Find_start = high_resolution_clock::now();
//    for(int i = 0; i < 100000; i++) {
//        hash_TL.find(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto TL_Find_stop = high_resolution_clock::now();
//    auto TL_Find_duration = duration_cast<microseconds>(TL_Find_stop - TL_Find_start);
//    cout << "Time taken by Find function: " << TL_Find_duration.count() << " microseconds" << endl;
    
    /** Hashing Duplo*/
    HashTable_HashingDuplo hash_HD;
    cout << "\nHashing duplo:" << endl;
//    /** Insert*/
//    auto HD_Insert_start = high_resolution_clock::now();
//    for(int i = 0; i < 10000; i++) {
//        hash_HD.insert(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto HD_Insert_stop = high_resolution_clock::now();
//    auto HD_Insert_duration = duration_cast<microseconds>(HD_Insert_stop - HD_Insert_start);
//    cout << "Time taken by Insert function: " << HD_Insert_duration.count() << " microseconds" << endl;
//    /** Remove*/
//    auto HD_Remove_start = high_resolution_clock::now();
//    for(int i = 0; i < 3000; i++) {
//        hash_HD.remove_position(rand() % 30000);
//    }
//    auto HD_Remove_stop = high_resolution_clock::now();
//    auto HD_Remove_duration = duration_cast<microseconds>(HD_Remove_stop - HD_Remove_start);
//    cout << "Time taken by Remove function: " << HD_Remove_duration.count() << " microseconds" << endl;
//    /** Query*/
//    auto HD_Find_start = high_resolution_clock::now();
//    for(int i = 0; i < 100000; i++) {
//        hash_HD.find(names[randomName()], occupations[randomOccupation()]);
//    }
//    auto HD_Find_stop = high_resolution_clock::now();
//    auto HD_Find_duration = duration_cast<microseconds>(HD_Find_stop - HD_Find_start);
//    cout << "Time taken by Find function: " << HD_Find_duration.count() << " microseconds" << endl;

    return 0;

}