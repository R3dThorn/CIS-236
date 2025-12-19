// Written by Colin Stachelrodt
// Lab 5-1: Functions
// Initial code copied from instructions

#include <stdio.h>
/*You only need to write THREE LINES OF CODE to complete this project! */
/*PART 1:
	Write the function prototype for the function print_results.
	This function requires three parameters that are all integers.
	It does not return a result.
*/
//Complete this FUNCTION PROTOTYPE:
void print_results (int, int, int); 
/*
	To the professor:
	
	The textbook says that the above is perfectly valid
	as the compiler throws out any variable names in the parameters
	of a prototype anyway. Going forward, would you like to see
	dummy variable names in the prototype's parameters? If not, I'm going to
	continue to declare my prototypes like above, as I like
	to be as concise as I can while coding.
*/

int
main(void)
{
	int num1;
	int num2;
	
	puts("Enter the first number: ");
	scanf("%d", &num1);
	
	puts("Enter the second number: ");
	scanf("%d", &num2);
	
	/*PART 2:
	Write the function call to the function print_results.
	*/
	
	//Complete this FUNCTION CALL:
	int sum = num1 + num2;
	print_results(num1, num2, sum); // Just filled out the parameters here
}
/*PART 3:
	Complete the function header with the correct parameters. Refer to the prototype
	you wrote above for the correct order and data types of these parameters. Refer to
	the statements in the function body below for the correct names for these
	parameters.
*/
//Complete this FUNCTION HEADER:
void print_results(int n1, int n2, int sum) // filled out the data types and parameters here to match the sample code's variables
{
	printf("The sum of %d and %d is %d", n1, n2, sum);
}

