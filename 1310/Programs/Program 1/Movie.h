/*
	Title:  Movie.h
	Author: Gabriel Snider
	Date:  9/24/2020
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Movie
{
private:
	Text* movieTitle;
	int movieLength;
	int movieYear;
	Text* movieGenre;
	Text* movieRating;
	int movieOscars;
	float movieNumStars;

public:
	Movie* createMovie();
	void editMovie();
	void printMovieDetails();
	void printMovieDetailsToFile(ofstream &outFile);
	Text* getMovieTitle();
	int getMovieLength();
	int getMovieYear();
	Text* getMovieGenre();
	Text* getMovieRating();
	int getMovieOscars();
	float getMovieNumStars();
	void setMovieTitle(Text*);
	void setMovieLength(int);
	void setMovieYear(int);
	void setMovieGenre(Text*);
	void setMovieRating(Text*);
	void setMovieOscars(int);
	void setMovieNumStars(float);


	Movie(Text*, int);
	Movie(Text*, int, int, Text*, Text*, int , float);
	~Movie();
};

#endif