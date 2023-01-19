#include "UserInfo.h";
#include <iostream>
#include "InGameActions.h";
#include "FieldOperations.h";
#include "Leaderboard.h";
using namespace std;


void StartGame()
{
	bool isNicknameInNicknames = false;
	char* nickname = getNickname();
	int fieldSize = getFieldSize();
	int** field = new int* [fieldSize];
	int score = 0;
	cin.ignore();
	gameOn(field, fieldSize, score);
	freeField(field, fieldSize);

	updateLeaderboard(fieldSize, score, nickname, isNicknameInNicknames);

	if (!isNicknameInNicknames)
	{
		delete[] nickname;
	}
}

void LeaderboardActions()
{
	showLeaderboardMenu();
	int chosenLeaderboard = chooseLeaderboard();
	showChosenLeaderboard(chosenLeaderboard);
}