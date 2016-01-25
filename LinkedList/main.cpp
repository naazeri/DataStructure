#include <iostream>

using namespace std;

template<class T>
class List;

template<class T>
class Node {
    friend class List<T>;

private:
    T data;
    Node<T> *next; // save next node address here
public:
    Node() {
        next = nullptr;
    }

    Node(const T &data) {
        this->data = data;
        next = nullptr;
    }
};

template<class T>
class List {
private:
    Node<T> *first;

public:
    List() { first = nullptr; }

    void print() const;

    int length() const;

    bool addAfterFirst(const T &);

    bool addToLast(const T &);

    bool addToPreLast(const T &);

    bool deleteFirst(T &);

    bool deleteSecond(T &);

    bool deleteLast(T &);

    bool deleteOneBeforeLast(T &);

    bool deleteTwoBeforeLast(T &);

    void quicksort();
};

template<class T>
void List<T>::print() const {
    if (!first) {
        cout << "List is empty!\n";
        return;
    }
    auto *help = first;
    while (help) {
        cout << help->data << "  ";
        help = help->next;
    }
    cout << endl;
}

template<class T>
int List<T>::length() const {
    unsigned int counter = 0;
    auto *help = first;
    while (help) {
        ++counter;
        help = help->next;
    }
    return counter;
}

template<class T>
bool List<T>::addAfterFirst(const T &x) {
    if (!first) {
        return false;
    }
    auto *temp = new Node<T>(x);
    temp->next = first->next;
    first->next = temp;
    return true;
}

template<class T>
bool List<T>::addToLast(const T &x) {
    if (!first) {
        first = new Node<T>(x);
        return true;
    }
    auto *help = first;
    while (help->next) {
        help = help->next;
    }
    help->next = new Node<T>(x);
    return true;
}

template<class T>
bool List<T>::addToPreLast(const T &x) {
    if (!first) {
        return false;
    }
    if (!first->next) {
        auto *temp = new Node<T>(x);
        temp->next = first;
        first = temp;
        return true;
    }
    auto *help = first;
    while (help->next->next) {
        help = help->next;
    }
    auto *temp = new Node<T>(x);
    temp->next = help->next;
    help->next = temp;
    return true;
}

template<class T>
bool List<T>::deleteFirst(T &x) {
    if (!first) {
        x = (T)NULL;
        return false;
    }

    x = first->data;
    auto *help = first;
    first = first->next;
    delete help;
    return true;
}

template<class T>
bool List<T>::deleteSecond(T &x) {
    if (!first || first->next) {
        x = (T)NULL;
        return false;
    }

    x = first->next->data;
    auto *help = first->next;
    first->next = first->next->next;
    delete help;
    return true;
}

template<class T>
bool List<T>::deleteLast(T &x) {
    if (!first) {
        x = (T)NULL;
        return false;
    }
    if (!first->next) {
        x = first->data;
        delete first;
        first = nullptr;
        return true;
    }

    auto *help = first;
    while (help->next->next) {
        help = help->next;
    }

    x = help->next->data;
    delete help->next;
    help->next = nullptr;
    return true;
}

template<class T>
bool List<T>::deleteOneBeforeLast(T &x) {
    if (!first || !first->next) {
        x = (T)NULL;
        return false;
    }
    if (!first->next->next) {
        x = first->data;
        auto *help = first;
        first = first->next;
        delete help;
        return true;
    }

    auto *help = first;
    while (help->next->next->next) {
        help = help->next;
    }

    x = help->next->data;
    auto *temp = help->next;
    help->next = help->next->next;
    delete temp;
    return true;
}

template<class T>
bool List<T>::deleteTwoBeforeLast(T &x) {
    if (!first || !first->next || !first->next->next) {
        x = (T)NULL;
        return false;
    }

    if (!first->next->next->next) {
        x = first->data;
        auto *help = first;
        first = first->next;
        delete help;
        return true;
    }

    auto *help = first;
    while (help->next->next->next->next) {
        help = help->next;
    }

    x = help->next->data;
    auto *temp = help->next;
    help->next = help->next->next;
    delete temp;
    return true;
}

template<class T>
void List<T>::quicksort() {
    cout << "start sort\n";
    if (!first) {
        return;
    }

    for (Node<T> *i = first; i; i = i->next) {
        for (Node<T> *j = first; j->next; j = j->next) {
            if (j->data > j->next->data) {
                Node<T> *temp = j;
                j = j->next;
                temp->next = j->next;
                j->next = temp;

                cout << "sweap\n";
            }
        }
    }
    cout << "end sort\n";
}


int main(void) {
    const int size = 10;
    List<int> list;
    list.print();
    for (int i = size; i > 0; i--) {
        list.addToLast(i+1);
    }
    list.print();

    list.quicksort();
    list.print();

//    int temp;
//    for (int i = 0; i < size+1; i++) {
//        list.deleteLast(temp);
//        list.print();
//    }
    return 0;
}

