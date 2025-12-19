// Written by Colin Stachelrodt
// Lab 6-2: Arrays
// Initial code copied from assignment

/* 06 Lab 02 Arrays, Part 1
	Complete a program that prompts the user for the number of values to use.
	Then save user input into an array. Call a function to compute the average,
	and then print the average returned from the function.
*/

#include <stdio.h>
// STEP 1 - Write the prototype for a function that calculates the average.
// There are 3 values to add here:
// 1) The data type of the return value
// 2) A parameter defining the array
// 3) A parameter defining the size of the array.
float compute_average(int a[], int b); // I now see the value of declaring dummy variables in the prototype

int
main(void)
{
	int index;
	int total=0;
	float average;
	int array_size;
	//Prompts the user for the number of values.
	printf("How many values? ");
	scanf("%d", &array_size);
	// STEP 5 - Create an array of integers here, using the size entered by the
	// user.
	int array[array_size];
	// STEP 6 - Finish the loop below that gets data from the user
	// You need to add 3 things:
	// 1) the starting index value in the for statement
	// 2) the ending index value in the for statement (use the value entered by
	//    the user)
	// 3) the correct subscripted variable in the scanf statement (don't forget
	//    the &)
	for (index = 0; index < array_size; index++)
	{
		printf("Type a number: ");
		scanf("%d", &array[index]);
	}
	//STEP 7 - Complete the call the calculateAverage function and save the
	// result in the variable average.
	
	// Student note: it was called both computer_average and calculateAverage. i decided to
	// default to computer_average because there was less rewritting needed to fix it that way
	average = compute_average(array , array_size);
	printf("The average of these numbers is %.2f\n\n", average);
}
	//STEP 2 - Write the header for the function that calculates the average.
	// There are 3 values to add here:
	// 1) The data type of the return value
	// 2) A parameter defining the array
	// 3) A parameter defining the size of the array.
float compute_average(int array[], int size)
{
	// STEP 3 - Finish the loop below that computes the total of the values in the
	// array
	// You need to add 3 things:
	// 1) the starting index value in the for statement
	// 2) the ending index value in the for statement (use the parameter!)
	// 3) complete the assignment statement in the loop body to add each
	// element's value to the total
	int index;
	int total = 0;
	float average;
	for (index = 0; index < size; index++)
		total += array[index];
	average = (float)total / size;
	// STEP 4 - Write the statement that passes the correct value back to the
	// calling code.
	return average;
}

