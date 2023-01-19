
#include "InGameActions.h";
#include "UserInfo.h";
#include "FieldOperations.h";
#include "Verifications.h";
#include <iostream>
using namespace std;

const int INIT_VALUE = 0;
const int START_TO_GENERATE_BIGGER = 400;


//moving up
void sumUpperValueIfPossible(int** field, size_t sizeOfField, int currentCol, int currentRow, int currentValue)
{
	//search for same value below the number
	for (size_t row = currentRow + 1; row < sizeOfField; row++)
	{
		//possible same value
		int nextValue = field[row][currentCol];
		if (nextValue == 0)
		{
			continue;
		}
		else if (nextValue == currentValue)
		{
			field[currentRow][currentCol] += nextValue;
			field[row][currentCol] = 0;
			break;
		}
		else
		{
			//if different we cant sum and break
			break;
		}
	}

}

void moveValueToTheTop(int** field, size_t sizeOfField, int currentCol, int currentRow)
{
	//move the value to the highest zero cell
	for (size_t row = 0; row < currentRow; row++)
	{
		if (field[row][currentCol] == 0)
		{
			field[row][currentCol] = field[currentRow][currentCol];
			field[currentRow][currentCol] = 0;
			break;
		}
	}

}

void sumSameSquaresAndMoveUp(int** field, size_t sizeOfField, int currentCol)
{
	//start from the top of the column
	for (size_t currentRow = 0; currentRow < sizeOfField; currentRow++)
	{
		int currentValue = field[currentRow][currentCol];
		//if zero skip
		if (currentValue == 0)
		{
			continue;
		}
		sumUpperValueIfPossible(field, sizeOfField, currentCol, currentRow, currentValue);
		moveValueToTheTop(field, sizeOfField, currentCol, currentRow);
	}
}

void moveUp(int** field, size_t sizeOfField)
{
	//go through every column
	for (size_t col = 0; col < sizeOfField; col++)
	{
		sumSameSquaresAndMoveUp(field, sizeOfField, col);
	}
}
//moving up

//moving down
void sumLowerValueIfPossible(int** field, size_t sizeOfField, int currentCol, int currentRow, int currentValue)
{
	//search for same value above the number
	for (int row = currentRow - 1; row >= 0; row--)
	{
		//possible same value
		int nextValue = field[row][currentCol];
		if (nextValue == 0)
		{
			continue;
		}
		else if (nextValue == currentValue)
		{
			field[currentRow][currentCol] += nextValue;
			field[row][currentCol] = 0;
			break;
		}
		else
		{
			//if different we cant sum and break
			break;
		}
	}

}

void moveValueToTheBottom(int** field, size_t sizeOfField, int currentCol, int currentRow)
{
	//move the value to the lowest zero cell
	for (int row = sizeOfField - 1; row > currentRow; row--)
	{
		if (field[row][currentCol] == 0)
		{
			field[row][currentCol] = field[currentRow][currentCol];
			field[currentRow][currentCol] = 0;
			break;
		}
	}

}

void sumSameSquaresAndMoveDown(int** field, size_t sizeOfField, int currentCol)
{
	//start from the bottom of the column
	for (int currentRow = sizeOfField - 1; currentRow >= 0; currentRow--)
	{
		int currentValue = field[currentRow][currentCol];
		//if zero skip
		if (currentValue == 0)
		{
			continue;
		}
		sumLowerValueIfPossible(field, sizeOfField, currentCol, currentRow, currentValue);
		moveValueToTheBottom(field, sizeOfField, currentCol, currentRow);
	}
}

void moveDown(int** field, size_t sizeOfField)
{
	//go through every column
	for (size_t col = 0; col < sizeOfField; col++)
	{
		sumSameSquaresAndMoveDown(field, sizeOfField, col);
	}
}
//moving down

//moving left
void sumLeftValueIfPossible(int** field, size_t sizeOfField, int currentCol, int currentRow, int currentValue)
{
	//search for same value on the right of the number
	for (size_t col = currentCol + 1; col < sizeOfField; col++)
	{
		//possible same value
		int nextValue = field[currentRow][col];
		if (nextValue == 0)
		{
			continue;
		}
		else if (nextValue == currentValue)
		{
			field[currentRow][currentCol] += nextValue;
			field[currentRow][col] = 0;
			break;
		}
		else
		{
			//if different we cant sum and break
			break;
		}
	}

}

void moveValueToTheLeft(int** field, size_t sizeOfField, int currentCol, int currentRow)
{
	//move the value to the leftmost zero cell
	for (size_t col = 0; col < currentCol; col++)
	{
		if (field[currentRow][col] == 0)
		{
			field[currentRow][col] = field[currentRow][currentCol];
			field[currentRow][currentCol] = 0;
			break;
		}
	}

}

void sumSameSquaresAndMoveLeft(int** field, size_t sizeOfField, int currentRow)
{
	//start from the left of the row
	for (size_t currentCol = 0; currentCol < sizeOfField; currentCol++)
	{
		int currentValue = field[currentRow][currentCol];
		//if zero skip
		if (currentValue == 0)
		{
			continue;
		}
		sumLeftValueIfPossible(field, sizeOfField, currentCol, currentRow, currentValue);
		moveValueToTheLeft(field, sizeOfField, currentCol, currentRow);
	}
}

void moveLeft(int** field, size_t sizeOfField)
{
	//go through every row
	for (size_t row = 0; row < sizeOfField; row++)
	{
		sumSameSquaresAndMoveLeft(field, sizeOfField, row);
	}
}
//moving left

//moving right
void sumRightValueIfPossible(int** field, size_t sizeOfField, int currentCol, int currentRow, int currentValue)
{
	//search for same value on the left of the number
	for (int col = currentCol - 1; col >= 0; col--)
	{
		//possible same value
		int nextValue = field[currentRow][col];
		if (nextValue == 0)
		{
			continue;
		}
		else if (nextValue == currentValue)
		{
			field[currentRow][currentCol] += nextValue;
			field[currentRow][col] = 0;
			break;
		}
		else
		{
			//if different we cant sum and break
			break;
		}
	}

}

void moveValueToTheRight(int** field, size_t sizeOfField, int currentCol, int currentRow)
{
	//move the value to the rightmost zero cell
	for (size_t col = sizeOfField - 1; col > currentCol; col--)
	{
		if (field[currentRow][col] == 0)
		{
			field[currentRow][col] = field[currentRow][currentCol];
			field[currentRow][currentCol] = 0;
			break;
		}
	}

}

void sumSameSquaresAndMoveRight(int** field, size_t sizeOfField, int currentRow)
{
	//start from the right of the row
	for (int currentCol = sizeOfField - 1; currentCol >= 0; currentCol--)
	{
		int currentValue = field[currentRow][currentCol];
		//if zero skip
		if (currentValue == 0)
		{
			continue;
		}
		sumRightValueIfPossible(field, sizeOfField, currentCol, currentRow, currentValue);
		moveValueToTheRight(field, sizeOfField, currentCol, currentRow);
	}
}

void moveRight(int** field, size_t sizeOfField)
{
	//go through every row
	for (size_t row = 0; row < sizeOfField; row++)
	{
		sumSameSquaresAndMoveRight(field, sizeOfField, row);
	}
}
//moving right





void gameOn(int** field, int fieldSize, int& score)
{
	//whole board with zeros;
	initBoard(field, fieldSize, INIT_VALUE);

	score = 0;
	int valueToInsert = getRandomValueBetween2And4();

	//generate a number to start with
	generateRandomNumberInTheField(field, fieldSize, valueToInsert, score);

	while (true)
	{
		printBoardAndScore(fieldSize, field, score);


		char currentMove = getValidMove();

		switch (currentMove)
		{
		case 'w':moveUp(field, fieldSize);break;
		case 'a':moveLeft(field, fieldSize);break;
		case 's':moveDown(field, fieldSize);break;
		case 'd':moveRight(field, fieldSize);break;
		}

		//stop game condition
		if (isFieldFull(field, fieldSize))
		{
			cout << "Game over! Your score is: " << score << endl;
			break;
		}

		//generate bigger values after a certain condition
		if (score > START_TO_GENERATE_BIGGER)
		{
			valueToInsert = getRandomValueBetween2Or4Or8();
		}
		else
		{
			valueToInsert = getRandomValueBetween2And4();
		}

		generateRandomNumberInTheField(field, fieldSize, valueToInsert, score);
	}
}
