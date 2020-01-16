#include <time.h>

#include "C:/Users/albaz/source/repos/Project4/Project4/definitions.c"

int main()
{
	srand(time(NULL));  //makes it so the random things generated in the game are dependant on the time, so each game is different
	PrintDifficultyMenu(); 
	GetDifficulty(); 
    GenerateCode();	
	GuessGameplay(); 
	system("pause");
    return 0;
}