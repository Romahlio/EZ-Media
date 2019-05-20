/**********************************
File name: E Z Media – Fucntions.h
Programmer: Romahlio Oswald Williams
Date: February 19, 2013
Description: Computer Science IA
**********************************/

int validateDate(Date d)
{
	int f = -1;//-1 is unreal date while real is 1

	switch (d.month)
	{
		case 1 : if (d.day <= 31)//if 31 days or less in January, year is real
				 {
					 f = 1;
				 }
				 break;

		case 2: if (d.day <= 28)//if not leap year and 28 days or less in February, year is real
				{
					if (d.year % 4 != 0)
					{
						f = 1;
					}
				}

				if (d.day <= 29)//if leap year and 29 days or less in February, year is real
				{
					if(d.year%4 == 0)
					{
						f = 1;
					}
				}
				break;

		case 3: if(d.day <= 31)//if 31 days or less in March, year is real
				{
					f = 1;
				}
				break;

		case 4: if(d.day <= 30)//if 30 days or less in April, year is real
				{
					f = 1;
				}
				break;

		case 5: if(d.day <= 31)//if 31 days or less in May, year is real
				{
					f = 1;
				}
				break;

		case 6: if(d.day <= 30)//if 30 days or less in June, year is real
				{
					f = 1;
				}
				break;

		case 7: if(d.day <= 31)//if 31 days or less in July, year is real
				{
					f = 1;
				}
				break;

		case 8: if(d.day <= 31)//if 31 days or less in August, year is real
				{
					f = 1;
				}
				break;

		case 9: if(d.day <= 30)//if 30 days or less in September, year is real
				{
					f = 1;
				}
				break;

		case 10: if(d.day <= 31)//if 31 days or less in October, year is real
				 {
					 f = 1;
				 }
				 break;

		case 11: if(d.day <= 30)//if 30 days or less in November, year is real
				 {
					 f = 1;
				 }
				 break;

		case 12: if(d.day <= 31)//if 31 days or less in December, year is real
				 {
					 f = 1;
				 }
				 break;

		default: f = -1; //if # of months exceeds 12, year is unreal
				 break;
	}

	if((d.year < 1900) || (d.year > 2100))//years greater than or 2100 and less than 1900 are unacceptable
	{
		f = -1;
	}

	if((d.day < 1) || (d.month < 1))//days or months less than 1 are unreal
	{
		f = -1;
	}

	return f;
}

int ReadPass(char testPass1[], char testPass2[])
{
	int y, holder, i = 0, x, j = 0;

	PassSetupScreen();

	do
	{
		testPass1[i] = getch();
		holder = testPass1[i];

		if(holder == 8)
		{
			if(i == 0)
			{
				PassSetupScreen();
			}
			else
			{
				PassSetupScreen();

				--i;

				for(x = 0; x < i; ++x)
				{
					printf("*");//for each character entered an asterisk will be shown
				}
			}
		}
		else
		{
			if(holder == 13)
			{
				break;
			}

			printf("*");
			++i;
		}
	}
	while(holder != 13);

	testPass1[i] = '\0'; 

	gotoxy(28, 10);
	printf("VERIFY PASSWORD: ");

	do
	{
		testPass2[j] = getch();
		holder = testPass2[j];

		if(holder == 8)
		{
			if(j == 0)
			{
				system("cls");
				PassSetupScreen();
				gotoxy(28, 10);

				for(x = 0; x < i; ++x)
				{
					printf("*");//for each character entered an asterisk is shown
				}

				gotoxy(28, 10);
				printf("VERIFY PASSWORD: ");
			}
			else
			{
				system("cls");
				PassSetupScreen();
				for(x = 0; x < i; ++x)
				{
					printf("*");
				}

				gotoxy(28, 10);
				printf("VERIFY PASSWORD: ");
				--j;
				for(x = 0; x < j; ++x)
				{
					printf("*");
				}
			}
		}
		else
		{

			if(holder == 13)
			{
				break;
			}

			printf("*");

			++j;
		}
	}
	while(holder != 13);

	testPass2[j] = '\0';

	if(strcmp(testPass1, testPass2) != 0)//if passwords do no match user must repeat entry
	{
		y = -1;
	}
	else
	{
		y = 1;
	}

	return y;
}

void AccountSetup(char pass[])
{
	FILE *fp;//file containing password
	char testPass1[30], testPass2[30];
	int y;
	
	if ((fp = fopen("Password.txt", "r")) == NULL)//check if file exists, if not create new password
	{	
		y = ReadPass(testPass1, testPass2);

		while(y == -1)
		{
			PassSetupResponseScreen(y);
			y = ReadPass(testPass1, testPass2);
		}
		strcpy(pass, testPass1);//store the password matched into variable pass

		if((fp = fopen("Password.txt", "w")) == NULL)//attempt to open file
		{
			fprintf(stderr, "\n\nFILE COULD NOT BE OPENED\n");//error if file wasn't opened
		}
		else//if file is opened, write the new password to it
		{
			fprintf(fp, "%s", pass);
			fclose(fp);
		}

		PassSetupResponseScreen(y);
	}
	else//if password file exist is read into the variable pass
	{
		fscanf(fp, "%s", pass);
		fclose(fp);
	}
}

void ReadLogin(char tempPass[])
{
	int holder,i = 0, x;

	fflush(stdin);
	LoginScreen();

	do
	{
		tempPass[i] = getch();
		holder = tempPass[i];
		
		if(holder == 8)
		{
			if(i == 0)
			{
				LoginScreen();
			}
			else
			{
				LoginScreen();
				
				--i;
				for(x = 0; x < i; ++x)
				{
					printf("*");//for each character entered a asterisks will be shown
				}
			}
		}
		else
		{
			if(holder == 13)
			{	
				break;
			}
			
			printf("*");
			++i;
		}
	}
	while(holder != 13);
	
	tempPass[i] = '\0';
}

int VerifyLogin(char tempPass[], char pass[])
{
	int x = -1;//-1 means pasword is incorrect, 1 means correct, 0 means password wrong too many times
	int y = 0;//count how many times the password is incorrect

	while ((x != 0) || (x != 1))
	{
		if (strcmp(tempPass, pass) == 0)//check if password is correct
		{
			x = 1;//password is correct, loop will terminate
			LoginResponseScreen(x);
			break;
		}
		else//if password was wrong increment y
		{
			y++;//count how many times the password is incorrect
			LoginResponseScreen(x);

			ReadLogin(tempPass);
		}
		if(y >= 4)//check if password was entered incorrectly 5 times
		{
			x = 0;
			break;
		}
	}

	return x;
}

Date readDate()
{
	Date d;

	fflush(stdin);
	printf("     DAY (0): ");
	scanf("%i", &d.day);
	fflush(stdin);
	printf("     MONTH (0): ");
	scanf("%i", &d.month);
	fflush(stdin);
	printf("     YEAR (0000): ");
	scanf("%i", &d.year);

	while (validateDate(d) != 1)//while date is unreal, error message is displayed
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID DATE!\n\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		d = readDate();	//date is asked for again
	}

	return d;
}

Date GetCurrentDate()
{
	Date today;
	SYSTEMTIME str_t;
	GetLocalTime(&str_t);

	today.day = str_t.wDay;//get numeric day store on the local pc
	today.month = str_t.wMonth;//get numeric month stored on the local pc
	today.year = str_t.wYear;//get numeric year stored on the local pc

	return today;
}

float readRating()
{
	float r;

	fflush(stdin);
	printf("\nREVIEW SCORE (1.0 - 10.0): ");
	scanf("%f", &r);

	while((r < 1) || (r > 10))//while review score is not 1-10, error message is displayed
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nREVIEW SCORE MUST BE BETWEET 1 and 10!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nREVIEW SCORE (1.0 - 10.0): ");//review score is asked for again
		scanf("%f", &r);
	}
	return r;
}

void writeMusicFile(Music music[], int musicCount)
{
	FILE *mfp;//music file
	int i;

	if((mfp = fopen("Music Records.dat", "rb+")) == NULL)//check if the file was successfully opened
	{
		fprintf(stderr, "\nMusic file could not be opened\n");//error message if file wasn't opened
		getch();
	}
	else//if file was opened
	{
		for(i = 0; i <= musicCount; i++)
		{
			fwrite(&music[i], sizeof(Music), 1, mfp); //write each music record to file with max capacity of a Music
		}
	
		fclose(mfp);//close file
	}
}

void writeFilmFile(Film film[], int filmCount)
{
	FILE *ff;//Film file
	int i;

	if((ff = fopen("Film Records.dat", "rb+")) == NULL)//check if the file was successfully opened
	{
		fprintf(stderr, "\nFilm file could not be opened\n");
		getch();
	}
	else//if file opened succesfully
	{
		for(i = 0; i <= filmCount; i++)
		{
			fwrite(&film[i], sizeof(Film), 1, ff); //write each film record to file with max capacity of a Film
		}
		
		fclose(ff);//close file
	}
}

void writeGameFile(Game game[], int gameCount)
{
	FILE *gf;//Game file
	int i;

	if((gf = fopen("Game Records.dat", "rb+")) == NULL)//check if the file was successfully opened
	{
		fprintf(stderr, "\nGAME FILE COULD NOT BE OPENED\n");//error if file wasn't opened
		getch();
	}
	else
	{
		for(i = 0; i <= gameCount; i++)
		{
			fwrite(&game[i], sizeof(Game), 1, gf); //write each game to file with max capacity of a Game
		}
		
		fclose(gf);//close file
	}
}

void writeWatchListFile(FilmList L)
{
	FILE *lfp;//music file
	int i;

	if((lfp = fopen("WatchList.dat", "rb+")) == NULL)//check if the file was successfully opened
	{
		fprintf(stderr, "\nWATCHLIST FILE COULD NOT BE OPENED\n");//error message if file wasn't opened
		getch();
	}
	else//if file was opened
	{
		fwrite(&L, sizeof(FilmList), 1, lfp); //write each music record to file with max capacity of a Music
		fclose(lfp);//close file
	}
}

void readTrackList(char trackList[][50], int numSongs)
{
	int x;

	printf("\nTRACK LIST: \n");

	for(x = 0; x < numSongs; x++)
	{
		fflush(stdin);
		printf("	TRACK %.2i: ", x+1);
		gets(trackList[x]);
	}
}

void readMusic(Music music[], int x)
{
	stringCenter("-------------------------------------\n");
	stringCenter("C R E A T E   M U S I C   R E C O R D\n");
	stringCenter(" -------------------------------------\n\n");

	fflush(stdin);
	printf("ALBUM: ");
	gets(music[x].album);
	printf("\nARTISTE: ");
	gets(music[x].artist);
	printf("\nGENRE: ");
	gets(music[x].genre);

	fflush(stdin);
	printf("\nNUMBER OF SONGS ON THIS ALBUM (0 - 50): ");

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 IF YOU DO NOT KNOW ALL THE SONGS ON THIS ALBUM.\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	fflush(stdin);
	gotoxy(40, 10);scanf("%i", &music[x].numSongs);
	gotoxy(0, 12);

	while((music[x].numSongs < 0) || (music[x].numSongs >= 50))
	{
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		gotoxy(0, 10);printf("INVALID NUMBER OF TRACKS!");
		printBlank(55);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printBlank(80);
		printf("NUMBER OF SONGS ON THIS ALBUM (0 - 50): ");
		printBlank(41);

		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 IF YOU DO NOT KNOW ALL THE SONGS ON THIS ALBUM.\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		fflush(stdin);
		gotoxy(40, 12);scanf("%i", &music[x].numSongs);
		gotoxy(0, 15);
	}

	if(music[x].numSongs > 0)
	{
		readTrackList(music[x].trackList, music[x].numSongs);
	}

	fflush(stdin);
	printf("\nRELEASE DATE:\n");
	music[x].releaseDate = readDate();

	fflush(stdin);
	music[x].rating = readRating();
	
	fflush(stdin);
	printf("\nDESCRIPTION: ");
	gets(music[x].description);
}

void readFilm(Film film[], int x)
{
	stringCenter("-----------------------------------\n");
	stringCenter("C R E A T E   F I L M   R E C O R D\n");
	stringCenter(" -----------------------------------\n\n");

	fflush(stdin);
	printf("MOVIE: ");
	gets(film[x].movie);
	printf("\nACTOR(S): ");
	gets(film[x].actors);
	printf("\nDIRECTOR: ");
	gets(film[x].director);
	printf("\nGENRE: ");
	gets(film[x].genre);

	printf("\nRELEASE DATE:\n");
	fflush(stdin);
	film[x].releaseDate = readDate();

	fflush(stdin);
	film[x].rating = readRating();
	
	fflush(stdin);
	printf("\nDESCRIPTION: ");
	gets(film[x].description);
}

void readGame(Game game[], int x)
{
	stringCenter("-----------------------------------\n");
	stringCenter("C R E A T E   G A M E   R E C O R D\n");
	stringCenter(" -----------------------------------\n\n");

	fflush(stdin);
	printf("GAME: ");
	gets(game[x].game);
	printf("\nPLATFORM: ");
	gets(game[x].platform);
	printf("\nGENRE: ");
	gets(game[x].genre);
	printf("\nPUBLISHER: ");
	gets(game[x].publisher);
	
	printf("\nRELEASE DATE:\n");
	fflush(stdin);
	game[x].releaseDate = readDate();

	fflush(stdin);
	game[x].rating = readRating();
	
	fflush(stdin);
	printf("\nDESCRIPTION: ");
	gets(game[x].description);
}

Count CreateRecord(Music music[], Film film[], Game game[], Count c)
{
	int op = 1, media = -1;;

	while (op != 2)//while the user would like to create another record
	{
		fflush(stdin);
		media = ChooseMediaType(media);

		if(media == 0)//if the user enters 0 then exit the loop
		{
			break;
		}
		
		system("cls");

		switch(media)//determine which media type was selected
		{
			case 1: c.musicCount++;//increase number of music records as new music is created
					readMusic(music, c.musicCount);
					writeMusicFile(music, c.musicCount);
					break;

			case 2: c.filmCount++;//increase number of film records as new film is created
					readFilm(film, c.filmCount);
					writeFilmFile(film, c.filmCount);
					break;

			case 3: c.gameCount++;//increase number of game records as new game is created
					readGame(game, c.gameCount);
					writeGameFile(game, c.gameCount);
					break;
		}
		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		stringCenter("MEDIA RECORD SUCCESSFULLY CREATED");
		printf("\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("CREATE ANOTHER MEDIA RECORD?");
		printf("\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}
	return c;
}

int DetermineFutureDate(Date d, Date today)
{
	int x = -1;//-1 is a passed date and 1 is future date

	if (d.year > today.year)//if year is greater than system year, date is in the future
	{
		x = 1;
	}
	else
	{
		if (d.year == today.year)//if year is equal, test if month is greater
		{
			if (d.month > today.month)//while year is equal, if month is greater, date is in the future
			{
				x = 1;
			}
			else
			{
				if (d.month == today.month)//while year and month are equal, test if day is greater
				{
					if (d.day >= today.day)//while year and month areequal, if day is greater than or equal, date is in the future
					{
						x = 1;
					}
					else//if not, date has passed
					{
						x= -1;
					}
				}
				else//if not, date has passed
				{ 
					x= -1;
				}
			}
		}
		else //if not, date has passed
		{
			x = -1;
		}
	}
	
	return x;
}

void UpcomingMusic(Music music[], Date today, int musicCount)
{
	int x, y, i = 0;
	//i counts the amount of times the date did not occure in the future
	//x stores the value which determines the if the dat eis passed(-1) or in the future (1)
	
	stringCenter("---------------------------\n");
	stringCenter("U P C O M I N G   M U S I C\n");
	stringCenter(" ---------------------------\n\n");
	
	for (y = 0; y <= musicCount; y++)
	{	
		x = DetermineFutureDate(music[y].releaseDate, today);

		if (x == 1)//if x is 1, print record
		{
			printMusic(music, y);
		}
		else//if date has passed, increment i
		{
			i++;
		}
	}

	if (i == y)//if no date is in the future, print message
	{
		printf("\n");
		stringCenter("NO UPCOMING MUSIC FOUND");
	}
	getch();
}

void UpcomingFilm(Film film[], Date today, int filmCount)
{
	int x, y, i = 0;
	//i counts the amount of times the date did not occure in the future
	//x stores the value which determines the if the dat eis passed(-1) or in the future (1)

	stringCenter("---------------------------\n");
	stringCenter("U P C O M I N G   F I L M S\n");
	stringCenter(" ---------------------------\n\n");
	
	for (y = 0; y <= filmCount; y++)
	{	
		x = DetermineFutureDate(film[y].releaseDate, today);

		if (x == 1)//if x is 1, print record
		{
			printFilm(film, y);
		}
		else//if date passed, increment i
		{
			i++;
		}
	}

	if (i == y)//if no date is in the future, print message
	{
		printf("\n");
		stringCenter("NO UPCOMING FILMS FOUND");
	}
	getch();
}

void UpcomingGame(Game game[], Date today, int gameCount)
{
	int x, y, i = 0;
	//i counts the amount of times the date did not occure in the future
	//x stores the value which determines the if the dat eis passed(-1) or in the future (1)
	
	stringCenter("---------------------------\n");
	stringCenter("U P C O M I N G   G A M E S\n");
	stringCenter(" ---------------------------\n\n");
	
	for (y = 0; y <= gameCount; y++)
	{	
		x = DetermineFutureDate(game[y].releaseDate, today);

		if (x == 1)//if x is 1, print record
		{
			printGame(game, y);
		}
		else//if date passed, increment i
		{
			i++;
		}
	}

	if(i == y)//if no date is in the future, print message
	{
		printf("\n");
		stringCenter("NO UPCOMING GAMES FOUND");
	}
	getch();
}

void UpcomingMedia(Music music[], Film film[], Game game[], Date today, Count c)
{
	int op = 1, media = -1;

	while (op != 2)//while the user would like to display upcoming media from another media type
	{
		media = ChooseMediaType(media);

		if(media == 0)
		{
			break;
		}

		system("cls");

		switch(media)//determine which media type to manipulate
		{
			case 1: UpcomingMusic(music, today, c.musicCount);
					break;

			case 2: UpcomingFilm(film, today, c.filmCount);
					break;

			case 3: UpcomingGame(game, today, c.gameCount);
					break;
		}

		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("VIEW OTHER UPCOMING MEDIA?");
		printf("\n\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}
}

void EditFilm(Film film[], int filmCount)
{
	int x;
	int change = -1;

	stringCenter("--------------------------------\n");
	stringCenter("E D I T   F I L M  R E C O R D\n");
	stringCenter(" --------------------------------\n\n");

	DisplayAllFilm(film, filmCount);
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH RECORD WOULD YOU LIKE TO EDIT: ");
	scanf("%i", &x);
	x--;//decrement x to match its index

	while((x < -1) || (x > filmCount))//if the user enters an invalid record number
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH MEDIA RECORD WOULD YOU LIKE TO EDIT: ");//user is prompted for record # again
		scanf("%i", &x);
		x--;
	}

	while ((x > -1) && (x <= filmCount))
	{
		system("cls");

		change = ChooseFilmField(film, change, x);

		if (change == 0)//if user enters 0 exit loop
		{
			break;
		}

		switch(change)
		{
			case 1: fflush(stdin);
					printf("\nMOVIE: ");
					gets(film[x].movie);//change movie
					break;

			case 2:	fflush(stdin);
					printf("\nACTOR(S): ");
					gets(film[x].actors);//change actors
					break;

			case 3:	fflush(stdin);
					printf("\nDIRECTOR: ");
					gets(film[x].director);//change genre
					break;

			case 4:	fflush(stdin);
					printf("\nGENRE: ");
					gets(film[x].genre);//change genre
					break;

			case 5:	fflush(stdin);
					printf("\nDATE RELEASED: \n");
					film[x].releaseDate = readDate();//change date released
					break;

			case 6: film[x].rating = readRating();//change review score
					break;

			case 7:	fflush(stdin);
					printf("\nDESCRIPTION: ");
					gets(film[x].description);//change description
					break;
		}
		writeFilmFile(film, filmCount);
		system("cls");
		printf("\n\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),10);
		stringCenter("RECORD SUCCESSFULLY EDITED");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		getch();
	}

	system("cls");
}

void EditMusic(Music music[], int musicCount)
{
	int x;
	int change = -1;

	stringCenter("--------------------------------\n");
	stringCenter("E D I T   M U S I C  R E C O R D\n");
	stringCenter(" --------------------------------\n\n");

	DisplayAllMusic(music, musicCount);
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH MEDIA RECORD WOULD YOU LIKE TO EDIT: ");
	scanf("%i", &x);
	x--;

	while((x < -1) || (x > musicCount))//if the user entered an invalid record #
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		printf("\nWHICH MEDIA RECORD WOULD YOU LIKE TO EDIT: ");//user is prompted for record # again
		scanf("%i", &x);
		x--;
	}

	while((x >= 0) && (x <= musicCount))
	{
		system("cls");

		change = ChooseMusicField(music, change, x);

		if(change == 0)//if the user enters o exit loop
		{
			break;
		}

		switch(change)
		{
			case 1: fflush(stdin);
					printf("\nALBUM: ");
					gets(music[x].album);//change album
					break;

			case 2:	fflush(stdin);
					printf("\nARTIST: ");
					gets(music[x].artist);//change artiste
					break;

			case 3:	fflush(stdin);
					printf("\nGENRE: ");
					gets(music[x].genre);//change song
					break;

			case 4:	fflush(stdin);
					
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
					printf("\nENTER 0 IF YOU DO NOT KNOW ALL THE SONGS ON THIS ALBUM.\n");
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

					printf("\nNUMBER OF SONGS ON THIS ALBUM (0 - 50): ");
					scanf("%i", &music[x].numSongs);

					while((music[x].numSongs < 0) || (music[x].numSongs >= 50))
					{
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
						printf("\nINVALID NUMBER OF TRACKS!\n");
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
						printf("\nENTER 0 IF YOU DO NOT KNOW ALL THE SONGS ON THIS ALBUM.\n");
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

						printf("\nNUMBER OF SONGS ON THIS ALBUM (0 - 50): ");
						printBlank(41);

						fflush(stdin);
						scanf("%i", &music[x].numSongs);
					}

					if(music[x].numSongs > 0)
					{
						readTrackList(music[x].trackList, music[x].numSongs);
					}
					break;

			case 5:	fflush(stdin);
					printf("\nDATE RELEASED: \n");
					music[x].releaseDate = readDate();//change date released
					break;

			case 6: music[x].rating = readRating();//change review score
					break;

			case 7:	fflush(stdin);
					printf("\nDESCRIPTION: ");
					gets(music[x].description);//change description
					break;
		}
		writeMusicFile(music, musicCount);
		system("cls");
		printf("\n\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),10);
		stringCenter("RECORD SUCCESSFULLY EDITED");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		getch();
	}

	system("cls");
}

void EditGame(Game game[], int gameCount)
{
	int x;
	int change = -1;

	stringCenter("------------------------------\n");
	stringCenter("E D I T   G A M E  R E C O R D\n");
	stringCenter(" ------------------------------\n\n");

	DisplayAllGame(game, gameCount);

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	printf("\nWHICH RECORD WOULD YOU LIKE TO EDIT: ");
	scanf("%i", &x);
	x--;

	while((x < -1) || (x > gameCount))//if ser enters an invalid record #
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH MEDIA RECORD WOULD YOU LIKE TO EDIT: ");//user is prompted for record # again
		scanf("%i", &x);
		x--;
	}

	while((x > -1) && (x <= gameCount))
	{
		system("cls");

		change = ChooseGameField(game, change, x);

		if(change == 0)//if user enters 0 exit loop
		{
			break;
		}

		switch(change)
		{
			case 1: fflush(stdin);
					printf("\nGAME: ");
					gets(game[x].game);
					break;

			case 2:	fflush(stdin);
					printf("\nPLATFORM: ");
					gets(game[x].platform);
					break;

			case 3:	fflush(stdin);
					printf("\nGENRE: ");
					gets(game[x].genre);
					break;

			case 4:	fflush(stdin);
					printf("\nPUBLISHER: ");
					gets(game[x].publisher);
					break;

			case 5: printf("\nRELEASE DATE:\n");
					game[x].releaseDate = readDate();
					break;

			case 6: game[x].rating = readRating();
					break;

			case 7:	fflush(stdin);
					printf("\nDESCRIPTION: ");
					gets(game[x].description);
					break;
		}
		writeGameFile(game, gameCount);
		system("cls");
		printf("\n\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),10);
		stringCenter("RECORD SUCCESSFULLY EDITED");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		getch();
	}

	system("cls");
}

void EditRecord(Music music[], Film film[], Game game[], Count c)
{
	int op = 1, media = -1;

	while (op != 2)//while the user would like to display upcoming media from another media type
	{
		fflush(stdin);
		media = ChooseMediaType(media);

		if(media == 0)//if usere enters 0 exit loop
		{
			break;
		}

		system("cls");

		switch(media)//determine which media type to manipulate
		{
			case 1: EditMusic(music, c.musicCount);
					break;

			case 2: EditFilm(film, c.filmCount);
					break;

			case 3: EditGame(game, c.gameCount);
					break;
		}

		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("EDIT ANOTHER MEDIA RECORD?");
		printf("\n\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}			
}

int ChooseMusicField(Music music[], int change, int x)
{
	int y, i = 0;
	printf("\n");
	printBlank(31);
	printf("MUSIC RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	
	printf("\n[1] ALBUM       : %s\n", music[x].album);
	printf("\n[2] ARTISTE     : %s\n", music[x].artist);
	printf("\n[3] GENRE       : %s\n", music[x].genre);	
	printf("\n[4] TRACK LIST  : ");

	if(music[x].numSongs > 0)
	{
		i = 1;
		printTrackList(music[x].trackList, music[x].numSongs);
	}

	if(i == 0)
	{
		printf("\n");
	}
	printf("\n[5] RELEASE DATE: %.2i/%.2i/%i\n", music[x].releaseDate.day, music[x].releaseDate.month, music[x].releaseDate.year);
	printf("\n[6] REVIEW SCORE: %.1f\n", music[x].rating);
	printf("\n[7] DESCRIPTION : %s\n", music[x].description);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	
	printf("\nWHICH FEILD DO YOU WISH TO EDIT: ");

	fflush(stdin);
	scanf("%i", &change);

	while((change < 0) || (change > 7))//if user enters an invalid option
	{
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID FEILD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	
		printf("\nWHICH FEILD DO YOU WISH TO EDIT: ");

		fflush(stdin);
		scanf("%i", &change);
	}

	return change;
}

int ChooseFilmField(Film film[], int change, int x)
{
	int y;
	printf("\n");
	printBlank(31);
	printf("FILM RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	printf("\n[1] MOVIE       : %s\n", film[x].movie);
	printf("\n[2] ACTOR(S)    : %s\n", film[x].actors);
	printf("\n[3] DIRECTOR    : %s\n", film[x].director);
	printf("\n[4] GENRE       : %s\n", film[x].genre);
	printf("\n[5] RELEASE DATE: %.2i/%.2i/%i\n", film[x].releaseDate.day, film[x].releaseDate.month, film[x].releaseDate.year);
	printf("\n[6] REVIEW SCORE: %.1f\n", film[x].rating);
	printf("\n[7] DESCRIPTION : %s\n", film[x].description);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH FEILD DO YOU WISH TO EDIT: ");

	fflush(stdin);
	scanf("%i", &change);

	while((change < 0) || (change > 7))//if user eneters an invalid field
	{
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID FEILD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH FEILD DO YOU WISH TO EDIT: ");

		fflush(stdin);
		scanf("%i", &change);
	}

	return change;
}

int ChooseGameField(Game game[], int change, int x)
{
	int y;
	printf("\n");
	printBlank(31);
	printf("GAME RECORD #: %i\n", x + 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	printf("\n[1] GAME        : %s\n", game[x].game);
	printf("\n[2] PLATFORM    : %s\n", game[x].platform);
	printf("\n[3] GENRE       : %s\n", game[x].genre);
	printf("\n[4] PUBLISHER   : %s\n", game[x].publisher);
	printf("\n[5] RELEASE DATE: %.2i/%.2i/%i\n", game[x].releaseDate.day, game[x].releaseDate.month, game[x].releaseDate.year);
	printf("\n[6] REVIEW SCORE: %.1f\n", game[x].rating);
	printf("\n[7] DESCRIPTION : %s\n", game[x].description);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for(y = 0; y < 80; y++){printf("_");}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO CANCEL\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	printf("\nWHICH FEILD DO YOU WISHH TO EDIT: ");
	fflush(stdin);
	scanf("%i", &change);
	
	while((change < 0) || (change > 7))//if field for change is invalid
	{
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID FEILD!\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO CANCEL\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		printf("\nWHICH FEILD DO YOU WHICH TO EDIT: ");
		fflush(stdin);
		scanf("%i", &change);
	}

	return change;
}

void SearchFilm(Film film[], int mediaCount)
{
	char search[50];
	int x, len, y = 0;//y counts the number of times the record did not match the search key
	
	stringCenter("---------------------\n");
	stringCenter("S E A R C H   F I L M\n");
	stringCenter(" ---------------------\n\n");

	fflush(stdin);
	printf("\n\t\tSEARCH FOR FILM BY MOVIE TITLE: ");
	gets(search);
	
	len = strlen(search);//get length of search key

	system("cls");

	stringCenter("---------------------------\n");
	stringCenter("S E A R C H   R E S U L T S\n");
	stringCenter(" ---------------------------\n\n");
	
	for(x = 0; x <= mediaCount; x++)
	{
		if (strnicmp(search, film[x].movie, len) == 0)//compares the length of the search key to that length within the record
		{
			printFilm(film, x);//if there is a match, record is printed
		}
		else//if there is no match, y is incremented
		{
			y++;
		}
	}

	if ( y == x)//if no record matched the search, a message is printed
	{
		printf("\n\n");
		stringCenter("FILM RECORD NOT FOUND");
	}
}

void SearchMusic(Music music[], int mediaCount)
{
	char search[50];
	int x, len, y = 0;//y counts the number of times the record did not match the search key

	stringCenter("-----------------------\n");
	stringCenter("S E A R C H   M U S I C\n");
	stringCenter(" -----------------------\n\n");

	fflush(stdin);
	printf("\n\t\tSEARCH FOR MUSIC BY ALBUM TITLE: ");
	gets(search);
	
	len = strlen(search);//get length of search key

	system("cls");

	stringCenter("---------------------------\n");
	stringCenter("S E A R C H   R E S U L T S\n");
	stringCenter(" ---------------------------\n\n");
	
	for(x = 0; x <= mediaCount; x++)
	{
		if (strnicmp(search, music[x].album, len) == 0)//compares the length of the search key to that length within the record
		{
			printMusic(music, x);//if there is a match, record is printed
		}
		else//if there is no match, y is incremented
		{
			y++;
		}
	}

	if ( y == x)//if no record matched the search, a message is printed
	{
		printf("\n\n");
		stringCenter("MUSIC RECORD NOT FOUND");	}
}

void SearchGame(Game game[], int mediaCount)
{
	char search[50];
	int x, len, y = 0;//y counts the number of times the record did not match the search key
	
	stringCenter("---------------------\n");
	stringCenter("S E A R C H   G A M E\n");
	stringCenter(" ---------------------\n\n");

	fflush(stdin);
	printf("\n\t\tSEARCH FOR GAME BY TITLE: ");
	gets(search);
	
	len = strlen(search);//get length of search key

	system("cls");

	stringCenter("---------------------------\n");
	stringCenter("S E A R C H   R E S U L T S\n");
	stringCenter(" ---------------------------\n\n");
	
	for(x = 0; x <= mediaCount; x++)
	{
		if (strnicmp(search, game[x].game, len) == 0)//compares the length of the search key to that length within the record
		{
			printGame(game, x);//if there is a match, record is printed
		}
		else//if there is no match, y is incremented
		{
			y++;
		}
	}

	if ( y == x)//if no record matched the search, a message is printed
	{
		printf("\n\n");
		stringCenter("GAME RECORD NOT FOUND");
	}
}

void SearchMedia(Music music[], Film film[], Game game[], Count c)
{
	int op = 1, media = -1;

	while (op != 2)//while the user would like to display upcoming media from another media type
	{
		fflush(stdin);
		media = ChooseMediaType(media);

		if(media == 0)//if user enters 0, exit loop
		{
			break;
		}

		system("cls");

		switch(media)//determines which medi type to manipulate
		{
			case 1: SearchMusic(music, c.musicCount);
					break;

			case 2: SearchFilm(film, c.filmCount);
					break;

			case 3: SearchGame(game, c.gameCount);
					break;
		}
		getch();
		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("SEARCH FOR ANOTHER MEDIA RECORD?");
		printf("\n\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}
}

void CreateMusicFile()
{
	FILE *mfp;
	Music blank = {"", "", "", 0, "", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank item

	int i;

	if((mfp = fopen("Music Records.dat", "w")) == NULL)//open file for writing
	{
		fprintf(stderr, "\nMusic file could not be opened.\n");//error if file failed to open
		getch();
	}
	else
	{
		for(i = 0; i < 100; i++)
		{
			fwrite(&blank, sizeof(Music), 1, mfp); //pad the file with blank records
		}
		fclose(mfp);
	}
}

void CreateFilmFile()
{
	FILE *ffp;
	Film blank = {"", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank Film item

	int i;

	if((ffp = fopen("Film Records.dat", "w")) == NULL)//open file for writing
	{
		fprintf(stderr, "\nFilm file could not be opened.\n");//error if file couldn't open
		getch();
	}
	else
	{
		for(i = 0; i < 100; i++)
		{
			fwrite(&blank, sizeof(Film), 1, ffp); //padd the file with blank Film records
		}
		fclose(ffp);
	}
}

void CreateGameFile()
{
	FILE *gfp;
	Game blank = {"", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank game item

	int i;

	if((gfp = fopen("Game Records.dat", "w")) == NULL)//oprn file for writing
	{
		fprintf(stderr, "\nGame file could not be opened.\n");//error if file failed to open
		getch();
	}
	else
	{
		for(i = 0; i < 100; i++)
		{
			fwrite(&blank, sizeof(Game), 1, gfp); //padd the file with blank Game records
		}
		fclose(gfp);
	}
}

void CreateWatchListFile()
{
	FILE *lfp;
	FilmList blank;

	blank = CreateFilmList(blank);
	
	if((lfp = fopen("WatchList.dat", "w")) == NULL)//oprn file for writing
	{
		fprintf(stderr, "WATCHLIST FILE COULD NOT BE OPENED.");//error if file failed to open
		getch();
	}
	else
	{
		fwrite(&blank, sizeof(FilmList), 1, lfp); //padd the file with blank Game records
		fclose(lfp);
	}
}

int readMusicFile(Music music[])
{
	FILE *mf;
	int x = -1, y;
	Music temp[100];

	if((mf = fopen("Music Records.dat", "r")) == NULL) //try opeing file
	{
		CreateMusicFile();//if file wasn't found, create it
	}
	else //this section is only executed if file is successfully opened
	{
		rewind(mf); //sets pointer to the beginning of the file

		for(y = 0; y < 100; y++)
		{
			fread(&temp[y], sizeof(Music), 1, mf);//read the entire file into a temporary array
		}

		while (strcmp("", temp[x+1].album) != 0)//while the song field is not blank
		{	
			x++;
			music[x] = temp[x];//transfer from temporary to Music array
		}

		fclose(mf);
	}

	return x;
}

int readFilmFile(Film film[])	
{
	FILE *ff;
	int x = -1, y;
	Film temp[100];

	if((ff = fopen("Film Records.dat", "r")) == NULL) //try opeing file
	{
		CreateFilmFile();//if file wasn't found create it
	}
	else //this section is only executed if file is successfully opened
	{
		rewind(ff); //sets pointer to the beginning of the file

		for(y = 0; y < 100; y++)
		{
			fread(&temp[y], sizeof(Film), 1, ff);//read the entire file into a temporary array
		}

		while (strcmp("", temp[x+1].movie) != 0)//while the movie field is not empty
		{	
			x++;
			film[x] = temp[x];//transfer from temporary array to Film array
		}

		fclose(ff);
	}

	return x;
}

int readGameFile(Game game[])	
{
	FILE *gf;
	int x = -1, y;
	Game temp[100];

	if((gf = fopen("Game Records.dat", "r")) == NULL) //try opeing file
	{
		CreateGameFile();//if file wasn't opened, vreate it
	}
	else //this section is only executed if file is successfully opened
	{
		rewind(gf); //sets pointer to the beginning of the file

		for(y = 0; y < 100; y++)
		{
			fread(&temp[y], sizeof(Game), 1, gf);//read the entire file into a temporary array
		}

		while (strcmp("", temp[x+1].game) != 0)//while the game field is not blank
		{	
			x++;
			game[x] = temp[x];//transfer from temporary variable to Game array
		}

		fclose(gf);
	}

	return x;
}

FilmList readWatchListFile(FilmList L)	
{
	FILE *lfp;
	int x = -1, y;
	
	if((lfp = fopen("WatchList.dat", "r")) == NULL) //try opeing file
	{
		CreateWatchListFile();//if file wasn't opened, create it
	}
	else //this section is only executed if file is successfully opened
	{
		
		rewind(lfp); //sets pointer to the beginning of the file

		fread(&L, sizeof(FilmList), 1, lfp);//read the entire file into a temporary array

		fclose(lfp);
	}
	return L;
}

Count readFiles(Music music[], Film film[], Game game[], Count c)	
{
	c.musicCount = readMusicFile(music);
	c.filmCount = readFilmFile(film);
	c.gameCount = readGameFile(game);

	return c;
}

int DeleteMusic(Music music[], int c)
{
	char confirm;
	int x, i;
	Music blank = {"", "", "", 0, "", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "","", "", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank item

	stringCenter("-------------------------------------\n");
	stringCenter("D E L E T E   M U S I C   R E C O R D\n");
	stringCenter(" ------------------------------------\n\n");

	DisplayAllMusic(music, c);
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO EXIT\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
	fflush(stdin);
	scanf("%i", &x);
	x--;

	while((x < -1) || (x > c))//while the record number was invalid
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO EXIT\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
		fflush(stdin);
		scanf("%i", &x);
		x--;
	}

	if(x == -1)//if the record number entered was 0
	{
		return c;//exit the module
	}

	fflush(stdin);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
	scanf("%c", &confirm);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	confirm = toupper(confirm);

	while ((confirm != 'Y') && (confirm != 'N'))//while the answergiven is neither yes nor no
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
		scanf("%c", &confirm);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		confirm = toupper(confirm);
	}

	if(confirm == 'N')//if answer is no, exit
	{
		return c;
	}

	for (i = x; i < c; i++)
	{
		music[i] = music[i+1];//reposition indexes, overwriting the record selected for deletion
	}

	music[c] = blank;//last record is made blank

	writeMusicFile(music, c);
	--c;

	system("cls");
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	stringCenter("RECORD SUCCESSFULLY DELETED");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	getch();

	return c;
}

int DeleteFilm(Film film[], int c)
{
	char confirm;
	int x, i;
	Film blank = {"", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank Film item

	stringCenter("-----------------------------------\n");
	stringCenter("D E L E T E   F I L M   R E C O R D\n");
	stringCenter(" -----------------------------------\n\n");

	DisplayAllFilm(film, c);
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO EXIT\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
	fflush(stdin);
	scanf("%i", &x);
	x--;

	while((x < -1) || (x > c))//while the record number was invalid
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO EXIT\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
		fflush(stdin);
		scanf("%i", &x);
		x--;
	}

	if(x == -1)//if the record number entered was 0
	{
		return c;//exit the module
	}

	fflush(stdin);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
	scanf("%c", &confirm);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	confirm = toupper(confirm);

	while ((confirm != 'Y') && (confirm != 'N'))//while the answergiven is neither yes nor no
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
		scanf("%c", &confirm);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		confirm = toupper(confirm);
	}

	if(confirm == 'N')//if answer is no, exit
	{
		return c;
	}

	for(i = x; i < c; i++)
	{
		film[i] = film[i+1];//reposition index, overwriting the record selected for deletion
	}

	film[c] = blank; //make the last index blank

	writeFilmFile(film, c);
	--c;

	system("cls");
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	stringCenter("RECORD SUCCESSFULLY DELETED");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	getch();

	return c;
}

int DeleteGame(Game game[], int c)
{
	int x, i;
	char confirm;
	Game blank = {"", "", "", "", 0, 0, 0, 0.0, ""};//initialize blank game item

	stringCenter("-----------------------------------\n");
	stringCenter("D E L E T E   G A M E   R E C O R D\n");
	stringCenter(" -----------------------------------\n\n");

	DisplayAllGame(game, c);
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\nENTER 0 TO EXIT\n");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
	fflush(stdin);
	scanf("%i", &x);
	x--;

	while((x < -1) || (x > c))//while the record number was invalid
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nINVALID RECORD\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\nENTER 0 TO EXIT\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
		printf("\nWHICH RECORD WOULD YOU LIKE TO DELETE: ");
		fflush(stdin);
		scanf("%i", &x);
		x--;
	}

	if(x == -1)//if the record number entered was 0
	{
		return c;//exit the module
	}

	fflush(stdin);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
	scanf("%c", &confirm);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

	confirm = toupper(confirm);

	while ((confirm != 'Y') && (confirm != 'N'))//while the answergiven is neither yes nor no
	{
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? [Y/N]\n");//ask again
		scanf("%c", &confirm);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);

		confirm = toupper(confirm);
	}

	if(confirm == 'N')//if answer is no, exit the modula
	{
		return c;
	}

	for(i = x; i < c; i++)
	{
		game[x] = game[x+1];//reposition each index, overwriting record selected for deletion
	}

	game[c] = blank;//make the last index blank

	writeGameFile(game, c);
	--c;

	system("cls");
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	stringCenter("RECORD SUCCESSFULLY DELETED");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	getch();

	return c;
}

Count DeleteMedia(Music music[], Film film[], Game game[], Count c)
{
	int op = 1, media = -1;

	while (op != 2)//while the user would like to display upcoming media from another media type
	{	
		fflush(stdin);
		media = ChooseMediaType(media);

		if(media == 0)
		{
			break;
		}

		system("cls");

		switch(media)//determine which media type to manipulate
		{
			case 1: c.musicCount = DeleteMusic(music, c.musicCount);
					break;

			case 2: c.filmCount = DeleteFilm(film, c.filmCount);
					break;

			case 3: c.gameCount = DeleteGame(game, c.gameCount);
					break;
		}

		system("cls");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		stringCenter("DELETE ANOTHER MEDIA RECORD?");
		printf("\n\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		op = ManipulateOther();
		system("cls");
	}
	return c;
}

void ChangePass(char pass[], char tempPass[])
{
	int x, y;
	FILE *fp;//file containing password
	char testPass1[30], testPass2[30];
	
	ReadLogin(tempPass);
	x = VerifyLogin(tempPass, pass);

	switch(x)
	{
		case 1:	if ((fp = fopen("Password.txt", "w")) == NULL)//attempts to open file for writing
				{
					fprintf(stderr, "File could not be opened.\n");//if file could not be opened
					getch();
				}
				else//if file exists data is re-writed
				{
					y = ReadPass(testPass1, testPass2);

					while(y == -1)
					{
						PassSetupResponseScreen(y);
						y = ReadPass(testPass1, testPass2);
					}
					strcpy(pass, testPass1);//store the password matched into variable pass

					fprintf(fp, "%s", pass);
					fclose(fp);

					PassSetupResponseScreen(y);
				}
				break;

		case 0: LoginResponseScreen(-1);
				gotoxy(19, 8);printf("PASSWORD ENTERED INCORRECTLY TOO MANY TIMES");
				gotoxy(19, 9);printf("                                           ");
				gotoxy(19, 10);printf("          RETURNING TO MAIN MENU           ");
				getch();
				return;
				break;
	}
}

FilmList PerformListOp(int op, Film film[], int filmCount, FilmList L)
{
	int rec, p;

	switch(op)
	{
		case 1: PrintFilmList(L);
				getch();
				break;

		case 2: if(filmCount != -1)
				{
					DisplayAllFilm(film, filmCount);

					fflush(stdin);
					printf("RECORD TO INSERT: ");
					scanf("%i", &rec);
					rec--;

					while((rec < 0) || (rec > filmCount))
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
						printf("\nINVALID RECORD\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

						fflush(stdin);
						printf("\nRECORD TO INSERT: ");
						scanf("%i", &rec);
						rec--;
					}
					
					if(IsEmptyFilm(L) == 1)
					{
						L = InsertFilm(L, film[rec], 1);
					}
					else
					{
						PrintFilmList(L);
						fflush(stdin);
						printf("\nPOSITION TO INSERT AT: ");
						scanf("%i", &p);
						L = InsertFilm(L, film[rec], p);
					}
				}
				else
				{
					printf("\n");
					stringCenter("YOU MUST CREATE A RECORD BEFORE ANY CAN BE ADDED TO THE LIST");
					getch();
				}
				break;

		case 3: PrintFilmList(L);
				
				if(L.length > 0)
				{
					printf("RECORD TO DELETE: ");
					scanf("%i", &p);
					L = deleteFilm(L, p);
				}
				else
				{
					getch();
				}
				break;		
	}
	return L;
}

FilmList WatchList(Film film[], int filmCount, FilmList L)
{
	int listOp = -1;

	while(listOp != 0)
	{
		fflush(stdin);
		listOp = ChooseListOperation();

		if(listOp == 0)//if user enters 0, exit loop
		{
			return L;
		}

		L = PerformListOp(listOp, film, filmCount, L);
		
		writeWatchListFile(L);

		system("cls");
	}

	return L;
}