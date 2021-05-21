//
// Created by Piotr Wesoły on 13/05/2021.
//

#ifndef INC_08_EXERCICE_BOOK_H
#define INC_08_EXERCICE_BOOK_H
#include <string>

using namespace std;

class Book {
private:
    int id;
    string title;
    string type;
    //static int* bookID;

public:
    Book(int _id,string _title,string _type);
    int getId() const;
    void setId(int id);
    const string &getTitle() const;
    void setTitle(const string &title);
    const string &getType() const;
    void setType(const string &type);
};


#endif //INC_08_EXERCICE_BOOK_H
