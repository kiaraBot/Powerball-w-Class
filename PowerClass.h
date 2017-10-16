/*Alix Field		afield@cnm.edu		Field.P3
		PowerClass.h                                           */ 

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#ifndef METHODS_H
#define METHODS_H 

using namespace std;

class Powerball
{
private:
	string player;
	int playerWhite[5];
	int gameWhite[5];
	int playerRed;
	int gameRed;
	string result;
	string desc;
	string numbers;
	int total;

	void Sort(int n[], int total1);
	void GenerateGameNum();
	void CheckResults();
public:
	Powerball();	  //default constructor
	void SetPlayersName(string n);
	void SetNumbers(int num[], int red);
	string DisplayNumbers();
	string DisplayResults();
};
#endif
