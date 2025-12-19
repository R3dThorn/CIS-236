// Written by Colin Stachelrodt
// Lab 4-3: Repetition
// Initial code copied from assignment

// 03 Lab 03 - Repetition
// Create a for loop that executes number of times entered by user.
// Each pass through the loop must display the number of times the
// loop has executed so far.
// Declare the loop control variable within the for header, and
// initialize it to 0.
// Example output:
// How many times should this loop execute? 3
// Loop has executed 1 times
// Loop has executed 2 times
// Loop has executed 3 times

#include <stdio.h>
#include <string.h>

int main()
{
	int count;
	// Prompt for the count
	printf("How many times should this loop execute? ");
	scanf("%d", &count);
	// for loop here:
	for(int counter = 1; counter <= count; ++counter)
	{
		printf("Loop has executed %d time(s).\n", counter);
	}
	return (0);
}

