// Written by Colin Stachelrodt
// Lab 7-2: Arrays pt.2
// Initial code copied from assignment



// 07 Arrays Part 2 - Lab 02
// Complete a program that performs a linear search on an array.
#include <stdio.h>
// STEP 2 - Create a symbolic constant using the number noted in STEP 1.
#define SIZE 21
int main()
{
	// STEP 1 - Highlight the text inside the quotes and note the number
	// of characters.
	char data[] = "Joliet Junior College";
	char search_char;
	int index = 0;
	// STEP 3 - Create a variable that will store the index of the
	// character if it is found in the search.
	int charFind = -1;
	// Initialize this variable to -1.
	// If the character is found, this variable will be
	// updated to the index of the character in the array.
	printf("What character do you want to find? ");
	scanf("%c", &search_char);
	fflush(stdin);
	// STEP 4 - Create a while loop using two simple conditions:
	// 4a) The loop hasn't yet reached the end of the array.
	// 4b) The character has not been found.
	//
	// How should these conditions be combined?
	// The loop must continue until the end of the array or
	// until the character is found.
	while (index < SIZE && charFind == -1)
	{
		// STEP 5 - Use an if statement to check if the character
		// at the current index matches the search character.
		// If so, assign the variable created in STEP 3 to
		// the current index.
		if (data[index] == search_char)
			charFind = index;
		// Update the loop control variable
		index++;
	}
	// STEP 6 - Use an if...else statement to print the index where the
	// character was found, or a message stating the character
	// was not found. Use the format in the sample runs below.
	if (charFind == -1)
		printf("Character %c not found", search_char);
	else
		printf("Character %c found at index %d", search_char, charFind);
}
//Sample Runs
//What character do you want to find? J
//Character J found at index 0
//What character do you want to find? u
//Character u found at index 8
//What character do you want to find? z
//Character z not found
