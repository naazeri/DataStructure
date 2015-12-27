#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
private:
	QString name, family;
	long birthDay;
//    int gender;
public:

	enum GENDER{ MALE=1, FEMALE=2 } gender;
	void setName(const QString&);

	QString getName() const;
	QString getFamily() const;
	QString getBirthDay() const;
	QString getGender() const;

	void setFamily(const QString&);
	void setBirthDay(const int&y, const int&m, const int&d);
	void setGender(const GENDER &gender);
//    void setGender(const int&);
};

#endif // PERSON_H
