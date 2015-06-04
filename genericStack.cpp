#include<iostream>
#include "genericStack.h"

using namespace std;

template<class T, int maxSize>
Stack<T, maxSize>::Stack()
{
    top = 0;
}

template<class T, int maxSize>
Stack<T, maxSize>::~Stack()
{
    cout << "delete" << endl;
}

template<class T, int maxSize>
void Stack<T, maxSize>::push(T x)
{
    if (isFull()) {
        cout << "stack overflow" << endl;
        return;
    }
    stack[top++] = x;
}

template<class T, int maxSize>
void Stack<T, maxSize>::display()
{
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    int temp = 0;
    cout << "stack is now :: " ;
    while(temp < top) {
        cout << stack[temp];
        temp++;
    }
    cout << endl;
}

template<class T, int maxSize>
T Stack<T, maxSize>::pop()
{
    return stack[--top];
}

template<class T, int maxSize>
bool Stack<T, maxSize>::isEmpty()
{
    if (top == 0) {
        return true;
    }
    return false;
}

template<class T, int maxSize>
bool Stack<T, maxSize>::isFull()
{
    if (top >= maxSize) {
        return true;
    }
    return false;
}

int main()
{
    Stack<char, 15> s;
    s.push('V');
    s.push('e');
    s.push('n');
    s.push('e');
    s.push('z');
    s.push('u');
    s.push('e');
    s.push('l');
    s.push('a');
    s.display();
    if (!s.isEmpty()) {
        cout << "pop ::" << s.pop() << endl;
    }
    s.display();
    if (!s.isEmpty()) {
        cout << "pop ::" << s.pop() << endl;
    }
    s.display();

    Stack<int, 20> intStack;
    intStack.push(4);
    intStack.push(3);
    intStack.push(2);
    intStack.push(1);
    intStack.display();
    while (!intStack.isEmpty()) {
        cout << "pop ::" << intStack.pop() << endl;
    }
    intStack.display();
    intStack.push(4);
    intStack.display();
    return 0;
}
