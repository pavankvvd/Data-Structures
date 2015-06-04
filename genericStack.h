template<class T, int maxSize>
class Stack {
private:
    T stack[maxSize];
    int top;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(T);
    void display();
    T pop();
};
