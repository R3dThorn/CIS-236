// Written by Colin Stachelrodt
// Lab 7-1: Arrays pt.2
// Initial code copied from assignment

// 07 Arrays Part 2 - Lab 01
// Complete a program that uses two parallel arrays to display the number
// of students who have earned a particular letter grade.
// You do not have to use functions.
// The output must display aligned, as shown in the Sample Run section
// at the bottom of this file.
#include <stdio.h>
//STEP 1 - Create a symbolic constant for the size, using the number 5.
#define SIZE 5
int
main(void)
{
	int index;
	//STEP 2 - Create two parallel arrays:
	
	// STEP 2a - Create an array of integers, using the symbolic constant
	// for the size. This array will store counts. Initialize the array
	// using an initialization list containing 1 value: {0}
	int count[SIZE] = {0};
	
	// STEP 2b - Create an array of characters, using the symbolic constant
	// for the size. Initialize the array using an initialization list
	// containing the following values: 'A', 'B', 'C', 'D', 'F'
	// These values represent letter grades.
	char grades[SIZE] = {'A', 'B', 'C', 'D', 'F'};
	// STEP 3 - Finish the loop below that gets data from the user.
	for (index = 0; index < SIZE; index++)
	{
		//STEP 3a - The printf displays the value at the current index of the
		// array of letter grades declared in STEP 2a.
		printf("How many students earned a grade of %c? ", grades[index]);
		//STEP 3b - Complete the scanf using the current element of the student
		// count array declared in STEP 2b.
		scanf("%d", &count[index]);
		fflush(stdin);
	}
	// Print newline
	puts("");
	// Print column headings
	printf("%-8s%-7s\n", "Grade", "Count");
	// STEP 4 - Finish the printf statement within this loop that prints the results:
	// See the sample run below for how this output must be displayed.
	for (index = 0; index < SIZE; index++)
	{
		printf("%-8c%5d\n", grades[index], count[index]);
	}
}
//Sample Run
// Note:
// Each letter grade is displayed left-aligned under the column heading "Grade".
// Each count is displayed right-aligned under the column heading "Count".
//How many students earned a grade of A? 8
//How many students earned a grade of B? 6
//How many students earned a grade of C? 15
//How many students earned a grade of D? 5
//How many students earned a grade of F? 1
//
//Grade Count
//A 8
//B 6
//C 15
//D 5
//F 1

