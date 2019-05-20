/***************************************
File name: E Z Media – List Operations.h
Programmer: Romahlio Oswald Williams
Date: February 19, 2013
Description: Computer Science IA
****************************************/

FilmList CreateFilmList(FilmList L)//creating list
{
	int i;
	Film blank = {"", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank Film item

	L.length = 0;

	for(i = 0; i < 50; i++)
	{
		L.array[i] = blank;
	}

	return L;
}

int IsFullFilm(FilmList L)//determines if the list is full//
{
	if(L.length >= 50)
	{
		return 1;
	}
	return 0;
}

int IsEmptyFilm(FilmList L)//determines if the list is empty//
{
	if(L.length <= 0)
	{
		return 1;
	}
	return 0;
}

FilmList InsertFilm(FilmList L, Film e, int p)//allows input of an element into the list//
{
	int x;

	if(IsFullFilm(L) == 1)
	{
		printf("\nLIST IS FULL");
		getch();
		return L;
	}
	else
	{
		if((p < 0) || (p > L.length+1))
		{
			printf("\nPOSITION IS INVALID");
			getch();
			return L;
		}
		else
		{
			for(x = L.length; x >= p; x--)
			{
				L.array[x] = L.array[x-1];
			}

			L.array[--p] = e;
			L.length++;
			return L;
		}
	}
}

int LocateFilm(FilmList L, char e[])//aquires the position of an element
{
	int x, len;

	len = strlen(e);//get length of search key

	if(IsEmptyFilm(L) == 1)
	{
		printf("\nLIST IS EMPTY");
		getch();
	}
	else
	{
		for(x = 0; x < L.length; x++)
		{
			if(strnicmp(e, L.array[x].movie, len) == 0)//compares the length of the search key to that length within the record
			{
				return x+1;
			}
		}
	}
	return -1;
}

Film RetrieveFilm(FilmList L, int p)//determines the element stored at a position
{
	Film e = {"", "", "", "", 0, 0, 0, 0.0, ""};

	p--;

	if(IsEmptyFilm(L) == 1)
	{
		printf("\nLIST IS EMPTY");
		getch();
	}
	else
	{
		if((p < 0) || (p > L.length))
		{
			printf("\nPOSITION NOT FOUND");
		}
		else
		{
			e = L.array[p];
		}
	}

	return e;
}

FilmList deleteFilm(FilmList L, int p)//removes an element from the list
{
	int x;

	if((p < 1) || p > (L.length))
	{
		printf("\nFILM RECORD NOT FOUND OR LIST IS EMPTY");
		getch();
	}
	else
	{
		for(x = p; x < L.length; x++)
		{
			L.array[x-1] = L.array[x];
		}
		L.length--;
	}
	return L;
}

int LengthFilm(FilmList L)
{
	return L.length;
}

void PrintFilmList(FilmList L)
{
	int x;

	system("cls");
	
	gotoxy(0, 1);stringCenter("---------------------------\n");
	gotoxy(0, 2);stringCenter("F I L M   W A T C H L I S T\n");
	gotoxy(0, 3);stringCenter(" ---------------------------\n\n");

	if(IsEmptyFilm(L) == 1)
	{
		stringCenter("LIST IS EMPTY");
	}
	else
	{
		for(x = 0; x < L.length; x++)
		{
			printFilm(L.array, x);
		}
	}
}