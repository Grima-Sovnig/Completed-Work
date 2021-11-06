/*
	Title:  Movies.cpp
	Author:  Gabriel Snider
	Date:  9/24/2020
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"
/*
	Function name:  Movies (constructeor) 
	Parameters:  	An integer containing the maximum size of the movie library 
	Returns: 		A pointer to a new Movies structure
	Purpose:  		This function should be called when the user needs to create a library
					of movies.  The function will dynamically allocate a movies array based
					on the maximum size and will also set the current number of movies to zero.
*/
Movies::Movies(int m)
{
	maxMovies = m;
	numMovies = 0;
	moviesArray = new Movie*[m];
}
/*
	Function name:  ~Movies
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when you need to remove all the single 
					movies in the movie library as well as the movie library.  This releases
					all the dynamically allocated space in memory.
*/
Movies::~Movies()
{
	for(int x = 0; x < numMovies; x++)
	{
		delete moviesArray[x];
	}
	delete [] moviesArray;
}
/*
	Function name:  resizeMovieArray 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function is called by addMovieToArray when the array size is not big enough
					to hold a new movie that needs to be added.  The function makes the array twice
					as big as it currently is and then moves all the movie pointers to this new array.
*/
void Movies::resizeMovieArray()
{
	int max = maxMovies * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	Movie** newMoviesArray = new Movie*[max];
	for(int x = 0; x < numMovies; x++)
	{
		newMoviesArray[x] = moviesArray[x];
	}
	
	//delete the original array from memory
	delete [] moviesArray;
	
	moviesArray = newMoviesArray;
	maxMovies = max;
}
/*
	Function name:  addMovieToArray 
	Parameters:  	none
	Returns: 		none
	Purpose:  		This function should be called when you need to add a single movie to the
					movie library.
*/
void Movies::addMovieToArray() 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//get movie data from the user
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	cout << "\nMOVIE LENGTH (in minutes): ";
	cin >> length;
	cout << "\nMOVIE YEAR: ";
	cin >> year;
	cin.ignore();
	cout << "\nMOVIE GENRE: ";
	cin.getline(tempString, 100);
	genre = new Text(tempString);
	cout << "\nMOVIE RATING: ";
	cin.getline(tempString, 100);
	rating = new Text(tempString);
	cout << "\nNUMBER OF OSCARS WON: ";
	cin >> numOscars;
	cout << "\nSTAR RATING (out of 10): ";
	cin >> numStars;
	
	//create the movie
	Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);
					
	//add the movie to the library	
	if(numMovies == maxMovies)
		Movies::resizeMovieArray();	//increase size by 2

	moviesArray[numMovies] = oneMovie;

	(numMovies)++;
}
/*
	Function name:  removeMovieFromArray 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to remove one single movie
					from the movie library.  The function will list all the movie names and allow
					the user to select the movie that they wish to remove. Then this function removes the movie.
*/
void Movies::removeMovieFromArray()
{
	int movieChoice;
	cout << numMovies << endl << endl;
	//delete a movie if there is more than one movie in the library.
	if((numMovies) <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		Movies::displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
		while(movieChoice < 1 || movieChoice > numMovies)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
			cin >> movieChoice;
		}
		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = moviesArray[movieIndexToBeRemoved]->getMovieTitle();
		
		
		//destroy this movie
		delete moviesArray[movieIndexToBeRemoved];
		
		int numElementsToMoveBack = (numMovies) - 1;
		
		for(int x = movieIndexToBeRemoved; x < numElementsToMoveBack; x++)
		{
			moviesArray[x] = moviesArray[x+1]; //move array elements!
		}
		
		//set the last movie to a null pointer
		moviesArray[numElementsToMoveBack] = NULL;
		
		//decrement the current number of movies
		(numMovies)--;
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
	}
}
/*
	Function name:  editMovieInArray 
	Parameters:  	none 
	Returns: 		none
	Purpose:  		This function should be called when you need to edit a movie in the array
*/
void Movies::editMovieInArray()
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	Movies::displayMovieTitles();
	cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
	cin >> movieChoice;
	while(movieChoice < 1 || movieChoice > numMovies)
	{
		cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
	}
	Movie* oneMovie = moviesArray[movieChoice-1];
	oneMovie->editMovie();
}


/*
	Function name:  displayMovies 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to have all the movies
					in the library printed to the screen.
*/
void Movies::displayMovies()
{
	if(numMovies > 0)
	{
		for(int x=0; x < (numMovies); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			moviesArray[x]->printMovieDetails(); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}
/*
	Function name:  displayMovieTitles 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when you want to print only the movie titles
					out of the movie library
*/
void Movies::displayMovieTitles()
{
	Text* movieTitle;
	
	for(int x=0; x < (numMovies); x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieTitle = moviesArray[x]->getMovieTitle();
		movieTitle->displayText();
	}
}
/*
	Function name:  readMoviesFromFile 
	Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to read movie data from a file
					and add the movies to the movie library.  The file must have data in the following order:
					title, length, year, genre, rating, num oscars won, star rating
*/
void Movies::readMoviesFromFile(char *filename)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		cout << "We got Here"<< endl;
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			cout << "We also got here" << endl;
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//now add this movie to the library
			if(numMovies == maxMovies)
				resizeMovieArray();	//increase size by 2
			moviesArray[numMovies] = oneMovie;
			(numMovies)++;
			
			//confirm addition to the user
			cout << endl;
			title->displayText();
			cout << " was added to the movie library!\n";
			
			
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			numMoviesReadFromFile++;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}
/*
	Function name:  saveToFile 
	Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to print all the movie data
					from the movie library to a file.  The data is printed in the following order (one piece
					of data per line):
					title, length, year, genre, rating, num oscars won, star rating
*/
void Movies::saveToFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x < (numMovies); x++)
	{
		moviesArray[x]->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}
/*
	Function name:  getMaxMovies 
	Parameters:  	none 
	Returns: 		int
	Purpose:  		it is a accessor function for the Movies Class.
*/
int Movies::getMaxMovies()
{
	return maxMovies;
}
/*
	Function name:  getnumMovies 
	Parameters:  	none 
	Returns: 		int
	Purpose:  		it is a accessor function for the Movies Class.
*/
int Movies::getnumMovies()
{
	return numMovies;
}
/*
	Function name:  getMoviesArray
	Parameters:  	none 
	Returns: 		pointer to the moviesArray
	Purpose:  		it is a accessor function for the Movies Class.
*/
Movie** Movies::getMoviesArray()
{
	return moviesArray;
}
/*
	Function name:  getSingleMovie 
	Parameters:  	A integer of the desired index to access
	Returns: 		int
	Purpose:  		To gather the data for a movie in a specified index.
*/
void Movies::getSingleMovie(int i)
{
	cout << "What movie do you wish to get info for? " << endl;
	cin >> i;
	cout << endl << moviesArray[i];
}
