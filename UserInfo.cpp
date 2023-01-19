#include <iostream>
using namespace std;
#include "UserInfo.h";
#include "Operations.h";
#include "Verifications.h";

const int BUFF_SIZE = 200;
const int MAX_FIELD_SIZE = 10;
const int MIN_FIELD_SIZE = 4;


int getCommand()
{
	cout << "Type 1, 2 or 3: ";
	int command = 0;
	while (true)
	{
		char buff[BUFF_SIZE];
		cin.getline(buff, BUFF_SIZE);
		if (getLengthOfString(buff) == 1)
		{
			command = getNumberFromSymbol(buff[0]);
		}
		if (command <= 3 && command >= 1)
		{
			break;
		}
		cout << "Incorrect command. Try again: ";

	}
	return command;
}

char* getNickname()
{
	cout << "Enter your nickname: ";
	char buff[BUFF_SIZE];
	cin.getline(buff, BUFF_SIZE);
	char* input = new char[getLengthOfString(buff) + 1];
	copyString(buff, input);
	return input;
}

int getFieldSize()
{
	cout << "Enter field size: ";
	int fieldSize;
	cin >> fieldSize;
	while (!isNumberInCertainRange(fieldSize, MIN_FIELD_SIZE, MAX_FIELD_SIZE))
	{
		cout << "Incorrect size. Try again: ";
		cin >> fieldSize;
	}
	return fieldSize;
}

char getValidMove()
{
	cout << "Enter move: ";
	
	char move;
	while (true)
	{
		char buff[BUFF_SIZE];
		cin.getline(buff, BUFF_SIZE);
		if (getLengthOfString(buff) == 1)
		{
			move = buff[0];
			if (isValidMove(move))
			{
				break;
			}
		}
		cout << "Invalid move! Enter new: ";

	}
	return move;
}

int chooseLeaderboard()
{
	cout << "Type wanted size here: ";
	int command = 0;
	while (true)
	{
		char buff[BUFF_SIZE];
		cin.getline(buff, BUFF_SIZE);
		int buffLength = getLengthOfString(buff);

		//with one digit
		if (buffLength == 1)
		{
			command = getNumberFromSymbol(buff[0]);
		}
		//speacially for 10
		else if (buffLength == 2)
		{
			command = getNumberFromSymbol(buff[0]) * 10 + getNumberFromSymbol(buff[1]);
		}
		//is command valid
		if (command <= 10 && command >= 4)
		{
			break;
		}
		cout << "Incorrect command. Try again: ";

	}
	return command;
}
