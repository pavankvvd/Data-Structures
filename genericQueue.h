#include "headers.h"

template <class T, int size>
class Queue
{
private:
    int front;
    int rear;
    T queue[size];
public:
    Queue();
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(T);
    void dequeue();
    void display();
};
