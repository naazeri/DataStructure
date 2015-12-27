#ifndef TEAM_H
#define TEAM_H

#include "person.h"
#include "list.h"

class Team {
private:
	int teamNumber;
	QString teamName;
	List<Person> *teamMembers;
	QString universityName;
	int acceptedQuestion;
	long enterTime, exitTime;

public:
	Team();
	/*** Functions ***/
	void getData();

	/*** Getters ***/
	int getTeamNumber() const;
	QString getTeamName() const;
	List<Person>* getMembers() const;
	QString getUniversityName() const;
	int getAcceptedQuestion() const;
	QString getEnterTime() const;
	QString getExitTime() const;

	/*** Setters ***/
	void setTeamNumber(const int&);
	void setTeamName(const QString&);
	void setPerson(List<Person>*);
	void setUniversityName(const QString&);
	void setAcceptedQuestion(const int&);
	void setEnterTime(const long&);
	void setExitTime(const long&);

};

#endif // TEAM_H
