### Practice Problem: Sci-Fi Books
The data directory contains several ``.csv`` files of the sub-genres of science fiction. The codex/meta-data for the
data files is as follows:

* Book_Title
* Original_Book_Title 
* Author_Name
* Edition_Language
* Rating_score
* Rating_votes
* Review_number
* Book_Description
* Year_published
* Genres
* url

All of the columns are delimited with commas, with the following caveats:

* _Book_Description_ - The book description is contained within a quoted string and may contain a number of commas as well as other quoted items (denoted with double ``""`` quotes as in ``""hello""``).
* _Genres_ - The genres field is contained within a block delimited by curly braces ``{ }`` with commas within the block.

Things to try:
* Write the code to read the data line by line in a ``main`` method. Suggestion: create a class called "SciFi" with the main method contained in it
  * ``public static void main(String args[])``
  * Use the ``File`` class to read data from a file contained in the ``data`` directory.
* Create the following classes
  * A ``Book`` class for storing book data
  * A ``Library`` class for storing the list of books 
* Write the constructor for Book so that it parses each line, handling the Book_Description and Genres data, accordingly
* Write a method in the Library class that searches for books based on the ``title`` and ``author``
* Add a program argument to allow running your program with a command-line argument of ``--title`` or ``--author`` and an appropriate name to search

