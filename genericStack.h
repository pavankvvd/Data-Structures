template<class T, int maxSize>
class Stack {
private:
    T stack[maxSize];
    int top;
public:
    Stack();
    ~Stack();
    void push(T);
    void display();
    bool isEmpty();
    T pop();
};
