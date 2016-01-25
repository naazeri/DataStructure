#include "team.h"
#include <QDebug>

Team::Team() {
//	members = nullptr;
	qDebug() << "Team class constractor called";
	member_size = 0;
}

int Team::getTeamNumber() const {
	return teamNumber;
}

QString Team::getTeamName() const {
	return teamName;
}

Person Team::getMember(const int &i) const {
	return members[i];
}

int Team::getMemberSize() const
{
	return member_size;
}

QString Team::getUniversityName() const {
	return universityName;
}

int Team::getAcceptedQuestion() const {
	return acceptedQuestion;
}

long Team::getEnterTime() const {
	return enterTime;
}

long Team::getExitTime() const {
	return exitTime;
}

void Team::setTeamNumber(const int &teamNumber) {
	this->teamNumber = teamNumber;
}

void Team::setTeamName(const QString &teamName) {
	this->teamName = teamName;
}

void Team::setMember(const Person &person, const int &i) {
	if (member_size >= 3) {
		qDebug() << "Can't add more 3 member!";
		return;
	}
	if (i < 3) {
		members[i] = person;
		++member_size;
	} else {
		qDebug() << "Error, Invalid member index";
	}
}
void Team::setUniversityName(const QString &uniName) {
	this->universityName = uniName;
}

void Team::setAcceptedQuestion(const int &i) {
	this->acceptedQuestion = i;
}

void Team::setEnterTime(const QString &h, const QString &m) {
//	this->enterTime = i;
}

void Team::setExitTime(const QString &h, const QString &m) {
//	this->exitTime = h;
}

void Team::printMembers() {
	qDebug() << "I want to Print members... @@@";
	for (int i = 0; i < member_size; ++i) {
		qDebug() << QString("Member #%1:").arg(i+1);
		qDebug() << "    Name" << members[i].getName();
		qDebug() << "    Family" << members[i].getFamily();
		qDebug() << "    BirthDay:" << members[i].getBirthDay();
		qDebug() << "    Gender:" << members[i].getGender();
	}
}

void Team::getData() {
//	int temp_int;
//	QString temp_string;

//	cout << "Enter team number: ";
//	cin >> temp_int;
//	cin.ignore();  // ignore '\n' char
//	setTeamNumber(temp_int);

//	cout << "Enter team name: ";
//	getline(cin, temp_string, '\n');
//	setTeamName(temp_string);

//	cout << "Enter the number of team members(Max=3): ";
//	int size;
//	cin >> size;
//	cin.ignore();
//	while (size <= 0 || size > 3) {
//		cout << "Invalid input!\nEnter the number of team members(Max=3): ";
//		cin >> size;
//		cin.ignore();
//	}

//	teamMembers = new List<Person>(size);
//	for (int i = 1; size; --size, ++i) {
//		Person p;
//		cout << "Member " << i << ":\n";
//		cout << "\tEnter name: ";
//		getline(cin, temp_string, '\n');
//		p.setName(temp_string);

//		cout << "\tEnter family: ";
//		getline(cin, temp_string, '\n');
//		p.setFamily(temp_string);

//		cout << "\tEnter birth year: ";
//		int y, m, d;
//		cin >> y;
//		cout << "\tEnter birth month: ";
//		cin >> m;
//		cout << "\tEnter birth day: ";
//		cin >> d;
//		p.setBirthDay(y, m, d);

//		cout << "\tEnter gender [1-Male 2-Female]: ";
//		cin >> y;
//		cin.ignore();
//		p.setGender( (y == Person::MALE)? Person::MALE:Person::FEMALE );
//		if (!teamMembers->addLast(p)) {
//			cout << "Error in add member!\n";
//			return;
//		}
//	}

//	cout << "University name: ";
//	getline(cin, temp_string, '\n');
//	setUniversityName(temp_string);

//	cout << "Accepted questions: ";
//	cin >> temp_int;
//	cin.ignore();
//	setAcceptedQuestion(temp_int);

//	long temp_long;
//	cout << "Enter time: ";
//	cin >> temp_long;
//	cin.ignore();
//	setEnterTime(temp_long);

//	cout << "Exit time: ";
//	cin >> temp_long;
//	cin.ignore();
//	setExitTime(temp_long);

//	cout << "\n\n";
}
