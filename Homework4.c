// Written by Colin Stachelrodt
// Homework 04 - Repetition

/*
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~~~
	1. Implement a repetition control structure with a nested selection structure.
	2. Use random number generation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	// WHAT DOES THIS MEAN
	srand(time(NULL));
	
	unsigned int quit = 0;
	unsigned int playerIn = 0;
	unsigned int guessCount = 0; // Instructions said this one was necessary
	unsigned int random = 1 + rand() % 10; // One plus the remainder of rand() divided by 10. Possible outcomes are [0 - 9].
										   // If I'm reading this right, rand() generates a number between 1 and 100
	
	// Begin sentinel-control style loop
	do {
		// Prompt for user input.
		// Guess counter gets added up here, before user input is recorded. 
		// Also flushing input here because this will guarantee a clear input memory before each user input.
		printf("Guess a number between 1 and 10!\n");
		++guessCount;
		fflush(stdin);
		
		// For readability in the actual program, this line shows a user input marker.
		printf("> ");
		
		/*
			First compare to see if user input is valid for the test.
			Then evaluate whether player guess is too low, too high, or spot on.
			
			For... some reason... setting the user input as a check condition
			here just... worked. So I designed around it.
		*/
		
		// Also, I tried writting the below if...else chain as a switch statement and I hated it.
			if (scanf("%d", &playerIn) == 0 || playerIn <= 0 || playerIn > 10) { 
			/* 
				"if playerIn is not a number (aka scanf can't parse it as an int), playerIn is less than 
				or equal to 0 or greater than 10, then reject the input."
				
				If input is rejected, print a message to the player and subtract from the counter to "reset" the loop.
			*/
				printf("Invalid input!\n");
				--guessCount;
			}
			else if (playerIn < random) {
				// printout for too low
				printf("Too Low!\n");
			}
			else if (playerIn > random) {
				// printout for too high
				printf("Too High!\n");
			}	
			else {
			// The only other possibility from this logic chain is that playerIn = random.
			
			// I wanted to flush the program console to signal that the "game" is over and the program is about to end.
			// But I don't want to lose points for using methods we haven't covered yet.
			
			// Just gonna leave this here.
			
			// system("cls");
			
			printf("You got it!\n\n");
			printf("Total Number of Guesses: %d", guessCount);
			printf("\n\nThanks for playing!");
			
			// Set sentinel value to exit value to cause program to quit upon successful guess.	
			quit = 1;
			}
	}
	while (quit != 1);
	return (0); // end of program
}
