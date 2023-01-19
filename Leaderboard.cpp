#include <iostream>
using namespace std;
#include "Leaderboard.h";
#include "Operations.h";
#include <fstream>

const int LEADERBOARD_PLAYESRS = 5;
const int BUFF_SIZE = 200;
const int FILE_NAME_SIZE = 7;


char* getLeaderboardNickname(char*& line)
{
	char buff[BUFF_SIZE];
	int buffIndex = 0;
	while (*line != ':')
	{
		buff[buffIndex++] = *line;
		line++;
	}
	buff[buffIndex] = '\0';
	//skip the dots
	line += 2;
	char* nickname = new char[getLengthOfString(buff) + 1];
	copyString(buff, nickname);
	return nickname;
}

int getScore(const char* line)
{
	int score = 0;

	while (*line)
	{
		score = score * 10 + getNumberFromSymbol(*line);
		line++;
	}
	return score;
}

void getNicknameAndScore(char* line, char** nickname, int* scores)
{
	*nickname = getLeaderboardNickname(line);
	*scores = getScore(line);
}

void getLeaderboard(const char* fileName, char** nicknames, int* scores)
{
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			char buff[BUFF_SIZE];
			inFile.getline(buff, BUFF_SIZE);
			char* line = new char[getLengthOfString(buff) + 1];
			copyString(buff, line);
			getNicknameAndScore(line, nicknames, scores);
			delete[] line;
			nicknames++;
			scores++;
		}
	}
	else
	{
		cout << "Error openning the file!" << endl;
	}
	inFile.close();
}

int getCountPlayersInLeaderboard(int* scores, int maxPlayers)
{
	int players = 0;
	for (size_t i = 0; i < maxPlayers; i++)
	{
		if (scores[i] == 0)
		{
			break;
		}
		players++;
	}
	return players;
}

void writeOnLeaderboard(char** nicknames, int* scores, int players, char* fileName)
{
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open())
	{

		for (size_t i = 0; i < players; i++)
		{
			//check if it is the last because it prints endl which is a problem after that with readingthe file again
			if (i == players - 1)
			{
				outFile << nicknames[i] << ": " << scores[i];
				break;
			}
			outFile << nicknames[i] << ": " << scores[i] << endl;
		}
	}
	else
	{
		cout << "Error openning the file!";
	}
	outFile.close();
}

void swapScores(int* scores, int firstIndex, int secondIndex)
{
	int temp = scores[firstIndex];
	scores[firstIndex] = scores[secondIndex];
	scores[secondIndex] = temp;
}

void swapPlayers(char** nicknames, int firstIndex, int secondIndex)
{
	char* temp = nicknames[firstIndex];
	nicknames[firstIndex] = nicknames[secondIndex];
	nicknames[secondIndex] = temp;
}

void sortLeaderboard(char** nicknames, int* scores, int players)
{
	//bubble sort
	for (size_t i = 0; i < players - 1; i++)
	{
		for (size_t p = 0; p < players - i - 1; p++)
		{
			if (scores[p] < scores[p + 1])
			{
				//swap both
				swapScores(scores, p, p + 1);
				swapPlayers(nicknames, p, p + 1);
			}
		}
	}
}

void freeNicknames(char** nicknames, size_t sizeOfMatrix)
{
	for (size_t i = 0; i < sizeOfMatrix; i++)
	{
		delete[] nicknames[i];
	}
	delete[] nicknames;
}

void updateLeaderboard(int fieldSize, int currentScore, char* currentNickname, bool& isNicknameInNicknames)
{
	char fileName[FILE_NAME_SIZE];
	getFileName(fieldSize, fileName);

	char** nicknames = new char* [LEADERBOARD_PLAYESRS];
	int scores[LEADERBOARD_PLAYESRS] = { 0 };
	getLeaderboard(fileName, nicknames, scores);

	int playersOnLeaderboard = getCountPlayersInLeaderboard(scores, LEADERBOARD_PLAYESRS);
	if (playersOnLeaderboard < LEADERBOARD_PLAYESRS)
	{
		scores[playersOnLeaderboard] = currentScore;
		nicknames[playersOnLeaderboard] = currentNickname;
		//sort by score
		sortLeaderboard(nicknames, scores, playersOnLeaderboard + 1);
		//write in file
		writeOnLeaderboard(nicknames, scores, playersOnLeaderboard + 1, fileName);
		isNicknameInNicknames = true;
	}
	else
	{
		//if less than the last one we don't have to add him
		if (scores[LEADERBOARD_PLAYESRS - 1] < currentScore)
		{
			delete[] nicknames[LEADERBOARD_PLAYESRS - 1];
			scores[LEADERBOARD_PLAYESRS - 1] = currentScore;
			nicknames[LEADERBOARD_PLAYESRS - 1] = currentNickname;
			//sort by score
			sortLeaderboard(nicknames, scores, playersOnLeaderboard);

			//write in file
			writeOnLeaderboard(nicknames, scores, playersOnLeaderboard, fileName);
			isNicknameInNicknames = true;
		}
	}

	freeNicknames(nicknames, playersOnLeaderboard);

}

void showLeaderboardMenu()
{
	cout << "Available leaderboards:" << endl;
	cout << "@ Leaderboard for size 4" << endl;
	cout << "@ Leaderboard for size 5" << endl;
	cout << "@ Leaderboard for size 6" << endl;
	cout << "@ Leaderboard for size 7" << endl;
	cout << "@ Leaderboard for size 8" << endl;
	cout << "@ Leaderboard for size 9" << endl;
	cout << "@ Leaderboard for size 10" << endl;
}

void showLeaderboard(const char* fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		//while there is something to read
		while (!inFile.eof())
		{
			char buff[BUFF_SIZE];
			inFile.getline(buff, BUFF_SIZE);
			cout << buff << endl;
		}
	}
	else
	{
		cout << "Error openning the file!" << endl;
	}
	inFile.close();
}

void getFileName(int chosenLeaderboard, char* fileName)
{
	if (chosenLeaderboard == 10)
	{
		fileName[0] = '1';
		fileName[1] = '0';
		copyString(".txt", fileName + 2);
	}
	else
	{
		fileName[0] = getSymbolFromDigit(chosenLeaderboard);
		copyString(".txt", fileName + 1);
	}
}

void showChosenLeaderboard(int chosenLeaderboard)
{
	char fileName[FILE_NAME_SIZE];
	getFileName(chosenLeaderboard, fileName);
	showLeaderboard(fileName);
}
