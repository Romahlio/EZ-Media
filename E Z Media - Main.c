/**********************************
	File name: E Z Media - Main.c
	Programmer: Romahlio Oswald Williams
	Date: February 19, 2013
	Description: Computer Science IA
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "E Z Media - Data Types.h"
#include "E Z Media - Display.h"
#include "E Z Media - List Operations.h"
#include "E Z Media - Functions.h"

#pragma warning(disable: 4996)

int main()
{
	int x;
	char pass[30];
	char tempPass[30];
	Music music[100];
	Film film[100];
	Game game[100];
	Count count = {-1, -1, -1};
	Date today;
	FilmList filmList;
	int op;

	SetScreenPosition(300, 100);
	SetScreenSize(79, 24);

	system ("title E Z Media");
	system("color 0b");

	TitleScreen();

	filmList = CreateFilmList(filmList);
	filmList = readWatchListFile(filmList);
	
	count = readFiles(music, film, game, count);//populate arrays

	AccountSetup(pass);//read password file or create password
	
	ReadLogin(tempPass);//ask the user for password to get access
	
	x = VerifyLogin(tempPass, pass);//verify password

	SetScreenPosition(300, 100);
	SetScreenSize(79, 40);

	switch(x)
	{
		case 0: system("cls");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
				printf("\n");
				stringCenter("-------------\n");
				stringCenter("G O O D B Y E\n");//if password enetered incorrectly too many times
				stringCenter("-------------\n");
				printf("\n\n\n");
				stringCenter("YOU HAVE ENTERED THE PASSWORD INCORRECTLY TOO MANY TIMES\n\n");
				Sleep(2000);
				break;
			
		case 1: today = GetCurrentDate();// get local date
				op = Menu();//display menu
				
				while (op != 0 )//if op = 0, exit
				{
					switch(op)
					{		
						case 1: count = CreateRecord(music, film, game, count);//create new data
								break;
						
						case 2: UpcomingMedia(music, film, game, today, count);
								break;
						
						case 3: DisplayAll(music, film, game, count);
								break;
						
						case 4:	filmList = WatchList(film, count.filmCount, filmList);
								break;

						case 5: EditRecord(music, film, game, count);
								break;
						
						case 6: SearchMedia(music, film, game, count);
								break;		

						case 7: count = DeleteMedia(music, film, game, count);
								break;

						case 8: ChangePass(pass, tempPass);
								break;
					}

					op = Menu();
				}

				system("cls");
				printf("\n");
				stringCenter("-------------\n");
				stringCenter("G O O D B Y E\n");//if password enetered incorrectly too many times
				stringCenter("-------------\n");
				Sleep(1000);
	}
	
	return 0;
}	