#include "Team.h"

Team::Team() {
    teamMembers = nullptr;
}

int Team::getTeamNumber() const {
    return teamNumber;
}

string Team::getTeamName() const {
    return teamName;
}

List<Person>* Team::getMembers() const {
    return teamMembers;
}

string Team::getUniversityName() const {
    return universityName;
}

int Team::getAcceptedQuestion() const {
    return acceptedQuestion;
}

string Team::getEnterTime() const {
    return "";
}

string Team::getExitTime() const {
    return "";
}


void Team::setTeamNumber(const int &teamNumber) {
    this->teamNumber = teamNumber;
}

void Team::setTeamName(const string &teamName) {
    this->teamName = teamName;
}

void Team::setPerson(List<Person> *person) {
    this->teamMembers = person;
}

void Team::setUniversityName(const string &uniName) {
    this->universityName = uniName;
}

void Team::setAcceptedQuestion(const int &i) {
    this->acceptedQuestion = i;
}

void Team::setEnterTime(const long &i) {
    this->enterTime = i;
}

void Team::setExitTime(const long &i) {
    this->exitTime = i;
}

void Team::getData() {
    int temp_int;
    string temp_string;

    cout << "Enter team number: ";
    cin >> temp_int;
    cin.ignore();  // ignore '\n' char
    setTeamNumber(temp_int);

    cout << "Enter team name: ";
    getline(cin, temp_string, '\n');
    setTeamName(temp_string);

    cout << "Enter the number of team members(Max=3): ";
    int size;
    cin >> size;
    cin.ignore();
    while (size <= 0 || size > 3) {
        cout << "Invalid input!\nEnter the number of team members(Max=3): ";
        cin >> size;
        cin.ignore();
    }

    teamMembers = new List<Person>(size);
    for (int i = 1; size; --size, ++i) {
        Person p;
        cout << "Member " << i << ":\n";
        cout << "\tEnter name: ";
        getline(cin, temp_string, '\n');
        p.setName(temp_string);

        cout << "\tEnter family: ";
        getline(cin, temp_string, '\n');
        p.setFamily(temp_string);

        cout << "\tEnter birth year: ";
        int y, m, d;
        cin >> y;
        cout << "\tEnter birth month: ";
        cin >> m;
        cout << "\tEnter birth day: ";
        cin >> d;
        p.setBirthDay(y, m, d);

        cout << "\tEnter gender [1-Male 2-Female]: ";
        cin >> y;
        cin.ignore();
        p.setGender( (y == Person::MALE)? Person::MALE:Person::FEMALE );
        if (!teamMembers->addLast(p)) {
            cout << "Error in add member!\n";
            return;
        }
    }

    cout << "University name: ";
    getline(cin, temp_string, '\n');
    setUniversityName(temp_string);

    cout << "Accepted questions: ";
    cin >> temp_int;
    cin.ignore();
    setAcceptedQuestion(temp_int);

    long temp_long;
    cout << "Enter time: ";
    cin >> temp_long;
    cin.ignore();
    setEnterTime(temp_long);

    cout << "Exit time: ";
    cin >> temp_long;
    cin.ignore();
    setExitTime(temp_long);

    cout << "\n\n";
}
