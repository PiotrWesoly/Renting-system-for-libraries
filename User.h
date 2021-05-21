//
// Created by Piotr Wesoły on 13/05/2021.
//

#ifndef INC_08_EXERCICE_USER_H
#define INC_08_EXERCICE_USER_H
#include <string>

using namespace std;

class User {
private:
    string name;
    string course;
    int nMec;
public:
    User();
    User(string _name, string _course, int _nMec);
    User(const User& u);
    const string &getName() const;
    void setName(const string &name);
    const string &getCourse() const;
    void setCourse(const string &course);
    int getNMec() const;
    void setNMec(int nMec);
    bool operator <(const User& user2) const;

};



#endif //INC_08_EXERCICE_USER_H
