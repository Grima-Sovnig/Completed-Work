//CLASS SPECIFICATION FILE for the Book Class
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

//this is the Book class declaration
class Book
{
    private:
        //attributes (data members)
        int numPages;
        string bookTitle;
        float price;

    public:
        //default constructor
        Book()
        {
            cout << "\nHello!  I am in the constructor!\n";
        }

        //overloaded constructor
        Book(int pages, string title, float price)
        {
            cout << "\nI am in the overloaded constructor.\n";
            this->numPages = pages;
            this->bookTitle = title;
            this->price = price;
        }

        //destructor
        ~Book()
        {
            cout << "\nGoodbye!  This is the destructor talking!\n";
        }

        //mutator (or setter) functions
        void setNumPages(int);
        void setBookTitle(string);
        void setPrice(float);

        //accessor (or getter) functions
        int getNumPages() const;
        string getBookTitle() const;
        float getPrice() const;

        friend ostream& operator << (ostream& os, const Book& b)
        {
            os << "My favorite book is " << b.bookTitle;
            os << " and it costs $"  << b.price;
            os << " and has " << b.numPages << " pages.\n\n";
            return os;
        }
        /*void printBook() //inline member function
        {
            cout << "My favorite book is " << bookTitle;
            cout << " and it costs $"  << price;
            cout << " and has " << numPages << " pages.\n\n";
        }*/
};



#endif 
