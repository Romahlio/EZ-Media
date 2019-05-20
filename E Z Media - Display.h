/**********************************
File name: E Z Media – Display.h
Programmer: Romahlio Oswald Williams
Date: February 19, 2013
Description: Computer Science IA
**********************************/

void SetScreenSize(int x,int y)
{
	HANDLE hOut;
	SMALL_RECT newScreenSize;
	
	newScreenSize.Left = 0; //(Upper left)
	newScreenSize.Right = x; //(Bottom right)
	newScreenSize.Top = 0;
	newScreenSize.Bottom = y; //Height of window
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(hOut, TRUE, &newScreenSize);
}

void SetScreenPosition(int x, int y)
{
	HWND a;
	a = GetConsoleWindow( );
	MoveWindow(a,x,y,10,10,1);
}

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(H,pos);
}

void printBlank(int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		printf(" ");
	}
}

void printBox(int height, int width, int boxClr, int bgClr)
{
	int x;

	printBlank((80 - width)/2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
	printBlank(width);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
	printBlank((80 - width)/2);

	for(x = 0; x < height; x++)
	{
		printBlank((80 - width)/2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
		printf("  ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
		printBlank(width - 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
		printf("  ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);	
		printBlank((80 - width)/2);
	}

	printBlank((80 - width)/2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
	printBlank(width);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
	printBlank((80 - width)/2);
}

void printTable(int rows,int height, int width, int boxClr, int bgClr)
{
	int x, y;

	printBlank((80 - width)/2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
	printBlank(width);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
	printBlank((80 - width)/2);

	for(y = 0; y < rows; y++)
	{
		for(x = 0; x <= height; x++)
		{
			printBlank((80 - width)/2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
			printf("  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
			printBlank(width - 4);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
			printf("  ");
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);	
			printBlank((80 - width)/2);
		}

		printBlank((80 - width)/2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),boxClr);
		printBlank(width);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),bgClr);
		printBlank((80 - width)/2);
	}
}

void stringCenter(char *string)
{
	int blankSpaces = 80 - strlen(string);

	printBlank(blankSpaces/2);

	printf("%s", string);
}

void LoginScreen()
{
	system("cls");
	printf("\n");

	stringCenter("---------\n");
	stringCenter("L O G I N\n");
	stringCenter(" ---------\n\n");

	printBox(7, 48, 187, 11);
	gotoxy(30, 9);
	printf("Password: ");
}

void PassSetupScreen()
{
	system("cls");
	printf("\n");

	stringCenter("--------------------------\n");
	stringCenter("P A S S W O R D  S E T U P\n");
	stringCenter(" --------------------------\n\n");

	printBox(8, 48, 187, 11);
	gotoxy(28, 9);
	printf("ENTER PASSWORD:  ");
}

void LoginResponseScreen(int login)
{
	system("cls");
	printf("\n");

	stringCenter("---------\n");
	stringCenter("L O G I N\n");
	stringCenter(" ---------\n\n");

	if(login == 1)
	{
		printBox(7, 48, 170, 11);
		gotoxy(33, 9);printf("W E L C O M E");
	}
	else
	{
		printBox(7, 48, 204, 11);
		gotoxy(21, 9);printf("I N C O R R E C T     P A S S W O R D");
	}
	getch();
}

void PassSetupResponseScreen(int match)
{
	system("cls");
	printf("\n");

	stringCenter("--------------------------\n");
	stringCenter("P A S S W O R D  S E T U P\n");
	stringCenter(" --------------------------\n\n");

	if(match == 1)
	{
		printBox(8, 48, 170, 11);
		gotoxy(25, 10);
		printf("PASSWORD SUCCESSFULLY CREATED");
	}
	else
	{
		printBox(8, 48, 204, 11);
		gotoxy(29, 10);
		printf("PASSWORDS DO NOT MATCH");
	}
	getch();
	system("cls");
}

void TitleScreen()
{
	printf("\n\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),187);
	printBlank(64);
	printf("\n\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	stringCenter("EEEEEEEEEEEEEEEEEEEEEE     ZZZZZZZZZZZZZZZZZZZ\n");
	stringCenter("E::::::::::::::::::::E     Z:::::::::::::::::Z\n");
	stringCenter("E::::::::::::::::::::E     Z:::::::::::::::::Z\n");
	stringCenter("EE::::::EEEEEEEEE::::E     Z:::ZZZZZZZZ:::::Z \n");
	stringCenter("  E:::::E       EEEEEE     ZZZZZ     Z:::::Z  \n");
	stringCenter("  E:::::E                          Z:::::Z    \n");
	stringCenter("  E::::::EEEEEEEEEE               Z:::::Z     \n");
	stringCenter("  E:::::::::::::::E              Z:::::Z      \n");
	stringCenter("  E:::::::::::::::E             Z:::::Z       \n");
	stringCenter("  E::::::EEEEEEEEEE            Z:::::Z        \n");
	stringCenter("  E:::::E                     Z:::::Z         \n");
	stringCenter("  E:::::E       EEEEEE     ZZZ:::::Z     ZZZZZ\n");
	stringCenter("EE::::::EEEEEEEE:::::E     Z::::::ZZZZZZZZ:::Z\n");
	stringCenter("E::::::::::::::::::::E     Z:::::::::::::::::Z\n");
	stringCenter("E::::::::::::::::::::E     Z:::::::::::::::::Z\n");
	stringCenter("EEEEEEEEEEEEEEEEEEEEEE     ZZZZZZZZZZZZZZZZZZZ\n\n");

	stringCenter("-------------\n");
	stringCenter("M E D I A\n");
	stringCenter("-------------\n");

	printf("\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),187);
	printBlank(64);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	Sleep(1000);
	system("cls");
}

int Menu()
{
	int op = 0, x1 = 25, x2 = 54, y = 6;
	char c = ' ';

	system("cls");

	stringCenter("-----------------\n");
	stringCenter("M A I N   M E N U\n");
	stringCenter(" -----------------\n\n");

	printTable(9, 2, 30, 187, 11);

	gotoxy(26, 6); printf("         CREATE NEW         ");
	gotoxy(26, 10);printf("        COMING  SOON        ");
	gotoxy(26, 14);printf("          VIEW ALL          ");
	gotoxy(26, 18);printf("         WATCH LIST         ");
	gotoxy(26, 22);printf("            EDIT            ");
	gotoxy(26, 26);printf("           SEARCH           ");
	gotoxy(26, 30);printf("           DELETE           ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	gotoxy(26, 34);printf("       CHANGE PASSWORD      ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	gotoxy(26, 38);printf("            EXIT            ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	
	do
	{
		switch(c)
		{
			case 72: if( y != 6){y = y-4;}//move up if not at maximum
					 break;

			case 80: if(y != 38){y = y+4;}//move down if not at minimum
					 break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),238);

		if(x1 == 25 && y == 6){op = 1;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){op = 2;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){op = 3;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){op = 4;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 22){op = 5;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 26){op = 6;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 30){op = 7;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 34){op = 8;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 38){op = 0;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

		c = getch();

		if(x1 == 25 && y == 6){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 22){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 26){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 30){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 34){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 38){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}


	}while(c != 13);
	system("cls");
	return op;
}

void printDate(Date d)
{
	printf("\nRELEASE DATE: %.2i/%.2i/%i\n", d.day, d.month, d.year);//print date in format dd/mm/yyyy
}

void printTrackList(char trackList[][50], int numSongs)
{
	int x = 0;

	printf("%.2i: %s\n", x+1, trackList[x]);
	x++;

	for(x ; x < numSongs; x++)
	{
		printf("              %.2i: %s\n", x+1, trackList[x]);
	}
}

void printMusic(Music music[], int x)
{
	int y;

	printf("\n");
	printBlank(31);
	printf("MUSIC RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	printf("\nALBUM       : %s\n", music[x].album);
	printf("\nARTIST      : %s\n", music[x].artist);
	printf("\nGENRE       : %s\n", music[x].genre);
	
	if(music[x].numSongs > 0)
	{
		printf("\nTRACK LIST  : ");
		printTrackList(music[x].trackList, music[x].numSongs);
	}
	printDate(music[x].releaseDate);

	printf("\nREVIEW SCORE: %.1f\n", music[x].rating);//print review score correct to 1/10
	printf("\nDESCRIPTION : %s\n", music[x].description);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n");
}

void printFilm(Film film[], int x)
{
	int y;

	printf("\n");
	printBlank(31);
	printf("FILM RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	printf("\nMOVIE       : %s\n", film[x].movie);
	printf("\nACTORS      : %s\n", film[x].actors);
	printf("\nDIRECTOR    : %s\n", film[x].director);	
	printf("\nGENRE       : %s\n", film[x].genre);

	printDate(film[x].releaseDate);

	printf("\nREVIEW SCORE: %.1f\n", film[x].rating);//print review score correct to 1/10
	printf("\nDESCRIPTION : %s\n", film[x].description);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n");
}

void printGame(Game game[], int x)
{
	int y;

	printf("\n");
	printBlank(31);
	printf("GAME RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	printf("\nGAME        : %s\n", game[x].game);
	printf("\nPLATFORM    : %s\n", game[x].platform);
	printf("\nGENRE       : %s\n", game[x].genre);
	printf("\nPUBLISHER   : %s\n", game[x].publisher);
	
	printDate(game[x].releaseDate);
	
	printf("\nREVIEW SCORE: %.1f\n", game[x].rating);	
	printf("\nDESCRIPTION : %s\n", game[x].description);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n");
}

void DisplayAllMusic(Music music[], int musicCount)
{
	int x;
	
	system("cls");
	printf("\n");

	stringCenter("-----------------\n");
	stringCenter("A L L   M U S I C\n");
	stringCenter(" -----------------\n\n");

	if( musicCount == -1)
	{
		stringCenter("NO MUSIC RECORDS FOUND");
	}

	for(x = 0; x <= musicCount; x++)
	{
		printMusic(music, x);
	}
}

void DisplayAllFilm(Film film[], int filmCount)
{
	int x;

	system("cls");
	printf("\n");

	stringCenter("---------------\n");
	stringCenter("A L L   F I L M\n");
	stringCenter(" ---------------\n\n");

	if( filmCount == -1)
	{
		stringCenter("NO FILM RECORDS FOUND");
	}

	for(x = 0; x <= filmCount; x++)
	{
		printFilm(film, x);
	}
}

void DisplayAllGame(Game game[], int gameCount)
{
	int x;

	system("cls");
	printf("\n");

	stringCenter("-----------------\n");
	stringCenter("A L L   M U S I C\n");
	stringCenter(" -----------------\n\n");

	if( gameCount == -1)
	{
		stringCenter("NO GAME RECORDS FOUND");
	}

	for(x = 0; x <= gameCount; x++)
	{
		printGame(game, x);
	}
}

void DisplayAll(Music music[], Film film[], Game game[], Count c)
{
	int op = 1, media = -1;

	while (op != 2)//while the user would like to display upcoming media from another media type
	{
		fflush(stdin);
		media = ChooseMediaType(media);

		if(media == 0)//if user eneters 0, exit the loop
		{
			break;
		}

		system("cls");

		switch(media)//determine which media type to manipulate
		{
			case 1: DisplayAllMusic(music, c.musicCount);
					break;

			case 2: DisplayAllFilm(film, c.filmCount);
					break;

			case 3: DisplayAllGame(game, c.gameCount);
					break;
		}
		getch();
		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("VIEW OTHER MEDIA RECORDS?");
		printf("\n\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}
}

int ChooseMediaType(int op)
{
	int x1 = 25, x2 = 54, y = 6;
	char c = ' ';

	system("cls");
	stringCenter("---------------------------------\n");
	stringCenter("S E L E C T   M E D I A   T Y P E\n");
	stringCenter(" ---------------------------------\n\n");

	printTable(4, 2, 30, 187, 11);

	gotoxy(25, 6);printf("             MUSIC             ");
	gotoxy(25, 10);printf("             FILM             ");
	gotoxy(25, 14);printf("             GAME             ");
	gotoxy(25, 18);printf("             EXIT             ");

	do
	{
		switch(c)
		{
			case 72: if( y != 6){y = y-4;}//move up if not at maximum
					 break;

			case 80: if(y != 18){y = y+4;}//move down if not at minimum
					 break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),238);

		if(x1 == 25 && y == 6){op = 1;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){op = 2;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){op = 3;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){op = 0;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

		c = getch();

		if(x1 == 25 && y == 6){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

	}while((c != 13) || (op == -1));

	return op;
}

int ChooseListOperation()
{
	int op = 0, x1 = 25, x2 = 54, y = 6;
	char c = ' ';

	system("cls");

	stringCenter("---------------------------------\n");
	stringCenter("W A T C H L I S T   O P T I O N S\n");
	stringCenter(" ---------------------------------\n\n");

	printTable(4, 2, 30, 187, 11);

	gotoxy(26, 6);printf("         PRINT LIST         ");
	gotoxy(26, 10);printf("           INSERT           ");
	gotoxy(26, 14);printf("           DELETE           ");
	gotoxy(26, 18);printf("            EXIT            ");
	
	do
	{
		switch(c)
		{
			case 72: if( y != 6){y = y-4;}//move up if not at maximum
					 break;

			case 80: if(y != 18){y = y+4;}//move down if not at minimum
					 break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),238);

		if(x1 == 25 && y == 6){op = 1;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){op = 2;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){op = 3;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){op = 0;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

		c = getch();

		if(x1 == 25 && y == 6){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 10){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 14){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 25 && y == 18){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

	}while(c != 13);
	system("cls");
	return op;
}

int ManipulateOther()
{
	int op = 0, x1 = 36, x2 = 43, y = 7;
	char c = ' ';

	printTable(2, 2, 8, 187, 11);

	gotoxy(36, 7); printf("  YES  ");
	gotoxy(36, 11);printf("  NO   ");

	do
	{
		switch(c)
		{
			case 72: if( y != 7){y = y-4;}//move up if not at maximum
					 break;

			case 80: if(y != 11){y = y+4;}//move down if not at minimum
					 break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),238);

		if(x1 == 36 && y == 7){op = 1;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 36 && y == 11){op = 2;gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

		c = getch();

		if(x1 == 36 && y == 7){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}
		if(x1 == 36 && y == 11){gotoxy(x1, y);printf(" ");gotoxy(x2, y);printf(" ");}

	}while(c != 13);
	system("cls");
	return op;
}