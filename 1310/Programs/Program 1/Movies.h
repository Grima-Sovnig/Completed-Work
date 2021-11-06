/*
	Title:  Movies.h
	Author:  Gabriel Snider
	Date:  9/24/2020
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies
{
private:
	Movie** moviesArray;
	int maxMovies;
	int numMovies;
	int getMaxMovies();
	int getnumMovies();
	Movie** getMoviesArray();
	void displayMovieTitles();
	void resizeMovieArray();
	void getSingleMovie(int);
public:
	void addMovieToArray();
	void removeMovieFromArray();
	void editMovieInArray();
	void displayMovies();
	void readMoviesFromFile(char*);
	void saveToFile(char*);
	Movies(int);
	~Movies();
};
#endif