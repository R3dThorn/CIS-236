// Written by Colin Stachelrodt
// Lab 5-2: Functions
// Initial code copied from instructions

#include <stdio.h>
/*You only need to write FOUR LINES OF CODE to complete this project! */

/*PART 1:
Write the function prototype for the function compute_results.
This function requires two parameters that are both integers.
It returns an integer result.
*/

//Complete this FUNCTION PROTOTYPE:
int compute_results(int ,int); // Like the previous lab, I'm just declaring the data types here

int
main(void)
{
	int num1;
	int num2;
	int sum;
	
	puts("Enter the first number: ");
	scanf("%d", &num1);
	
	puts("Enter the second number: ");
	scanf("%d", &num2);
	
	/*PART 2:
	Write the function call to the function compute_results.
	Since the function returns a result, it must be part of an
	assignment statement.
	*/
	
	//Complete this FUNCTION CALL:
	sum = compute_results(num1, num2); // assignment of sum to the value returned from the function call
	printf("The sum of %d and %d is %d", num1, num2, sum);
}
/*PART 3:
Complete the function header with the correct parameters. Refer to the prototype
you wrote above for the correct order and data types of these parameters. Refer to
the statements in the function body below for the correct names for these
parameters.
*/
//Complete this FUNCTION HEADER:
int compute_results(int n1,int n2) // declared expected data type in front of function name and declared parameter names and data types
{
	int sum = n1 + n2;
	/*PART 4: Write the statement that sends the result
	back to the code that called this function.
	*/
	return sum; // it just returns the sum... duh!
}
/*
	Regarding the use of 'sum' both in the body of main and in compute_results:
	
	Are both 'sum' variables looking at different pointers, which is why I can use
	the same varaible name in 'main' and 'compute_results' without a conflict of address?
*/

