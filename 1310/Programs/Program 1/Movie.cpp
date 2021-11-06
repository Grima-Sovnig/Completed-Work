/*
	Title:  Movie.cpp
	Author:  Gabriel Snider
	Date:  9/24/2020
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"
/*
	Function name:  Movie (constructor)
	Parameters:  	1) A pointer to a Text variable, containing a c-string and the length of the string.
					2) An integer containing the length of the movie
	Returns: 		none (creates a new Movie object)
	Purpose:  		This function should be called when only the title of the movie and the length of
					the movie is known and it will create a new movie with this information.
*/
Movie::Movie(Text* t, int l)
{
	movieTitle = t;
	movieLength = l;
}
/*
	Function name:  Movie (constructor)
	Parameters:  	1) A pointer to a Text variable, containing the title of the movie
					2) An integer containing the length of the movie
					3) An integer containing the year the movie was released
					4) A pointer to a Text variable, containing the genre of the movie
					5) A pointer to a Text variable, containing the rating of the movie
					6) An integer containing the number of oscars the movie won
					7) A float containing the IMDB rating of the movie (out of 10 stars)
	Returns: 		none (creates a new Movie obeject)
	Purpose:  		This function should be called when all movie information is known and 
					it will create a new movie with this information.
*/
Movie::Movie(Text* t, int l, int y, Text* g, Text* r, int n,float s)
{
	movieTitle = t;
	movieLength = l;
	movieYear = y;
	movieGenre = g;
	movieRating = r;
	movieOscars = n;
	movieNumStars = s;
}
/*
	Function name:  ~Movie 
	Parameters:  	none
	Returns: 		nothing (void)
	Purpose:  		This function should be called when there is no longer need for the
					movie in the database (like when removing or deleting a movie).
*/
Movie::~Movie()
{
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

/*
	Function name:  printMovieDetails 
	Parameters:  	none
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to print ALL
					the movie information to the screen.
*/
void Movie::printMovieDetails()
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	movieTitle->displayText();
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	movieGenre->displayText();
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	movieRating->displayText();
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << endl << endl;
}
/*
	Function name:  printMovieDetailsToFile 
	Parameters:  	A file stream object (sent by reference)
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to print ALL
					the movie information to the file.
*/
void Movie::printMovieDetailsToFile(ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, movieTitle->getText(), 1000);
	outFile << temp << endl;
	outFile << movieLength << endl;
	outFile << movieYear << endl;
	strncpy(temp, movieGenre->getText(), 1000);
	outFile << temp << endl;
	strncpy(temp, movieRating->getText(), 1000);
	outFile << temp << endl;
	outFile << movieOscars << endl;
	outFile << movieNumStars << endl;
}
/*
	Function name:  editMovie 
	Parameters:  	none
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to edit a single
					movie's data
*/
void Movie::editMovie()
{
	int choice;
	Text* tempText;
	char temp[100];
	
	do
	{
		cout << "\n\nWhich detail do you wish to edit?\n";
		cout << "1.  Title\n";
		cout << "2.  Length\n";
		cout << "3.  Year\n";
		cout << "4.  Genre\n";
		cout << "5.  Rating\n";
		cout << "6.  Number of Oscars Won\n";
		cout << "7.  Number of Stars\n";
		cout << "8.  DONE EDITING\n";
		cout << "CHOOSE 1-8:  ";
		cin >> choice;
		while(choice < 1 || choice > 8)
		{
			cout << "\nOOPS!  Enter choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore();
		
		switch(choice)
		{
			case 1: cout << "\nCurrent Title: ";
					movieTitle->displayText();
					delete movieTitle;
					cout << "\nNEW TITLE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);
					movieTitle = tempText;
					break;
			
			case 2:	cout << "\nCurrent Length: " << movieLength;
					cout << "\nNEW LENGTH:  ";
					cin >> movieLength;
					break;
					
			case 3: cout << "\nCurrent Year: " << movieYear;
					cout << "\nNEW LENGTH:  ";
					cin >> movieYear;
					break;
					
			case 4:	cout << "\nCurrent Genre: ";
					movieGenre->displayText();
					delete movieGenre;
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);
					movieGenre = tempText;
					break;
					
			case 5: cout << "\nCurrent Rating: ";
					movieRating->displayText();
					delete movieRating;
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);
					movieRating = tempText;
					break;
			
			case 6: cout << "\nCurrent Number of Oscars Won: " << movieOscars;
					cout << "\nNEW NUMBER OF OSCARS:  ";
					cin >> movieOscars;
					break;
					
			case 7:	cout << "\nCurrent Star Rating from IMDB: " << movieNumStars;
					cout << "\nNEW STAR RATING:  ";
					cin >> movieNumStars;
					break;
		}
	}while(choice != 8);
}
/*
	Function name:  getMovieTitle
	Parameters:  	none
	Returns: 		Text* movieTitle
	Purpose:  		This function should be used to access the movieTitle.
*/
Text* Movie::getMovieTitle()
{
	return movieTitle;
}
/*
	Function name:  getMovieLength
	Parameters:  	none
	Returns: 		int movieLength
	Purpose:  		This function should be used to access the movieLength.
*/
int Movie::getMovieLength()
{
	return movieLength;
}
/*
	Function name:  getMovieYear
	Parameters:  	none
	Returns: 		int movieYear
	Purpose:  		This function should be used to access the movieYear.
*/
int Movie::getMovieYear()
{
	return movieYear;
}
/*
	Function name:  getMovieGenre
	Parameters:  	none
	Returns: 		Text* movieGenre
	Purpose:  		This function should be used to access the movieGenre.
*/
Text* Movie::getMovieGenre()
{
	return movieGenre;
}
/*
	Function name:  getMovieRating
	Parameters:  	none
	Returns: 		Text* movieRating
	Purpose:  		This function should be used to access the movieRating.
*/
Text* Movie::getMovieRating()
{
	return movieRating;
}
/*
	Function name:  getMovieOscars
	Parameters:  	none
	Returns: 		int movieOscars
	Purpose:  		This function should be used to access the movieOscars.
*/
int Movie::getMovieOscars()
{
	return movieOscars;
}
/*
	Function name:  getMovieNumStars
	Parameters:  	none
	Returns: 		float movieNumStars
	Purpose:  		This function should be used to access the movieNumStars.
*/
float Movie::getMovieNumStars()
{
	return movieNumStars;
}
/*
	Function name:  setMovieTitle
	Parameters:  	Text*
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieTitle.
*/
void Movie::setMovieTitle(Text* title)
{
	movieTitle = title;
}
/*
	Function name:  setMovieLength
	Parameters:  	int
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieLength.
*/
void Movie::setMovieLength(int length)
{
	movieLength = length;
}
/*
	Function name:  setMovieYear
	Parameters:  	int
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieYear.
*/
void Movie::setMovieYear(int year)
{
	movieYear = year;
}
/*
	Function name:  setMovieGenre
	Parameters:  	Text*
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieGenre.
*/
void Movie::setMovieGenre(Text* genre)
{
	movieGenre = genre;
}
/*
	Function name:  setMovieRating
	Parameters:  	Text*
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieRating.
*/
void Movie::setMovieRating(Text* rating)
{
	movieRating = rating;
}
/*
	Function name:  setMovieOscars
	Parameters:  	int
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieOscars.
*/
void Movie::setMovieOscars(int oscars)
{
	movieOscars = oscars;
}
/*
	Function name:  setMovieNumStars
	Parameters:  	float
	Returns: 		none (void)
	Purpose:  		This function is a mutator for the movieNumStars.
*/
void Movie::setMovieNumStars(float stars)
{
	movieNumStars = stars;
}
