//
// Created by Piotr Wesoły on 13/05/2021.
//

#include "User.h"

User::User() {
    nMec=0;
    name="";
    course="";
}

User::User(string _name, string _course, int _nMec) {
    name=_name;
    course=_course;
    nMec=_nMec;
}

User::User(const User& u) {
    name=u.name;
    course=u.course;
    nMec=u.nMec;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

const string &User::getCourse() const {
    return course;
}

void User::setCourse(const string &course) {
    User::course = course;
}

int User::getNMec() const {
    return nMec;
}

void User::setNMec(int nMec) {
    User::nMec = nMec;
}
bool User::operator<(const User &user2) const {
    if(this->getNMec() < user2.getNMec())return true;
    else return false;
}
