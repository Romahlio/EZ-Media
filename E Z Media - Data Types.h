/**********************************
File name: E Z Media – Data Types.h
Programmer: Romahlio Oswald Williams
Date: February 19, 2013
Description: Computer Science IA
**********************************/

typedef struct
{
	int day;
	int month;
	int year;
}Date;

typedef struct
{
	char album[50];
	char artist[50];
	char genre[50];
	int numSongs;
	char trackList[50][50];
	Date releaseDate;
	float rating;
	char description[200];
}Music;

typedef struct
{
	char movie[50];
	char actors[200];
	char director[50];
	char genre[50];
	Date releaseDate;
	float rating;
	char description[200];
}Film;

typedef struct
{
	char game[50];
	char platform[50];
	char genre[50];
	char publisher[50];
	Date releaseDate;
	float rating;
	char description[100];
}Game;

typedef struct
{
	int musicCount;
	int filmCount;
	int gameCount;
}Count;

typedef struct
{
	Music array[50];
	int length;
}MusicList;

typedef struct
{
	Film array[50];
	int length;
}FilmList;

typedef struct
{
	Game array[50];
	int length;
}GameList;