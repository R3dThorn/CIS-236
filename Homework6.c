// Written by Colin Stachelrodt
// Homework 6 - Arrays pt.1

/*
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~
	1. Implement a selection control structure.
	2. Implement a repetition control structure.
	3. Use an array to store related data.
	4. Implement functions with input arguments and return value.
	5. Display formatted output to stdout.
	
	Requirements
	~~~~~~~~~~~~
	Create a symbolinc constant to represent the size of the array.
*/
#include <stdio.h>
#define SIZE 6 // I wanted to name this 'VI' like the Roman Numeral, but I figured I should be somewhat serious on this attempt.

// prototype time
void partyHP(int a, int b[]); // a function that returns no value that takes 2 parameters, one int, one int array
void partyTotal(int a[]); // a function that returns no value that takes 1 parameter: one int array

int main (void){
	int hpArray[SIZE] = {0, 0, 0, 0, 0, 0}; // Initialize an array of 6 zeros
	int quit = -1; // Set value to break below loop
	int userInput; // userInput
	
	// Sentinel-controlled loop, checking every userInput against the predefined quit value -1
	while (userInput != quit){
		printf("Player HP Points (-1 to quit): ");
		scanf("%d", &userInput);
		partyHP(userInput, hpArray); // Function call to evaluate how to handle the input. 
		
		// For some reason, letters in any combination were evaluated as being 0 by the function. Why is that? 
		// I thought it would've evaluated them as their ASCII code value... is it recording a 0 due to
		// not expecting a 'char' type input?
		
		fflush(stdin);
	}
	partyTotal(hpArray); // When the loop breaks, main calls this function to print the totals and then quits out.
	return (0);
}

void partyHP(int HP, int hpArray[])
{
	int test; // Needed a variable to help simplify HP down for the switch statement. 
			  // I probably could've used the <math.h> header
			  // and rounded HP/10 and evaluated from there, but I wanted to challenge myself to reduce my
			  // overhead as much as possible.
			  
	if (HP == -1){
		test = -1; // short sweet and to the point to quit out
	} else if (HP >= 50){
		test = 5; // simplifies a lot of thinking here
	} else {
		test  = HP/10; // because test is an int, this math gets truncated to the unrounded ones-place digit
	}
	// This switch statement handles the possible inputs and adjusts the array based on value
	// Only possible inputs are: -1, 0, 1, 2, 3, 4, 5. default for error handling.
	switch (test){
		case -1: 
			break;
		case 0: 
			hpArray[0] += 1; 
			break;
		case 1: 
			hpArray[1] += 1; 
			break;
		case 2: 
			hpArray[2] += 1; 
			break;
		case 3: 
			hpArray[3] += 1; 
			break;
		case 4: 
			hpArray[4] += 1; 
			break;
		case 5: 
			hpArray[5] +=1; 
			break;
		default: 
			printf("i'm just as confused as you are. try again?\n");
	}
}

void partyTotal(int hpArray[]) // Prints the recorded HPs using a repetition structure in the for loop
{
	printf("\nT O T A L S\n");
	printf("-----------\n");
	for (int i = 0; i < SIZE; i++)
		printf("Level %d    %d\n", i+1, hpArray[i]);
}
