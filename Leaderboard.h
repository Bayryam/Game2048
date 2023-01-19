#pragma once


char* getLeaderboardNickname(char*&);

int getScore(const char*);

void getNicknameAndScore(char*, char**, int*);

void getLeaderboard(const char*, char**, int*);

int getCountPlayersInLeaderboard(int*, int);

void writeOnLeaderboard(char**, int*, int, char*);

void swapScores(int*, int, int);

void swapPlayers(char**, int, int);

void sortLeaderboard(char**, int*, int);

void freeNicknames(char**, size_t);

void updateLeaderboard(int, int, char*, bool&);

void showLeaderboardMenu();

void showLeaderboard(const char*);

void getFileName(int, char*);

void showChosenLeaderboard(int);