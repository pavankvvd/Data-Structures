#include "genericQueue.h"

template <class T, int size>
Queue<T, size>::Queue()
{
    front = -1;
    rear = -1;
}

template <class T, int size>
Queue<T, size>::~Queue()
{
    cout << "object deleted" << endl;
}

template <class T, int size>
void Queue<T, size>::enqueue(T item)
{
    if (!isFull()) {
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear = (rear+1)%size;
        queue[rear] = item; 
        cout << "inserted :: " << item << endl;
    } else {
        cout << "queue is full " << endl;
    }
}

template <class T, int size>
void Queue<T, size>::dequeue()
{
    if (!isEmpty()) {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front +1)%size;
        }
    } else {
        cout << "queue is empty" << endl;
    }
}

template <class T, int size>
bool Queue<T,size>::isFull()
{
    if (front == (rear+1)%size) {
        return true;
    }
    return false;
}

template <class T, int size>
bool Queue<T,size>::isEmpty()
{
    if (front == -1 && rear == -1) {
        return true;
    }
    return false;
}

template <class T, int size>
void Queue<T,size>::display()
{
    int temp = front;
    while ((temp) != rear) {
        cout << queue[temp];
        temp = (temp+1)%size;
    }
    cout << queue[rear] << endl;
}

int main()
{
    Queue <int , 5> Q;
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(3);
    Q.display();
    Q.enqueue(4);
    Q.enqueue(5);
    Q.display();
    Q.enqueue(5);
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(6);
    Q.enqueue(7);
    Q.display();
    Queue <char , 4> Qch;
    Qch.enqueue('a');
    Qch.enqueue('b');
    Qch.display();
    return 0;
}
