#ifndef HASH_H
#define HASH_H


#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


class Hash {
private:                             //modify hash function by tableSize
    static const int tableSize = 40; //40 indexes or 40 buckets bigger less collision
    struct Item{
        string ipaddress;
        int hop_count;
        int distance;
        Item* next;
    };

    Item *HashTable[tableSize];  //index of hash table is bucket 10 buckets

public:
    Hash();
    int hash(string key);
    void AddItem(string ipaddress, int distance, int hop_count);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void findHopCount(string ipaddress);
    void removeItem(string ipaddress);
    void Test();
};


void functionTest(Hash hash, int n);
#endif // HASH_H
