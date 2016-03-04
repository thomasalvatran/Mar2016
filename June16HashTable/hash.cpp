/*
 * Hash.cpp
 *
 *  Created on: June 16, 2015
 *      Author: tv
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include "hash.h"
using namespace std;

Hash::Hash() // initialize constructor
{
  cout << "Ctor" << endl;
  for (int i = 0; i < tableSize; i++) {
    HashTable[i] = new Item;
    HashTable[i]->ipaddress = "empty";
    HashTable[i]->hop_count = 0;
    HashTable[i]->distance = 0;
    HashTable[i]->next = NULL;
  }
}
void Hash::AddItem(string ipaddress, int hop_count, int distance) {
  int index = hash(ipaddress); //run hash function
  if (HashTable[index]->ipaddress == "empty") {
    HashTable[index]->ipaddress = ipaddress;
    HashTable[index]->distance = distance;
    HashTable[index]->hop_count = hop_count;
    HashTable[index]->next = NULL;
  } else {                      // collision find all elements in linked list
    Item *Ptr = HashTable[index]; // Point to 1st item of bucket
    Item *n = new Item;
    n->ipaddress = ipaddress;
    n->distance = distance;
    n->hop_count = hop_count;
    n->next = NULL;
    while (Ptr->next != NULL) {
      Ptr = Ptr->next; // find the last item and add at the end linkedlist
    }
    Ptr->next = n;
    // link to the new node just creted n and it has p->next = NULL
  }
}
int Hash::NumberOfItemsInIndex(int index) { // index of that bucket
  int count = 0;
  if (HashTable[index]->ipaddress == "empty") {
    return count;
  } else {
    count++;
    Item *ptr = HashTable[index]; //1st item in the bucket
    while (ptr->next != NULL) {
      count++;
      ptr = ptr->next;
    }
  }
  return count;
}
void Hash::PrintTable() {
  int number = 0;
  cout << "----PrintTable----------\n";
  for (int i = 0; i < tableSize; i++) {
      number = 1;
 //      number = NumberOfItemsInIndex(i); // take long to search linkedlist in bucket
       cout << "index = " << i << endl;
       cout << HashTable[i]->ipaddress << " hop_cnt : ";
       cout << HashTable[i]->hop_count << " distance: ";
       cout << HashTable[i]->distance << " - ";
       cout << "# of items = " << number << endl;
 //      number--;

    while (HashTable[i]->next != NULL)

//     while (number > 0) // numbers items in linked list
     {
       cout << "index = " << i << endl;
       cout << HashTable[i]->ipaddress << " hop_cnt : ";
       cout << HashTable[i]->hop_count << " distance: ";
       cout << HashTable[i]->distance << " - ";
       number++;
       cout << "# of items = " << number << endl;
       cout << "Next = " << HashTable[i]->next << endl;
       HashTable[i] = HashTable[i]->next;
     }
    cout << "------------------\n";
  }
}
void Hash::PrintItemsInIndex(int index) {
  Item *Ptr = HashTable[index];
  if (Ptr->ipaddress == "empty") {
    cout << "index = " << index << " is empty" << endl;
    cout << "------------\n";
  } else {
    cout << "index = " << index << " contains the following items:\n";
    while (Ptr != NULL) {
      //      cout << "------------\n";
      cout << Ptr->ipaddress << " hop count = ";
      cout << Ptr->hop_count << " distance = ";
      cout << Ptr->distance;
      cout << "\n"
           << "------------\n";
      Ptr = Ptr->next;
    }
  }
}
int Hash::hash(string key) { // hash function create index
  int hash = 0;
  int index;

  for (int i = 0; i < key.length(); i++) {
    hash = (hash + (int)key[i]) ;   // * 2 and hash tableSize ->collision
    // hash = (hash) + (int)key[i]; //modify hash function for index
  }

  index = hash % tableSize;   //index = bucket

  return index;
}
void Hash::findHopCount(string ipaddress) {
  int index = hash(ipaddress); //hash function to get index/bucket
  cout << "Using Hash function -->"<< " ipaddress = " << HashTable[index]->ipaddress << " "
       << "hop count = " << HashTable[index]->hop_count << " "
       << "distance = " << HashTable[index]->distance  << " "
       << endl;
  bool found = false;
  int i = 0, j;
  Item ip[tableSize]; // create in stack just for this function if using outside
  //  Item *ip[tableSize]; //*ip has new allocate in the heap because it is
  //  pointer

  Item *ptr = HashTable[index];
  cout << "index = " << index << endl;

  while (ptr != NULL) {
    if (ptr->ipaddress == ipaddress) {
      //      if (ipaddress.compare(ptr->ipaddress) == 0){
      found = true;
      //      ip[i] = new Item; // pointer needs point to something otherwise
      //      segment fault
      ip[i].ipaddress = ptr->ipaddress;
      ip[i].hop_count = ptr->hop_count;
      ip[i].distance = ptr->distance;
      i++;
    }
    ptr = ptr->next;
  }
  if (found == true)
    for (j = 0; j < i; j++) {
      cout << "Using iterating throught list takes longer -->" << endl;
      cout << "ipaddress = " << setw(15) << ip[j].ipaddress << endl;
      cout << "hop count = " << setw(15) << ip[j].hop_count << endl;
      cout << "distance  = " << setw(15) << ip[j].distance << endl;
    }
  else
    cout << " Hop count is not found in hash table" << endl;
}

void Hash::removeItem(string ipaddress) {
  int index = hash(ipaddress);  //run hash function
  Item *delPtr;
  Item *p1;
  Item *p2;

  if (HashTable[index]->ipaddress == "empty")
    cout << ipaddress << " was not found in hash table " << endl;
  // case 1 match name and only 1 item in the bucket
  else if (HashTable[index]->ipaddress == ipaddress &&
           HashTable[index]->next == NULL) {
    HashTable[index]->ipaddress = "empty";
    HashTable[index]->hop_count = NULL; // leave bucket in stack HashTable
    cout << ipaddress << " was removed from hash table " << endl;
  }
  // case 2 - match is located in the 1st time in the bucket but thre are more
  // items in the bucket.
  else if (HashTable[index]->ipaddress == ipaddress) {
    delPtr = HashTable[index];
    HashTable[index] = HashTable[index]->next;
    delete delPtr; // release memory it is a part of linked list
    cout << ipaddress << " was removed from hash table " << endl;
  }
  // case 3 - bucket contains items but 1st item is not a match
  // case 3.1 no match
  // case 3.2 match is found
  else {
    p1 = HashTable[index]->next;
    p2 = HashTable[index];
    while (p1 != NULL && p1->ipaddress != ipaddress) { // 2 conditions
      p2 = p1;
      p1 = p1->next;
    }
    if (p1 == NULL) { // 1st condition
      cout << ipaddress << " was not found in hash table" << endl;
    } else { // 2nd condition
      delPtr = p1;
      p1 = p1->next;
      p2->next = p1;
      delete delPtr; // release memory it is a part of linked list
      cout << ipaddress << " was removed from hash table " << endl;
    }
  }
}
void functionTest(Hash hash, int n) { // function pointer as argument
  // void functionTest( Hash *func(string str)) {
  string ipaddress;
  if (n == 0) { //find ip
    while (ipaddress != "empty") {
        cout << "Search for hop count of ip address (type exit to exit): ";
        cin >> ipaddress;
      if (ipaddress != "exit")
        hash.findHopCount(ipaddress);
      else
        break;
    }
  } else { //remove ip
    while (ipaddress != "empty") {
        cout << "Remove ipaddress in hash table (type exit to exit): ";
        cin >> ipaddress;
      if (ipaddress != "exit"){
        hash.removeItem(ipaddress);
        hash.PrintTable();
      }
      else
        break;
    }
  }
}

void Hash::Test() {
  Item *temp = new Item;
  temp->ipaddress = "192.168.0.1";
  temp->distance = 1;
  temp->hop_count = 100;
  temp->next = NULL;

  int index = hash("192.168.0.1");
  cout << "index =" << index << endl;
  if (HashTable[index]->ipaddress == "empty") {
    HashTable[1]->ipaddress = "192.168.0.1";
    HashTable[1]->distance = 1;
    HashTable[1]->hop_count = 100;
  } else {

    Item *Ptr = HashTable[0];

    Item *n = new Item;
    n->ipaddress = "192.168.0.1";
    n->distance = 1;
    n->hop_count = 100;
    n->next = NULL;
    cout << "Ptr " << Ptr->ipaddress << endl;
    for (int i = 0; i < 10; i++) {
      cout << "Hashtable " << HashTable[i]->ipaddress << endl;
      if (HashTable[i]->ipaddress == "empty")
        HashTable[i] = n;
    }

    //    		while(Ptr->name != "empty")
    //    		{
    //    			Ptr = Ptr->next;
    //    			cout << "Ptr->name" << Ptr->name  << endl;
    //    			cout <<"TTTTT"<<endl;
    //    		}
    cout << "Ptr" << Ptr->ipaddress << endl;
    // Ptr->next = n;
  }
  // cout << "insert index 1 name =" <<  temp->name << endl;
}
