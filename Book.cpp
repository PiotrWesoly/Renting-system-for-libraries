//
// Created by Piotr Wesoły on 13/05/2021.
//

#include "Book.h"

Book::Book(int _id, string _title, string _type) {
    id=_id;
    title=_title;
    type=_type;
}

int Book::getId() const {
    return id;
}

void Book::setId(int id) {
    Book::id = id;
}

const string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    Book::title = title;
}

const string &Book::getType() const {
    return type;
}

void Book::setType(const string &type) {
    Book::type = type;
}
