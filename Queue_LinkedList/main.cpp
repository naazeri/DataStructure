#include <iostream>

using namespace std;

template <class T> class Queue;

template <class T>
class Node {
    friend class Queue<T>;
private:
    T data;
    Node<T> *next;

public:
    Node() {
        this->next = nullptr;
    }
    Node(const T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Queue {
public :
    Queue();
    ~Queue();
    bool enqueue(const T);
    bool dequeue();
    bool dequeue(T&);
    void print() const;

private:
    Node<T> *rear, *front;
};

template <class T>
Queue<T>::Queue() {
    this->front = this->rear = nullptr;
}

template <class T>
Queue<T>::~Queue() {
    delete front;
    delete rear;
}

template <class T>
bool Queue<T>::enqueue(const T data) {
    auto *temp = new Node<T>(data);
    if (!temp) {
        return false;
    }

    if (!front) {
        front = rear = temp;  // list is empty
    } else {
        rear->next = temp;  // make link
        rear = temp;  // point to end of list
    }

    return true;
}

template <class T>
bool Queue<T>::dequeue() {
    if (!front) {
        cout << "List is empty!\n";
        return false;
    }

    auto *const temp = front;
    front = front->next;
    delete temp;
    return true;
}

template <class T>
bool Queue<T>::dequeue(T &data) {
    if (!front) {
        cout << "List is empty!\n";
        data = nullptr;
        return false;
    }

    data = front->data;
    auto *const temp = front;
    front = front->next;
    delete temp;
    return true;
}

template <class T>
void Queue<T>::print() const {
    if (!front) {
        cout << "List is empty!\n";
    }
    else {
        auto *help = front;
        while (help) {
            cout << help->data << "  ";
            help = help->next;
        }
        cout << endl;
    }
}

int main(void) {
    const int size = 10;
    Queue<double> queue;

    queue.print();
    for (int i = 0; i < size; ++i) {
        const auto temp = i + 1.5;
        queue.enqueue(temp);
        queue.print();
    }
    for (int i = 0; i < size+1; ++i) {
        queue.dequeue();
        queue.print();
    }
    return 0;
}
