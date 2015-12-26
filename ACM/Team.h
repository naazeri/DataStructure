#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "List.h"

class Team {
private:
    int teamNumber;
    string teamName;
    List<Person> *teamMembers;
    string universityName;
    int acceptedQuestion;
    long enterTime, exitTime;

public:
    Team();
    /*** Functions ***/
    void getData();

    /*** Getters ***/
    int getTeamNumber() const;
    string getTeamName() const;
    List<Person>* getMembers() const;
    string getUniversityName() const;
    int getAcceptedQuestion() const;
    string getEnterTime() const;
    string getExitTime() const;

    /*** Setters ***/
    void setTeamNumber(const int&);
    void setTeamName(const string&);
    void setPerson(List<Person>*);
    void setUniversityName(const string&);
    void setAcceptedQuestion(const int&);
    void setEnterTime(const long&);
    void setExitTime(const long&);

};


