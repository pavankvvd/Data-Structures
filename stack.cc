#include<iostream>
using namespace std;

#define SIZE 5

class Stack
{
private:
    int stack[SIZE];
    int top;
public:
    Stack();
    void push(int);
    void display();
    void pop();
};

Stack::Stack()
{
    top = 0;
}

void
Stack::push(int x)
{
    if (top >= SIZE) {
        cout << "stack overflow" << endl;
        return;
    }
    stack[top++] = x;
}

void
Stack::display()
{
    if (top == 0) {
        cout << "Stack is empty" << endl;
        return;
    }

    int temp = 0;
    while(temp < top) {
        cout << stack[temp];
        temp++;
    }
    cout << endl;
}

void
Stack::pop()
{
    if (top == 0) {
        cout << "stack is empty" << endl;
        return;
    }
    top--;
}

int main()
{
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    return 0;
}
