//CLASS IMPLEMENTATION FILE for the Book Class
#include "Book.h"
#include <iostream>
using namespace std;

//mutator functions
// :: is the scope resolution operator
void Book::setNumPages(int num)
{
    this->numPages = num;
}
void Book::setBookTitle(string title)
{
    this->bookTitle = title;
}
void Book::setPrice(float price)
{
    this->price = price;
}

//accessor functions
int Book::getNumPages() const
{
    return this->numPages;
}

string Book::getBookTitle() const
{
    return this->bookTitle;
}

float Book::getPrice() const
{
    return this->price;
}