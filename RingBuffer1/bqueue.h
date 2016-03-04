#ifndef BQUEUE_H
#define BQUEUE_H


//class bqueue
//{
//public:
//    bqueue();
//    ~bqueue();
//};
#include <stdbool.h>
const int MAX_LENG = 10;

class IntQueue {
public:
  bool isEmpty() const;
  bool isFull() const;
  void Enqueue(/* in */ int newItem);
  int Front() const;
  int Rear() const;
  void Dequeue();
  void Print();
  IntQueue();

private:
  int data[MAX_LENG + 1];
  int front;
  int rear;
};
#endif // BQUEUE_H
