#pragma once

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
    const int limit;
    int size;

public:
    List() : limit(-1) {
        first = nullptr;
        size = 0;
    }

    List(const int &limit) : limit(limit) {
        first = nullptr;
        size = 0;
    }

    void printMembers();
    void printTeam();
    int length() const;
    bool addFirst(const T &);
    bool addLast(const T &);
    bool deleteFirst(T &);
    bool deleteLast(T &);
};

template<class T>
void List<T>::printTeam() {
    if (!first) {
        cout << "List is empty!\n";
        return;
    }
    auto *help = first;
    while (help) {
        const auto team = help->data;
        cout << "Team Number: " << team.getTeamNumber() << endl;
        cout << "Team Name: " << team.getTeamName() << endl;
        cout << "Team Member Info: \n";
        team.getMembers()->printMembers();
        cout << "University Name: " << team.getUniversityName() << endl;
        cout << "Accepted Questions: " << team.getAcceptedQuestion() << endl;
        cout << "Enter Time: " << team.getEnterTime() << endl;
        cout << "Exit Time: " << team.getExitTime() << endl;
        help = help->next;
    }
    cout << endl;
}

template <class T>
void List<T>::printMembers() {
    auto *help = first;
    for (int i = 1; help; ++i) {
        cout << "\tMember #" << i << " Name: " << help->data.getName() << endl;
        cout << "\tMember #" << i << " Family: " << help->data.getFamily() << endl;
        cout << "\tMember #" << i << " BirthDay: " << help->data.getBirthDay() << endl;
        cout << "\tMember #" << i << " Gender: " << help->data.getGender() << "\n\n";

        help = help->next;
    }
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
bool List<T>::addFirst(const T &x) {
    if (size != limit) {
        if (!first) {
            first = new Node<T>(x);
            ++size;
            return true;
        }

        auto temp = new Node<T>(x);
        temp->next = first;
        first = temp;
        ++size;
        return true;
    }
    cout << "can't create more than " << limit << endl;
    return false;
}

template<class T>
bool List<T>::addLast(const T &x) {
    if (size != limit) {
        if (!first) {
            first = new Node<T>(x);
            ++size;
            return true;
        }
        auto *help = first;
        while (help->next) {
            help = help->next;
        }
        help->next = new Node<T>(x);
        ++size;
        return true;
    }
    cout << "can't create more than " << limit << endl;
    return false;
}

template<class T>
bool List<T>::deleteFirst(T &x) {
    if (!first) {
        x = (T) NULL;
        return false;
    }

    x = first->data;
    auto *help = first;
    first = first->next;
    delete help;
    --size;
    return true;
}

template<class T>
bool List<T>::deleteLast(T &x) {
    if (!first) {
        x = (T) NULL;
        return false;
    }
    if (!first->next) {
        x = first->data;
        delete first;
        first = nullptr;
        --size;
        return true;
    }

    auto *help = first;
    while (help->next->next) {
        help = help->next;
    }

    x = help->next->data;
    delete help->next;
    help->next = nullptr;
    --size;
    return true;
}
