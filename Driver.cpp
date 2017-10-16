/*Alix Field		afield@cnm.edu		Field.P3
				Driver.cpp						                  */


#include "PowerClass.h"
#include "powerFunctions.h"

int main()
{
	//Console Text and Background Color
	system("Color 73");

	//Variable Declaration
	string answer = "y";
	string playerName;
	string display1 = "";
	string result = "";
	int UserWhite[5] = {};
	int GameWhite[5] = {};
	int userRed, gameRed = 0;


	//Object Instation
	Powerball gracey;

	//Calling First 2 powerFunctions
	WriteHeader();
	playerName = AskName();
	
	//Set Players Name
	gracey.SetPlayersName(playerName);

	//Play Loop
	do
	{
		AskPlayerNum(UserWhite,  &userRed);
		//Set player numbers
		gracey.SetNumbers(UserWhite, userRed);
		
		//Display Player and Game Numbers
		display1= gracey.DisplayNumbers();
		cout << display1;

		//Display Results
		result = gracey.DisplayResults();
		cout << result;
		
		cout << "\n\nWould you like to play again (y/n)?";
		getline(cin, answer);
	} while (answer == "y");

	//Goodbye Message
	cout << "\n\nThank You for Playing!!!"
		<< "\n          ~* GoodBye *~\n\n";

	return 0;
}