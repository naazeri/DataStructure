#pragma once
#include <QDebug>
#include <QList>

using namespace std;

template<class T> class List;

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

	int length() const;

	/*** Show ***/
	T showByID(const int &teamNumber);
	void showAllTeam();
//	void printMembers();

	/*** Setter ***/
	bool setNode(const int &teamNumber, const T &data);
	bool setAcceptedQuestion(const int &teamNumber, const int &acceptedQuestion);

	/*** Getter ***/
	bool getNode(Node<T> *returnNode, const int &teamNumber);
	bool get(T &returnData, const int &teamNumber);
	bool getAll(QList<T> &returnData);

	/*** Add ***/
	bool addFirst(const T &data);
	bool addLast(const T &data);

	/*** Delete ***/
	bool deleteFirst();
	bool deleteFirst(T &returnData);
	bool deleteLast(T &returnData);
	bool deleteLast();
	bool deleteById(const int &teamNumber);
	bool deleteById(T &returnData, const int &teamNumber);

	/*** Search ***/
	bool searchById(const int &teamNumber);
	bool searchById(Node<T> *returnNode, const int &teamNumber);
	bool searchById_prev(Node<T> *returnNode, const int &teamNumber);

	/*** Calculate ***/
	bool calculateWinner(QList<T> &returnData);
	bool getOlderPerson(QList<T> &returnData);
	bool calculateFirstExitTeam(QList<T> &returnData);

	/*** Sort ***/
	bool sortByAcceptedQuestion();
};

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
void List<T>::showAllTeam() {
	if (!first) {
		qDebug() << "List is empty!";
		return;
	}

	auto *help = first;
	while (help) {
		auto team = help->data;
		qDebug() << "Team Number: " << team.getTeamNumber();
		qDebug() << "Team Name: " << team.getTeamName();
        qDebug() << "Team Member Info:";
		team.printMembers();
		qDebug() << "University Name: " << team.getUniversityName();
		qDebug() << "Accepted Questions: " << team.getAcceptedQuestion();
		qDebug() << "Enter Time: " << team.getEnterTime();
		qDebug() << "Exit Time: " << team.getExitTime() << "\n\n";
		help = help->next;
	}
}

template<class T>
T List<T>::showByID(const int &teamNumber) {
	if (!first) {
		qDebug() << "List is empty!";
		return (T) NULL;
	}

	Node<T> *team = nullptr;

	if (!searchById(team, teamNumber)) {
		return (T) NULL;
	}
	const auto data = team->data;
	qDebug() << "Team Number: " << data.getTeamNumber();
	qDebug() << "Team Name: " << data.getTeamName();
	qDebug() << "Team Member Info:";
	team.getMembers()->printMembers();
	qDebug() << "University Name: " << data.getUniversityName();
	qDebug() << "Accepted Questions: " << data.getAcceptedQuestion();
	qDebug() << "Enter Time: " << data.getEnterTime();
	qDebug() << "Exit Time: " << data.getExitTime();
	qDebug() << "\n";

	return data->data;
}

//template<class T>
//void List<T>::printMembers() {
//	qDebug() << "function call";
//	qDebug() << "-1";
//	if (!this->first) {
//		qDebug() << "List is empty!";
//		return;
//	}
//	qDebug() << "0";
//	auto *help = first;
//	qDebug() << "1";
//	for (int i = 1; help; ++i) {
//		qDebug() << "2";
//		auto data = help->data;
//		qDebug() << "3";
//		qDebug() << "\tMember #" << i << " Name: " << data.getName() << endl;
//		qDebug() << "\tMember #" << i << " Family: " << data.getFamily() << endl;
//		qDebug() << "\tMember #" << i << " BirthDay: " << data.getBirthDay() << endl;
//		qDebug() << "\tMember #" << i << " Gender: " << data.getGender() << "\n\n";

//		help = help->next;
//	}
//}

template<class T>
bool List<T>::setNode(const int &teamNumber, const T &data) {
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	Node<T> *node = nullptr;
	if (!searchById(node, teamNumber)) {
		return false;
	}

	node->data = data;
	return true;
}

template<class T>
bool List<T>::setAcceptedQuestion(const int &teamNumber, const int &acceptedQuestion) {
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	Node<T> *node = nullptr;
	if (!searchById(node, teamNumber)) {
		return false;
	}

	node->data.setAcceptedQuestion(acceptedQuestion);
	return true;
}

template<class T>
bool List<T>::getNode(Node<T> *returnNode, const int &teamNumber) {
	returnNode = nullptr;
	return searchById(returnNode, teamNumber);
}

template<class T>
bool List<T>::get(T &returnData, const int &teamNumber) {
	Node<T> *node;
	const bool resualt = searchById(node, teamNumber);
	returnData = node->data;
	return resualt;
}

template<class T>
bool List<T>::getAll(QList<T> &returnData) {
	returnData.clear();
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	auto *help = first;
	while (help) {
		returnData.push_back(help->data);
		help = help->next;
	}
	return returnData.size() > 0;
}

template<class T>
bool List<T>::addFirst(const T &x) {
	if (!first) {
		first = new Node<T>(x);
		return true;
	}

	auto temp = new Node<T>(x);
	temp->next = first;
	first = temp;
	return true;
}

template<class T>
bool List<T>::addLast(const T &x) {
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
bool List<T>::deleteFirst() {
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	auto *help = first;
	first = first->next;
	delete help;
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
		return true;
	}

	auto *help = first;
	while (help->next->next) {
		help = help->next;
	}

	delete help->next;
	help->next = nullptr;
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
		return true;
	}

	auto *help = first;
	while (help->next->next) {
		help = help->next;
	}

	returnData = help->next->data;
	delete help->next;
	help->next = nullptr;
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

template<class T>
bool List<T>::calculateWinner(QList<T> &returnData) {
	returnData.clear();
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	int topScore = 0;
	auto *help = first;
	while (help) {
		const int score = help->data.getAcceptedQuestion();
		if (score > topScore) {
//			returnData = help->data;
			returnData.clear();
			returnData.push_back(help->data);
			topScore = score;
		} else if (score == topScore) {
			returnData.push_back(help->data);
		}
		help = help->next;
	}

	return topScore > 0;
}

template<class T>
bool List<T>::getOlderPerson(QList<T> &returnData) {
	returnData.clear();
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	long maxAge = 0;
	auto *help = first;
	while (help) {
		const int memberSize = help->data.getMemberSize();
		for (int i = 0; i < memberSize; ++i) {
			const long age = help->data.getMembers(i).getBirthDay();
			if (age > maxAge) {
				returnData.clear();
				returnData.push_back(help->data);
				maxAge = age;
			} else if (age == maxAge) {
				returnData.push_back(help->data);
			}
		}
		help = help->next;
	}

	return maxAge > 0;
}

template<class T>
bool List<T>::calculateFirstExitTeam(QList<T> &returnData) {
	returnData.clear();
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	auto *help = first;
	long minTime = first->data.getExitTime() - first->data.getEnterTime();
	while (help) {
		const long time = help->data.getExitTime() - help->data.getEnterTime();
		if (time < minTime) {
			returnData.clear();
			returnData.push_back(help->data);
			minTime = time;
		} else if (time == minTime) {
			returnData.push_back(help->data);
		}
		help = help->next;
	}

	return returnData.size() > 0;
}

template<class T>
bool List<T>::sortByAcceptedQuestion() {
	if (!first) {
		qDebug() << "List is empty!";
		return false;
	}

	for (Node *i = first; i; i = i->next) {
		for (Node *j = i->next; j; j->next = j->next) {
			if (i->data.getAcceptedQuestion() < j->data.getAcceptedQuestion()) {
				Node *temp = i;
				i = j;
				j = temp;
			}
		}
	}

	return true;
}
