// Written by Colin Stachelrodt
// Lab 9-2: Pointers pt.1
// Original code copied from assignment

/* 09 Lab 02 - Pointers, Part 1
This lab creates and calls a function to determine the sum of
two numbers, using 2 input parameters and 1 output parameter.
Complete the four steps below
*/
#include <stdio.h>
// STEP 3 - complete the prototype for the computeSum function.
// This function requires:
// - 2 input parameters (both ints)
// - 1 output parameter to an int (this will be used for the sum)
void computeSum(int *a, int *b, int *c);

int main() 
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	printf("Type two numbers: ");
	scanf("%d %d", &num1, &num2); // Has the ampersand that we use here been a pointer operand this whole time?
	
	// STEP 4 - Complete this function call
	computeSum(&num1, &num2, &sum);
	printf("The sum of %d and %d is %d\n", num1, num2, sum);
}

//STEP 1 - complete the header for the computeSum function.
//This function requires:
// - 2 input parameters (both ints)
// - 1 output parameter to an int (this will be used for the sum)
// - use meaningful names

void computeSum(int *inPtr1, int *inPtr2, int *sumPtr) // Is it best practice to pass by reference, or by value? This seems like a case where passing by value would be more intuitive.
													   // Can I blend pass by reference and by value? i.e. (int input1, int input2, int *sumPtr) or do I have to do all the same type
													   
													   // Also, I understand how evaluation by pass-by-reference is easier on memory due to reduced read steps to perform the same action,
													   // but does that save significant time in longer programs? Is it a relic of older systems that had much more limited memory?
													   // Not a CS major, but I'd be fascinated by the numbers and theory behind it.
{
	*sumPtr = *inPtr1 + *inPtr2;
}

