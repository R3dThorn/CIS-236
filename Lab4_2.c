// Written by Colin Stachelrodt
// Lab 4-2: Repetition
// Initial code copied from assignment

/*
03 Lab 02 Repetition
Create a sentinel-controlled repetition structure that
executes until the user types -1.
The loop should prompt the user for an integer.
Within the loop, keep a total of the integers entered.
After the loop, print the total.
Do not use break!
*/
#include <stdio.h>
int main(void)
{
	int num;
	int total = 0; //always initialize totals to 0
	//Remember the 3 parts of a loop:
	// 1) initialize LCV
	// 2) test LCV
	// 3) update LCV
	printf("Type a number: ");
	// STEP 1: Write the statement that reads user input
	// and saves it into the variable num
	scanf("%d", &num);
	// STEP 2: Complete the condition inside the parentheses
	while(num != -1)
	{
		total += num;
		printf("Type a number: ");
		// STEP 3: Copy the statement from STEP 1 here
		fflush(stdin);
		scanf("%d", &num);
	}
	printf("The total is %d", total);
	return(0);
}

