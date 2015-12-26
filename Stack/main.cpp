#include <iostream>
using namespace std;

template<class T>
class MyStack {
private:
    const int size;
    int top;
    T *s;

public:
    MyStack(const int&);
    ~MyStack();
    bool push(const T&);
    bool pop(T&);
    bool pop();
    T Top() const;
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
};

template <class T>
MyStack<T>::MyStack(const int &size) : size(size) {
    this->s = new T[size];
    this->top = -1;
}

template <class T>
MyStack<T>::~MyStack() {
    delete[] s;
}

template <class T>
bool MyStack<T>::push(const T &item) {
    if (isFull()) {
        cout << "List is full!\n";
        return false;
    }
    s[++top] = item;
    return true;
}

template <class T>
bool MyStack<T>::pop() {
    if (isEmpty()) {
        cout << "List is empty!\n";
        return false;
    }
    --top;
    return true;
}

template <class T>
bool MyStack<T>::pop(T &item) {
    if (isEmpty()) {
        cout << "List is empty!\n";
        return false;
    }
    item = Top();
    --top;
    return true;
}

template <class T>
T MyStack<T>::Top() const {
    return (isEmpty())? (T)NULL:s[top];
}

template <class T>
bool MyStack<T>::isFull() const {
    return top == size-1;
}

template <class T>
bool MyStack<T>::isEmpty() const {
    return top == -1;
}

template <class T>
void MyStack<T>::print() const {
    if (isEmpty()) {
        cout << "List is empty!\n";
    }
    else {
        for (int i = 0; i <= top; ++i) {
            cout << s[i] << "  ";
        }
        cout << endl;
    }
}

int main() {
    const int size = 10;
    MyStack<int> stack(size);

    stack.print();

    for (int i = 0; i < size+1; ++i) {
        stack.push(i+1);
        stack.print();
    }

    for (int i = 0; i < size+1; ++i) {
        stack.pop();
        stack.print();
    }

    return 0;
}