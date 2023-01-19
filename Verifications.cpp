#include "Verifications.h";

bool isNumberInCertainRange(int number, int start, int end)
{
	return number >= start && number <= end;
}


bool isValidMove(char move)
{
	return move == 'w' || move == 'a' || move == 's' || move == 'd';
}


bool isFieldFull(int** field, size_t fieldSize)
{
	for (size_t i = 0; i < fieldSize; i++)
	{
		for (size_t j = 0; j < fieldSize; j++)
		{
			if (field[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
