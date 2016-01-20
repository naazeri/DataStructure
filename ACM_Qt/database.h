#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "team.h"

class DataBase : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QStringList teamNumber READ teamNumber WRITE setTeamNumber NOTIFY teamNumberChanged)
	Q_PROPERTY(QStringList teamName READ teamName WRITE setTeamName NOTIFY teamNameChanged)
//	Q_PROPERTY(QStringList member1Name READ member1Name WRITE setMember1Name NOTIFY member1NameChanged)
//	Q_PROPERTY(QStringList member1Family READ member1Family WRITE setMember1Family NOTIFY member1FamilyChanged)
//	Q_PROPERTY(QStringList member1birth READ member1birth WRITE setMember1birth NOTIFY member1birthChanged)
//	Q_PROPERTY(QStringList member1gender READ member1gender WRITE setMember1gender NOTIFY member1genderChanged)
//	Q_PROPERTY(QStringList member2Name READ member2Name WRITE setMember2Name NOTIFY member2NameChanged)
//	Q_PROPERTY(QStringList member2Family READ member2Family WRITE setMember2Family NOTIFY member2FamilyChanged)
//	Q_PROPERTY(QStringList member2birth READ member2birth WRITE setMember2birth NOTIFY member2birthChanged)
//	Q_PROPERTY(QStringList member2gender READ member2gender WRITE setMember2gender NOTIFY member2genderChanged)
//	Q_PROPERTY(QStringList member3Name READ member3Name WRITE setMember3Name NOTIFY member3NameChanged)
//	Q_PROPERTY(QStringList member3Family READ member3Family WRITE setMember3Family NOTIFY member3FamilyChanged)
//	Q_PROPERTY(QStringList member3birth READ member3birth WRITE setMember3birth NOTIFY member3birthChanged)
//	Q_PROPERTY(QStringList member3gender READ member3gender WRITE setMember3gender NOTIFY member3genderChanged)
//	Q_PROPERTY(QStringList uniName READ uniName WRITE setUniName NOTIFY uniNameChanged)
//	Q_PROPERTY(QStringList acceptedQuestions READ acceptedQuestions WRITE setAcceptedQuestions NOTIFY acceptedQuestionsChanged)
//	Q_PROPERTY(QStringList enterTime READ enterTime WRITE setEnterTime NOTIFY enterTimeChanged)
//	Q_PROPERTY(QStringList exitTime READ exitTime WRITE setExitTime NOTIFY exitTimeChanged)

public:
	explicit DataBase(QObject *parent = 0);

	/*** Setters ***/
	void setTeamNumber(const QStringList s);
	void setTeamName(const QStringList s);

	/*** Getters ***/
	QStringList teamNumber();
	QStringList teamName();

signals:
	void teamNumberChanged();
	void teamNameChanged();

public slots:
	void changeTeamNumber();
	void changeTeamName();

private:
	List<Team> *list;
	QStringList _teamNumber;
	QStringList _teamName;
	QStringList _member1Name;
	QStringList _member1Family;
	QStringList _member1birth;
	QStringList _member1gender;
	QStringList _member2Name;
	QStringList _member2Family;
	QStringList _member2birth;
	QStringList _member2gender;
	QStringList _member3Name;
	QStringList _member3Family;
	QStringList _member3birth;
	QStringList _member3gender;
	QStringList _uniName;
	QStringList _acceptedQuestions;
	QStringList _enterTime;
	QStringList _exitTime;

	void reloadData();
};

#endif // DATABASE_H
