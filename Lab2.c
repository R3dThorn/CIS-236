// Program by Colin Stachelrodt
// Assignment No.2 - Data Types

#include <stdio.h>

int main (void)
{
	int x = 12;
	// Data Type of Variable is int, and 
	// the value stored in the variable is also int
	
	printf("%d",x);
	// prints out whatever the value of "x" is declared to
	// Data Type of int
	
	// Variation #1: int-int-int
	int firstVar = 1;
	
	printf("\n\n%d", firstVar);
	// An int data type with an int value displayed using an int FCS gives the result: 1
	
	// Variation #2: int-int-float
	int secondVar = 2;
	
	printf("\n%.2f", secondVar);
	// An int data type with an int value displayed using a float FCS with 2 points of precision gives the result: 0.00
	
	// Variation #3: int-float-int
	int thirdVar = 3.031;
	
	printf("\n%d", thirdVar);
	// An int data type with a float value displayed using an int FCS gives the result: 3
	
	// Variation #4: int-float-float
	int fourthVar = 4.454;
	
	printf("\n%.2f", fourthVar);
	// An int data type with a float value displayed using a float FCS with 2 points of precision gives the result: 0.00
	
	// Variation #5: float-int-int
	float fifthVar = 42;
	
	printf("\n%d", fifthVar);
	// A float data type with an int value displayed using an int FCS gives the result: 0
	
	// Variation #6: float-int-float
	float sixthVar = 42;
	
	printf("\n%.2f", sixthVar);
	// A float data type with an int value displayed using a float FCS with 2 points of precision gives the result: 42.00
	
	// Variation #7: float-float-int
	float seventhVar = 7.87;
	
	printf("\n%d", seventhVar);
	// A float data type with a float value displayed using an int FCS gives the result: 1073741824
	
	// Variation #8: float-float-float
	float eighthVar = 8.3848;
	
	printf("\n%.2f", eighthVar);
	// A float data type with a float value displayed using a float FCS with 2 points of precision gives the result: 8.38
	
	return (0);
}
