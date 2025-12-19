// Written by Colin Stachelrodt
// Lab 3, part 1

/*
Write a single-selection statement that adds 10 to a
number if the number is more than 100.
Follow the steps in the code below.
*/

#include <stdio.h>

int
main (void)
{
//	STEP 1 - assign a value that is less than 100 to number:
	int number = 113;
	
//	STEP 2 - write a single selection statement that adds 10
//  to this number is it is more than 100.
	
	if (number >= 100){
		number = number + 10;
	};
	
//  STEP 3 - Compile and run and observe the results.
	printf("Number: %d", number);
	
//  STEP 4 - Change the value in STEP 1 to a number greater than 100.
// 				Compile and run and observe the results
	
	/*
	Student observations:
	First number assignment was 75. Result of compile and run returned 75.
	
	Second number assignment was 113. Result of compile and run returned 123.
	*/
	return (0);
}
