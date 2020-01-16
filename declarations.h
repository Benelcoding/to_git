#pragma once
void PrintDifficultyMenu(); //prints the difficulties to the user.
void GetDifficulty(); //gets the user's requested difficulty.

void GenerateCode(); //generated the random code the user will guess.
void GenerateExclusiveNumber(int* D, int* numarr); //chooses a digit and makes sure it wasn't chosen already. Entrance claim: gets a pointer to the int where the digit generated will be stored and a pointer to a dynamically allocated array that helps with choosing exclusive numbers.

void GuessGameplay(); //handles the guesses from the user and checks them, while outputting the proper information for the user.
int Validguess(int guess);  //checks if the input from the user when asked for a guess is valid. Entrance claim: receives the user's guess as a int. Exit claim: if the guess is valid, a 1 is returned. Else, returns a 0.
void GenerateValidationConditions(int guess); //generates the answers for code guessing conditions. Entrance claim: receives the user's guess as a int.

void Checkguess(int guess);  //checks if the guess from the user is correct, and if not it outputs the proper info for the user. Entrance claim: receives the user's guess as a int.

void Winner();  //prints an appropriate message for when the player wins.
void Loser();  //prints an appropriate message for when the player loses.
