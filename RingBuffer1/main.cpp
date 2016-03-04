//Mark book
#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include "bqueue.h"
using namespace std;

int main(int argc, char *argv[]) {

//  IntQueue Q; //in stack
  cout << "RingBuffer1 Circulate array (RingBuffer)" << endl;
  IntQueue *array = new IntQueue; //heap
  cout << array->Front() << " " << array->Rear() << endl;
  //      array->Enqueue(22);
  //      array->Enqueue(23);
  for (int i = 0; i < 10; i++) {
    array->Enqueue(i + 10);
  }
  array->Print();
  cout << "front =" << array->Front() << ", rear = " << array->Rear() << endl;
  //  array->Dequeue();
  array->Dequeue();
  array->Dequeue();
//  array->Dequeue();
  array->Enqueue(669);
  array->Enqueue(677);
  array->Enqueue(688);
  array->Print();

  cout << "front =" << array->Front() << ", rear = " << array->Rear() << endl;
  while (array->isEmpty() == 0) {
    array->Dequeue();
  }

  cout << "queue front is " << array->Front() << endl;
  printf("Queue is %s\n", array->isEmpty() ? "empty " : "not empty ");
  array->Enqueue(222);
  array->Enqueue(223);
  cout << "queue front is " << array->Front() << endl;
  printf("Queue is %s\n", array->isEmpty() ? "empty " : "not empty ");
  array->Print();
}
