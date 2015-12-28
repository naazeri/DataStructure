#pragma once
#include <iostream>

class Person {
private:
    std::string name, family;
    long birthDay;
//    int gender;
public:

    enum GENDER{ MALE=1, FEMALE=2 } gender;
    void setName(const std::string&);

    std::string getName() const;
    std::string getFamily() const;
    std::string getBirthDay() const;
    std::string getGender() const;

    void setFamily(const std::string&);
    void setBirthDay(const int&y, const int&m, const int&d);
    void setGender(const GENDER &gender);
//    void setGender(const int&);
};


