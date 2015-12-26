#include "Person.h"

void Person::setName(const std::string &name) {
    this->name = name;
}

void Person::setFamily(const std::string &family) {
    this->family = family;
}

void Person::setBirthDay(const int &y, const int &m, const int &d) {
    birthDay = 13;
}

void Person::setGender(const GENDER &gender) {
    this->gender = gender;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getFamily() const {
    return family;
}

std::string Person::getBirthDay() const {
    return "birthDay";
}

std::string Person::getGender() const {
    return (gender == MALE)? "Male":"Female";
}