/*Alix Field		afield@cnm.edu		Field.P3 
			PowerClass.cpp                                 */

#include "PowerClass.h"

/*----------------------------------- Public Methods -----------------------------------*/


//---------------------------------
//Default Constructor
//---------------------------------

Powerball::Powerball()
{
	for (int i = 0; i < 5; i++)
	{
		playerWhite[i] = 0;
		gameWhite[i] = 0;
	}

	player = "";
	playerRed = 0;
	gameRed = 0;
	result = "";
	desc = "";
	numbers = "";
	total = 0;
}

//-------------------------------
//Accessors
//-------------------------------
void Powerball::SetPlayersName(string n)
{
	player = n;
}

void Powerball::SetNumbers(int num[], int red)
{
	//User Numbers
	playerRed = red;
	for (int u = 0; u < 5; ++u)
	{
		playerWhite[u] =  num[u];
	}

	//Sorting User Numbers
	Sort(playerWhite, 5);							

	//Game Numbers
	GenerateGameNum();
}

//----------------
//Getters
//----------------
string Powerball::DisplayNumbers()
{
	stringstream displayNum;
	displayNum << numbers;

	//Displaying User Numbers
	displayNum << "\n\n" << player << "'s Picked Lottery Numbers: "
							<< "\n     White Ball Numbers: ";
	for (int i = 0; i < 5; ++i)
	{
		displayNum << playerWhite << ", ";
	}
		displayNum<< "\n     Powerball Number:  " << playerRed << endl;
	
	//Displaying Computer Numbers
	displayNum << "\n\nComputer Lottery Numbers: "
							<< "\n     White Ball Numbers: ";
	for (int i = 0; i < 5; ++i)
	{
		displayNum << gameWhite << ", ";
	}
		displayNum << "\n     Powerball Number:  " << gameRed;

	return displayNum.str();
}


string Powerball::DisplayResults()
{
	CheckResults();
	stringstream displayRes;
	displayRes << result;
	displayRes << "\n\n" << player << "'s Results: "
							<< "\n\n" << desc;
	return displayRes.str();
}


/*************************** Privot Methods ***************************/

void Powerball::Sort(int n[], int total1)
{
	//Declaring Variables
	int i, j, temp;	

	//Bubble Sort 
	for (i = 0; i < total1 - 1; ++i)										
	{
		for (j = 1; j < total1; ++j)
		{
			total = total1;
			if (n[j - 1] > n[j])
			{
				temp = n[j];
				n[j] = n[j - 1];
				n[j - 1] = temp;
			}
		}
	}
}

void Powerball::GenerateGameNum()
{
	//Seeding Rand
	srand((unsigned)time(NULL));

	//Declaring and Intializing Variables and Check Array
	int row, value, i;
	bool Check[56];
	bool again = true;

	//Sets the Check[] to false
	for (i = 0; i < 56; ++i)
	{
		Check[i] = false;
	}

	//For Loop: continues to fill CompWhite array until all 5 positions have been filled
	for (row = 0; row < 5; row++)
	{
		//Do While Loop: 
		do
		{
			//Generating numbers using rand
			value = rand() % 55 + 1;

			//Check Array for Repeat Numbers
			if (Check[value] == false)
			{
				gameWhite[row] = value;
				Check[value] = true;
				again = false;
			}
		} while (again == true);
	}
	
	//Sort Game Array
	Sort(gameWhite, 5);					

	//Generate Random Number for Red Ball
	int red = 0;
	red = rand() % 42 + 1;
	gameRed = red;
}

void Powerball::CheckResults()
{
	//Variable Decleration
	bool again = true;
	int whiteMatch = 0;
	
	//IF Check: 
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (playerWhite[i] == gameWhite[j])
			{
				whiteMatch++;
			}
		}
	}
	if (whiteMatch == 5 && playerRed == gameRed)
	{
		desc = "\n~~~ All White Balls & Powerball Matched ~~~ You won the Jackpot ~~~ "
			 "\n                !!! You Won $23, 000, 000 !!!\n";
		again = false;
	}
	else if (whiteMatch == 5)
	{
		desc = "\n", whiteMatch,  " Match"
		 "\n~~~ You Won $1, 000, 000 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 4 && playerRed == gameRed)
	{
		desc = "\n" , whiteMatch , " Match";
		desc = "\n Powerball: Matched";
		desc = "\n~~~ You Won $10, 000 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 4)
	{
		desc = "\n" , whiteMatch , " Match";
		desc = "\n~~~ You Won $100 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 3 && gameRed == gameRed)
	{
		desc = "\n", whiteMatch, " Match";
		desc = "\nPowerball: Matched";
		desc = "\n~~~ You Won $100 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 3)
	{
		desc = "\n", whiteMatch, " Match";
		desc = "\n~~~ You Won $7 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 2 && playerRed == gameRed)
	{
		desc = "\n", whiteMatch, " Match";
		desc = "\n~~~ You Won $7 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 2)
	{
		desc = "\n", whiteMatch, " Match";
		desc = "\n~~~ You Won $4 ~~~\n";
		again = false;
	}
	else if (whiteMatch == 0 && playerRed == gameRed)
	{
		desc = "\n" , whiteMatch, " Match";
		desc = "\nPowerball: Matched";
		desc = "\n~~~ You Won $4 ~~~\n";
		again = false;
	}
	else
	{
		desc = "I'm sorry, none of your picks matched.  :(\n\n";
		again = false;
	}
}