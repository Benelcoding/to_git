#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "C:/Users/albaz/source/repos/Project4/Project4/declarations.h"
#include "C:/Users/albaz/source/repos/Project4/Project4/config.h"

int guesses; //the amount of guesses the player has left
int g1, g2, g3, g4;  //the 4 digits of the player's guess
int exist_and_placed;  // the amount of digits that exist and are correctly placed
int exist;		   // the amount of digits that exist and are incorrectly placed 

int d1 = 0, d2 = 0, d3 = 0, d4 = 0;  //the 4 digits of the code the user is trying to guess

int no_reoccurring_digits; //Does the guess have any reoccurring digits?
int one_to_six; //Are all the numbers in the guess between 1-6?
int four_digits; //is the guess 4 digits long?

void PrintDifficultyMenu() {
	printf("Code Guessing Game\nPlease select a difficulty:\n1 - Easy: %d Guesses\n2 - Medium: %d Guesses\n3 - Hard: %d Guesses\n4 - CrAzY: a random number of guesses between 5 and 25\n", EASY_GUESSES, MEDIUM_GUESSES, HARD_GUESSES);
}
void GetDifficulty() {
	int choice = -1;
	while (choice == -1)
	{
		choice = getch();
		switch (choice)
		{
		case '1':
			guesses = EASY_GUESSES;
			break;
		case '2':
			guesses = MEDIUM_GUESSES;
			break;
		case '3':
			guesses = HARD_GUESSES;
			break;
		case '4':
			guesses = 5 + (rand() % 20); //rand()%20 returns a number between 0-20, adding 5 makes the range 5-25
			break;
		default:
			printf("Thats not one of the options! Please enter your desired difficulty:");
			choice = -1;
		}
	}
}
void GenerateCode() {
	int* numarray = (int*)malloc(6 * sizeof(int));
	for (int i = 0;i<6;i++) {
		numarray[i] = i + 1;
	}
	GenerateExclusiveNumber(&d1, numarray);
	GenerateExclusiveNumber(&d2, numarray);
	GenerateExclusiveNumber(&d3, numarray);
	GenerateExclusiveNumber(&d4, numarray);
	free(numarray);
}
void GenerateExclusiveNumber(int* d, int* numarr) {
	while (*d == 0) {
		*d = numarr[rand() % 6];
	}
	numarr[*d - 1] = 0;
}
int Validguess(int guess) {
	char buffer;
	if (scanf_s("%d%c", &guess, &buffer) != 2 || buffer != '\n') {
		printf("Invalid input - enter a 4-digit code!\n");
	}
	else {
		GenerateValidationConditions(guess);
		if (no_reoccurring_digits) {
			if (one_to_six) {
				if (four_digits) {
					return 1;
				}
				else {
					printf("The code you entered is not 4 digits long! That's Invalid!\n");return 0;
				}
			}
			else {
				printf("Not all of the digits you entered are between 1-6! That's Invalid!\n");return 0;
			}
		}
		else {
			printf("Some of the digits you entered are the same, and that's invalid!\n");return 0;
		}
	}
}
void GenerateValidationConditions(int guess) {
	g1 = guess % (int)RADIX;
	g2 = (guess / 10) % RADIX;
	g3 = (guess / 100) % RADIX;
	g4 = (guess / 1000) % RADIX;

	no_reoccurring_digits = (g1 != g2)&(g1 != g3)&(g1 != g4) & (g2 != g3)&(g2 != g4) & (g3 != g4);
	one_to_six = ((g1<7)&(g1>0)) & ((g2<7)&(g2>0)) & ((g3<7)&(g3>0)) & ((g4>0)&(g4<7));
	four_digits = ((guess>999)&(guess<10000));
}
void Checkguess(int guess) {
	exist_and_placed = 0;exist = 0;
	if (g1 == d1)
		exist_and_placed++;
	else { if (g1 == d2 || g1 == d3 || g1 == d4)exist++; }
	if (g2 == d2)
		exist_and_placed++;
	else { if (g2 == d1 || g2 == d3 || g2 == d4)exist++; }
	if (g3 == d3)
		exist_and_placed++;
	else { if (g3 == d1 || g3 == d2 || g3 == d4)exist++; }
	if (g4 == d4)
		exist_and_placed++;
	else { if (g4 == d1 || g4 == d3 || g4 == d2)exist++; }

	if (exist_and_placed == 4) {
		Winner();
	}
	else {
		printf("%d Digits are in the right place, %d Digits exist but are in the wrong place and %d Digits Don't exist\n", exist_and_placed, exist, 4 - (exist_and_placed + exist));
		if (guesses == 1) {
			Loser();
		}
	}
}
void GuessGameplay() {
	int guess = 0000;
	exist_and_placed = 0;
	exist = 0;
	printf("A 4-Digit code has been genrated! Now it's guessing time.\nRemember! The digits are between 1-6!\n");
	while ((guesses != 0) & (exist_and_placed != 4)) {
		printf("you have %d guesses left...\n", guesses);
		if (Validguess(guess))
		{
			Checkguess(guess);
			guesses--;
		}
	}
}
void Winner() {
	printf(WINNER_MESSAGE);
}
void Loser() {
	printf(LOSER_MESSAGE);
}
