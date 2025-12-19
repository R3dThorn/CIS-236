// Written by Colin Stachelrodt
// Lab 6-1: Arrays
// Initial code copied from assignment

// 06 Lab 01 Arrays Part 1
// Complete a program that saves user input into an array, computes the average,
// and prints the values of the elements of the array to the screen in opposite
// order.
//
//You do not have to use functions or create attractive output.
#include <stdio.h>
#define V 5 // Roman Numeral for 5 because I didn't want to type 'five' over and over again
// STEP 1 - Create a symbolic constant for the number 5:
int
main(void)
{
	int index;
	int total = 0;
	float average;
// STEP 2 - Create an array of five integers here, using the symbolic constant
// defined in Step 1.
	int array[V];
// STEP 3 - Finish the loop below that gets data from the user
// You need to add 3 things:
//  1) the starting index value in the for statement
//  2) the ending index value in the for statement (use the symbolic
//     constant!)
//  3) the correct subscripted variable in the scanf statement (don't forget
//     the &)
	for (index = 0; index < V; index++)
	{
		printf("Type a number: ");
		scanf("%d", &array[index]);
	}
// STEP 4 - Finish the loop below that computes the total of the values in the
// array
// You need to add 3 things:
//  1) the starting index value in the for statement
//  2) the ending index value in the for statement (use the symbolic
//     constant!)
//  3) complete the assignment statement in the loop body to add each
//     element's value to the total
	for (index = 0; index < V; index++)
		total += array[index];
// STEP 5 - Replace the words "size of array" with the symbolic constant
// created in Step 1.
	average = (float)total / V;
	printf("The average of these numbers is %.2f\n\n", average);
	puts("Values in reverse order:");
// STEP 5 - Write a for loop that prints the value of each element
// of the array in the OPPOSITE order from the order in which the values were
// entered.
	for (index = V; index > 0; index--)
		printf("%d\n", array[index - 1]);
}

