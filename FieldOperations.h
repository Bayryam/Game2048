#pragma once

void printStartMenu();

void initBoard(int**, size_t, int);

void printNeededSpaces(int);

void printBoardAndScore(int, int**, int);

void generateRandomNumberInTheField(int**, size_t, int, int&);

int getRandomValueBetween2And4();

int getRandomValueBetween2Or4Or8();

void freeField(int**, size_t);



