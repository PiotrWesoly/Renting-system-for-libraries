#include <iostream>
#include "Book.h"
#include "User.h"
#include <map>
#include <iomanip>
#include <vector>
#include <list>


using namespace std;
void enrolStudent(vector<User>&);
vector<User> removeStudent(vector <User>);
void printUsers(vector<User> Users, map<User, vector<Book>> dataBase);
void registerBook(vector<Book> &books, int&);
void printBooks(vector<Book>);
void loan(map<User, vector<Book>> &dataBase, vector <Book> &books, vector <User> &users);
void returnBook(map<User, vector<Book>> &dataBase, vector<User> &users, vector<Book> &books);

int main() {

   // map<int, User> users;
   int id=100;
   vector<User> users;
   vector<Book> books;
   map<User, vector<Book>> dataBase;
    int choice;
    User Piotr("Piotr","Computer Science", 12345 );
    users.push_back(Piotr);
    User John("John","Marketing", 11111 );
    users.push_back(John);
    Book titanic(id, "Titanic", "NORMAL");
    id++;
    books.push_back(titanic);
    Book romeoAndJuliet(id, "Romeo and Juliet", "NORMAL");
    id++;
    books.push_back(romeoAndJuliet);
    Book hamlet(id, "Hamlet", "NORMAL");
    id++;
    books.push_back(hamlet);

    cout << "Welcome!" << endl;
    do{
        cout<<"1 – enrol student"<<endl
         <<"2 - remove student"<<endl
         <<"3 - print list of users"<<endl
         <<"4 - register new book"<<endl
         <<"5 - print list of books"<<endl
         <<"6 - loan"<<endl
         <<"7 - return"<<endl
         <<"8 - exit"<<endl;

        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
            enrolStudent(users);
            break;
            case 2:
                users = removeStudent(users);
                break;
            case 3:
                printUsers(users, dataBase);
                break;
            case 4:
                registerBook(books, id);
                break;
            case 5:
                printBooks(books);
                break;
            case 6:
                loan(dataBase, books, users);
                break;
            case 7:
                returnBook(dataBase, users, books);
            case 8:
                cout<<"\nHave a nice day!!\n";
                break;
            default:
                cout<<"Wrong key, try again\n";
                break;

        }
    }while(choice!=8);

    return 0;
}

void enrolStudent(vector<User> &users){
    string name, course;
    int nMec;

    cout<<"Enter name of the student: ";
    getline(cin, name);
    cout<<"\nEnter name of his course: ";
    getline(cin, course);
    cout<<"\nEnter his nMec: ";
    cin>>nMec;
    User tempUser(name, course, nMec);
    users.push_back(tempUser);

}

vector<User> removeStudent(vector <User> users){
    int nMec;
    cout<<"Enter ID of student you want to delete: ";
    cout<<endl;
    cin>>nMec;
    for(int i=0 ;i<users.size();i++){
        if(users.at(i).getNMec()==nMec){
            users.erase(users.begin()+i);
            break;
        }
    }
    return users;
}

void printUsers(vector<User> Users, map<User, vector<Book>> dataBase){
    std::cout <<left<<setw(15) << "Name" <<left<< setw(20) << "Course" <<left<< setw(10)<<"nMec"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for (const auto value : Users) {
        std::cout <<left<<setw(15) << value.getName() <<left<< setw(20) << value.getCourse() <<left<< setw(10)<<value.getNMec()<<endl;
        cout<<"Books loaned:"<<endl;
        for (const auto book : dataBase[value]) {
        cout<<left<<setw(15) << book.getTitle()<<endl;
        }
        cout<<"-------------------------------------------------"<<endl;
    }
}

void registerBook(vector<Book> &books, int &id){
    string title, type;

    cout<<"Enter title of the book: ";
    getline(cin, title);
//    cout<<"\nEnter type (NORMAL,CONDITIONAL)  ";
//    cin>>type;
    Book tempBook(id, title, "NORMAL");
    id++;
    books.push_back(tempBook);
}

void printBooks(vector<Book> Books){
    std::cout <<left<<setw(15) << "ID" <<left<< setw(20) << "Title" <<left<< setw(20)<<"Type"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    for (const auto value : Books) {
        std::cout <<left<<setw(15) << value.getId() << setw(20) << value.getTitle() << left<<setw(20)<<value.getType()<<endl;
    }
}

void loan(map<User, vector<Book>> &dataBase, vector <Book> &books, vector <User> &users) {
    string title;
    int nMec;
    cout << "Enter your nMec: ";
    cin >> nMec;
    User tempUser;
    for (int i = 0; i < users.size(); i++) {
        if (users.at(i).getNMec() == nMec) {
            tempUser = users.at(i);
            break;
        } else if (i == users.size()) cout << "User does not exist\n";
    }
    if (dataBase[tempUser].size() >= 3) {
        cout << "You have loaned 3 books, you cannot loan another one" << endl;
    } else {
        bookName :
        cout << "Enter the name of the book you want to loan: ";
        cin >> title;
        for (int i = 0; i < books.size(); i++) {
            if (books.at(i).getTitle() == title and books.at(i).getType() == "NORMAL") {
                dataBase[tempUser].push_back(books.at(i));
                books.at(i).setType("CONDITIONAL");
                cout << "You loaned " << title << endl;
                break;
            } else if (books.at(i).getTitle() == title and books.at(i).getType() == "CONDITIONAL") {
                cout << "Book is already loaned out" << endl;
                goto bookName;
            } else {
                cout << "Book is not in database" << endl;
                break;
            }
        }
    }
}

void returnBook(map<User, vector<Book>> &dataBase, vector<User> &users, vector<Book> &books) {
    string title;
    int nMec;
    User tempUser;
    Book tempBook(0, "", "");
    cout << "Enter your nMec: " << endl;
    cin >> nMec;
    cout << "Enter the name of the book you want to return: " << endl;
    cin >> title;
    tempBook.setTitle(title);
    for (auto &user : users) {
        if (user.getNMec() == nMec) tempUser = user;
    }

    for (int i = 0; i < dataBase[tempUser].size(); i++) {
        if (dataBase[tempUser].at(i).getTitle() == tempBook.getTitle()) {
            dataBase[tempUser].erase(dataBase[tempUser].begin() + i);
            for (int i = 0; i < books.size(); i++) {
                if (books.at(i).getTitle() == title) {
                    books.at(i).setType("NORMAL");
                    cout << "You returned a " << title << endl;
                    break;
                }
            }
        }
    }
}