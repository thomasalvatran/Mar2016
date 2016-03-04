#include <iostream>
#include "bqueue.h"
using namespace std;

const int VEC_SIZE = MAX_LENG + 1;

IntQueue::IntQueue()
{
    front = rear = 0;
}
bool IntQueue::isEmpty() const
{
    return (rear == front);
}
bool IntQueue::isFull() const {
    return ((rear + 1) % VEC_SIZE == front);
}
void IntQueue::Enqueue( /* in */ int newItem){
    if (isFull()){
        cout << "Array Full For "<< newItem << endl;
        return;
    }
    rear = (rear + 1) % VEC_SIZE;
    data[rear] = newItem;
}
int IntQueue::Front() const {
    return data[(front + 1) % VEC_SIZE];
}
void IntQueue::Dequeue() {
    if (isEmpty() != true)
    front = (front + 1) % VEC_SIZE;
    data[front] = -1; //fill with -1
}
int IntQueue::Rear() const {
    return data[(rear + 1) % VEC_SIZE];
}
void IntQueue::Print(){
    int count = (rear + VEC_SIZE - front) % VEC_SIZE + 1;
//    cout << count << endl;
    cout << "Queue:   ";
//    cout << "front--------- " << front << " " << rear << endl;
    for (int i = 1 ; i < count; i++)
    {
        int index = (front + i) % MAX_LENG;
        cout << data[index] << "[" << index <<"] ";
    }
    cout << endl;
}
