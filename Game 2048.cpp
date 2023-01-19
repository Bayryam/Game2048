/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Bayryam Dermendzhiev
* @idnumber 0MI0600180
* @compiler VC
*
* Main file
*
*/

//I think all files have meaningful headings so not to copy this block again and again and repeat info





#include "FieldOperations.h";
#include "UserInfo.h";
#include "CommandsActions.h";

using namespace std;




int main()
{
	printStartMenu();
	int command = getCommand();
	while (command != 3)
	{

		if (command == 1)
		{
			StartGame();

		}
		else if (command == 2)
		{
			LeaderboardActions();
		}

		printStartMenu();
		command = getCommand();
	}

}



