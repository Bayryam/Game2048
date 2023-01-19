#include <iostream>
using namespace std;
#include "FieldOperations.h";
#include "Operations.h";

const int SPACE_GIVEN = 4;


void printStartMenu()
{
	cout << "1. Start game" << endl;
	cout << "2. Leaderboard" << endl;
	cout << "3. Quit" << endl;
}

void initBoard(int** field, size_t sizeOfField, int value)
{
	for (size_t i = 0; i < sizeOfField; i++)
	{
		field[i] = new int[sizeOfField];
		for (size_t j = 0; j < sizeOfField; j++)
		{
			field[i][j] = value;
		}
	}
}

void printNeededSpaces(int numberLength)
{
	int spacesNeeded = SPACE_GIVEN - numberLength;
	for (size_t i = 0; i < spacesNeeded; i++)
	{
		cout << " ";
	}
}

void printBoardAndScore(int sizeOfBoard, int** field, int score)
{
	for (size_t i = 0; i < sizeOfBoard; i++)
	{
		cout << "  ";
		for (size_t j = 0; j < sizeOfBoard; j++)
		{
			cout << field[i][j];
			printNeededSpaces(getNumberLength(field[i][j]));
			cout << "  ";
		}
		cout << endl << endl;
	}
	cout << "Score: " << score << endl << endl;

}

void generateRandomNumberInTheField(int** field, size_t sizeOfField, int valueToInsert, int& score)
{
	srand(time(NULL));//Seeds the pseudo-random number generator with the value seed.

	//generates random coordinates between 0 and sizeOfBoard-1
	int firstRandomCoordinate = rand() % sizeOfField;
	int secondRandomCoordinate = rand() % sizeOfField;

	while (field[firstRandomCoordinate][secondRandomCoordinate] != 0)
	{
		firstRandomCoordinate = rand() % sizeOfField;
		secondRandomCoordinate = rand() % sizeOfField;
	}

	field[firstRandomCoordinate][secondRandomCoordinate] = valueToInsert;
	score += valueToInsert;
}

int getRandomValueBetween2And4()
{
	srand(time(NULL));//Seeds the pseudo-random number generator with the value seed.
	//2 powered once or twice
	return 1 << (rand() % 2 + 1);
}

int getRandomValueBetween2Or4Or8()
{
	srand(time(NULL));//Seeds the pseudo-random number generator with the value seed.
	//2 powered one, twice or three times more often twice or three times
	return 1 << (rand() % 5 + 1) % 3 + 1;
}

void freeField(int** field, size_t sizeOfField)
{
	for (size_t i = 0; i < sizeOfField; i++)
	{
		delete[] field[i];
	}
	delete[] field;
}
