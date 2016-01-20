#ifndef TEAM_H
#define TEAM_H

#include "person.h"
#include "list.h"

class Team {
private:
	int teamNumber;
	QString teamName;
	Person members[3];
	int member_size;
	QString universityName;
	int acceptedQuestion;
	long enterTime, exitTime;

public:
	Team();

	/*** Functions ***/
	void getData();
	void printMembers();

	/*** Getters ***/
	int getTeamNumber() const;
	QString getTeamName() const;
	Person getMember(const int &index) const;
	QString getUniversityName() const;
	int getAcceptedQuestion() const;
	QString getEnterTime() const;
	QString getExitTime() const;

	/*** Setters ***/
	void setTeamNumber(const int&);
	void setTeamName(const QString&);
	void setMember(const Person &person, const int &i);
	void setUniversityName(const QString&);
	void setAcceptedQuestion(const int&);
	void setEnterTime(const QString &h, const QString &m);
	void setExitTime(const QString &h, const QString &m);

};

#endif // TEAM_H
