// Written by Colin Stachelrodt
// Lab 9-1: Pointers, pt.1
// Original code copied from assignment

/* 09 Lab 01 - Pointers, Part 1
	This lab demonstrates creating pointer variables and
	displaying the values and addresses of variables and pointers.
*/
#include <stdio.h>
int main()
{
	int the_integer = 10;
	float the_float = 22.22;
	// STEP 1
	// Create 2 pointer variables:
	// 1. A pointer to an int
	int *theIntPtr;
	// 2. A pointer to a float
	float *theFloatPtr;
	// Do not assign them to anything yet.
	
	// STEP 2
	// Assign each pointer to the address of the appropriate variable
	// created at the top of main.
	theIntPtr = &the_integer;
	theFloatPtr = &the_float;
	
	// STEP 3
	// Print the VALUE of each variable created at the top of main.
	printf("The value of the_integer is:\t%d\n", the_integer); // 10
	printf("The value of the_float is:\t%.2f\n\n", the_float); // 22.22
	// STEP 4
	// Print the ADDRESS of each variable created at the top of main.
	printf("The address of the_integer is:\t%x\n", &the_integer); // 62fe3c
	printf("The address of the_float is:\t%x\n\n", &the_float); // 62fe38
	// STEP 5
	// Print the value of each pointer variable created in STEP 1.
	printf("The value of int_ptr is:\t%x\n", theIntPtr); // 62fe3c
	printf("The value of float_ptr is:\t%x\n", theFloatPtr); // 62fe38
	
	printf("the value of the_integer from the value that theIntPtr is pointing to is: \t%d\n", *theIntPtr);
}

