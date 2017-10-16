/*Alix Field		afield@cnm.edu		Field.P3
				powerFunctions.cpp                      */

#include "powerFunctions.h"

//Prototypes
//void WriteHeader()
//string AskName()
//void AskPlayerNum(int UserWhite[], int *UserRed)


void WriteHeader()
{
	//Header File: Game Rules & Ask User for Name
	cout << "\n\n\n                         !!! Welcome to My Powerball Lottery Game !!!"
		<< "\n\nGame Rules:"
		<< "\n     * In Powerball there is one red ball(the powerball) that can be a value "
		<< "\n          between 1 - 42."
		<< "\n     * There are five white balls and their values can be between 1 - 55. "
		<< "\n     * You will pick five white balls(five different numbers between 1 - 55) "
		<< "\n          and one powerball number (a number between 1 - 42)."
		<< "\n     * Once you have picked your numbers, the Powerball Lottery Game will pick "
		<< "\n          5 random white ball numbers and one red powerball number to match "
		<< "\n          against the numbers you have picked."
		<< "\n\nThere Are 9 Ways to Win:"
		<< "\n     Match five white balls and the powerball"
		<< "\n          * You Win the Jackpot: $23, 000, 000"
		<< "\n          * Odds of Winning: 1 in 175,223,510.00"
		<< "\n     Match the five white balls in any order"
		<< "\n          * You Win: $1, 000, 000!"
		<< "\n          * Odds: 1 in 5,153,632.65"
		<< "\n     Match four white balls in any order and the powerball"
		<< "\n          * You Win: $10, 000!"
		<< "\n          * Odds: 1 in 648, 975.96"
		<< "\n     Match four white balls in any order"
		<< "\n          * You Win: $100"
		<< "\n          *Odds: 1 in 19,078.53"
		<< "\n     Match three white balls in any order and the powerball"
		<< "\n          * You Win: $100!"
		<< "\n          * Odds: 1 in 12, 244.83"
		<< "\n     Match three white balls in any order"
		<< "\n          * You Win: $7"
		<< "\n          * Odds: 360.14"
		<< "\n     Match two white balls in any order and the powerball"
		<< "\n          * You Win: $7"
		<< "\n          * Odds: 1 in 706.43"
		<< "\n     Match one white ball and the powerball "
		<< "\n          * You Win: $4"
		<< "\n          * Odds: 1 in 110.81"
		<< "\n     Match the powerball only"
		<< "\n          * You Win: $4"
		<< "\n          * Odds: 1 in 55.41";
}

string AskName()
{
	string playerName;

	cout << "\n\n                !!! Let's Start !!! \n"
		<< "\n\nPlease enter your name: ";
	getline(cin, playerName);

	return playerName;
}


void AskPlayerNum(int UserWhite[], int *userRed)
{
	//Variable Decleration
	bool again = true;			//Do While Loop 1
	bool inside = false;			//If Loop
	bool again2 = true;		//Do while loop 2
	int ball, rBall;

	cout << "\n\nTime to pick your winning numbers!!! "
		<< "\n     * White Ball numbers must be in range of 1 - 55  "
		<< "\n     * And may not be repeated "
		<< "\n     * The Powerball must be in of range 1 - 42 \n\n\n";

	//For Loop: Fills the Users White Ball Array
	for (int row = 0; row < 5; row++)
	{
		//Do While Loop: Checks the whiteball number entered, if it is in range
		//and not repeated
		do
		{
			cout << "Please enter a White Ball number: ";
			cin >> ball;
			cin.ignore();

			//Check IF: the white ball number is within range of 1-55
			if (ball <= 56 && ball >= 1)
			{

				//For Loop: moves the IF statement along each position of the array
				for (int i = 0; i < row; i++)
				{
					//Resetting the value to false
					inside = false;
					//IF Check: to see if the ball has already been used in the array
					if (UserWhite[i] == ball)
					{
						cout << "\n***This number has already been picked***\n\n";
						inside = true;
						row--;
					}
				}

				//IF: number is good it is entered into the array
				if (inside == false)
				{
					UserWhite[row] = ball;
					again = false;
				}
			}

			//IF: Number was not in range, sends user through the loop again
			else
			{
				cout << "\n***This number is not within range***\n\n";
				row--;
			}
		} while (again == true);
	}
	//Ask User for Powerball number
	//Check IF: powerball number is within range
	do
	{
		//Ask User for powerball number
		cout << "Please enter a number for the Powerball: ";
		cin >> rBall;
		cin.ignore();
		if (rBall <= 42 && rBall >= 1)
		{
			*userRed = rBall;
			again2 = false;
		}
		else
		{
			cout << "\n***Your Powerball number was not in range***\n\n";
		}
	} while (again2 == true);
}