#pragma once
#include <QDebug>

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
    void printData();
    int length() const;
    bool addFirst(const T &);
    bool addLast(const T &);
    bool deleteFirst();
    bool deleteFirst(T &returnData);
    bool deleteLast();
    bool deleteLast(T &returnData);
    bool deleteById(const int &teamNumber);
    bool deleteById(T &returnData, const int &teamNumber);
    bool searchById(Node<T> *returnNode, const int &teamNumber);
    bool searchById(const int &teamNumber);
    bool searchById_prev(Node<T> *returnNode, const int &teamNumber);
};

template<class T>
void List<T>::printData() {
    if (!first) {
        qDebug() << "List is empty!";
        return;
    }
    auto *help = first;
    while (help) {
        const auto team = help->data;
        qDebug() << "Team Number: " << team.getTeamNumber() << endl;
        qDebug() << "Team Name: " << team.getTeamName() << endl;
        qDebug() << "Team Member Info: \n";
        team.getMembers()->printMembers();
        qDebug() << "University Name: " << team.getUniversityName() << endl;
        qDebug() << "Accepted Questions: " << team.getAcceptedQuestion() << endl;
        qDebug() << "Enter Time: " << team.getEnterTime() << endl;
        qDebug() << "Exit Time: " << team.getExitTime() << endl;
        help = help->next;
    }
    qDebug() << endl;
}

template<class T>
void List<T>::printMembers() {
    if (!first) {
        qDebug() << "List is empty!";
        return;
    }
    auto *help = first;
    for (int i = 1; help; ++i) {
        auto data = help->data;
        qDebug() << "\tMember #" << i << " Name: " << data.getName() << endl;
        qDebug() << "\tMember #" << i << " Family: " << data.getFamily() << endl;
        qDebug() << "\tMember #" << i << " BirthDay: " << data.getBirthDay() << endl;
        qDebug() << "\tMember #" << i << " Gender: " << data.getGender() << "\n\n";

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
    qDebug() << "can't create more!" << limit << endl;
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
    qDebug() << "can't create more!" << limit << endl;
    return false;
}

template<class T>
bool List<T>::deleteFirst() {
    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    auto *help = first;
    first = first->next;
    delete help;
    --size;
    return true;
}

template<class T>
bool List<T>::deleteFirst(T &returnData) {
    if (!first) {
        qDebug() << "List is empty!";
        returnData = (T) NULL;
        return false;
    }

    returnData = first->data;
    auto *help = first;
    first = first->next;
    delete help;
    --size;
    return true;
}

template<class T>
bool List<T>::deleteLast() {
    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }
    if (!first->next) {
        delete first;
        first = nullptr;
        --size;
        return true;
    }

    auto *help = first;
    while (help->next->next) {
        help = help->next;
    }

    delete help->next;
    help->next = nullptr;
    --size;
    return true;
}

template<class T>
bool List<T>::deleteLast(T &returnData) {
    if (!first) {
        qDebug() << "List is empty!";
        returnData = (T) NULL;
        return false;
    }
    if (!first->next) {
        returnData = first->data;
        delete first;
        first = nullptr;
        --size;
        return true;
    }

    auto *help = first;
    while (help->next->next) {
        help = help->next;
    }

    returnData = help->next->data;
    delete help->next;
    help->next = nullptr;
    --size;
    return true;
}

template<class T>
bool List<T>::deleteById(const int &teamNumber) {
    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    Node<T> *node = nullptr;
    if (!searchById_prev(node, teamNumber)) {
        qDebug() << "Can't find this team";
        return false;
    }

    auto *help = node->next;
    node->next = node->next->next;
    delete help;
    --size;

    return true;
}

template<class T>
bool List<T>::deleteById(T &returnData, const int &teamNumber) {
    returnData = (T) NULL;

    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    Node<T> *node = nullptr;
    if (!searchById_prev(node, teamNumber)) {
        qDebug() << "Can't find this team";
        return false;
    }

    returnData = node->data;
    auto *help = node->next;
    node->next = node->next->next;
    delete help;
    --size;

    return true;
}

template<class T>
bool List<T>::searchById(Node<T> *returnNode, const int &teamNumber) {
    returnNode = nullptr;

    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    auto *help = first;
    while (help) {
        if (help->data.getTeamNumber() == teamNumber) {
            returnNode = help;
            return true;
        }
        help = help->next;
    }

    return false;
}

template<class T>
bool List<T>::searchById(const int &teamNumber) {
    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    auto *help = first;
    while (help) {
        if (help->data.getTeamNumber() == teamNumber) {
            return true;
        }
        help = help->next;
    }

    return false;
}

template<class T>
bool List<T>::searchById_prev(Node<T> *returnNode, const int &teamNumber) {
    returnNode = nullptr;

    if (!first) {
        qDebug() << "List is empty!";
        return false;
    }

    if (first->data->getTeamNumber() == teamNumber) {
        returnNode = first;
        return true;
    }

    auto *help = first;
    while (help->next) {
        if (help->next->data.getTeamNumber() == teamNumber) {
            returnNode = help;
            return true;
        }
        help = help->next;
    }

    return false;
}
