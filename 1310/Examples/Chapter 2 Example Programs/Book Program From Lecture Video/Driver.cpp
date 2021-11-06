#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    Book myFavoriteBook;
    myFavoriteBook.setNumPages(156);
    myFavoriteBook.setPrice(12.99);
    myFavoriteBook.setBookTitle("The Giver");
    cout << myFavoriteBook;

    Book* myLibrary = new Book[3];

    delete [] myLibrary;

    Book anotherBook(250, "The Stand", 24.99);
    cout << anotherBook;

    return 0;
}