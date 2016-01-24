#pragma once
#include <QString>
#include <QDebug>

class Person {
public:
//	static int size;
//	static Person* new_instance() {
//		if (size >= 3) {
//			qDebug() << "I don't call Constructor. You have" << size << "member!\n";
//			return nullptr;
//		}
//		size++;
//		return new Person();
//	}
	Person(){}

    enum GENDER{ MALE, FEMALE };

	/*** Get ***/
	QString getName() const;
	QString getFamily() const;
	long getBirthDay() const;
	QString getGender() const;

	/*** Set ***/
	void setName(const QString&);
	void setFamily(const QString&);
	void setBirthDay(const QString&y, const QString&m, const QString&d);
	void setGender(const GENDER gender);

private:
	QString name, family;
	long birthDay;
	GENDER gender;
};
