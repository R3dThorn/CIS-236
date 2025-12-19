// Written by Colin Stachelrodt
// Homework 10 - Pointers, pt.2

/*
	Student Notes
	~~~~~~~~~~~~~
	
	When writing up the printf statements for the address-printing functions,
	I found that using %d printed a 7-digit string that didn't corrolate with any memory address,
	%x would print the simplified hexadecimal (6-digit), and %p would print the full 16-digit hexadecimal
	memory address.	I defaulted to using %p	because it seemed more correct than %x.
	
	
	I skimmed through the book and realized that use of %p is covered in chapter 9 of the textbook.
	Reverted all uses of %p to %x for this assignment.
*/

/*
	Description
	~~~~~~~~~~~~
	Write a program that prints the values in an array and the addresses of the array’s elements using
	four different techniques, as follows:
		1. Array index notation using array name
		2. Pointer/offset notation using array name
		3. Array index notation using a pointer
		4. Pointer/offset notation using a pointer
	Example fig07_20.c and the lab for this week will be useful guides for this assignment.
	
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~
	1. Use functions with array and pointer arguments
	2. Use indexing and offset notations to access arrays
	
	Requirements
	~~~~~~~~~~~~
	1. Your code must use these eight functions, using these names (in addition to main):
		a. valuesNameIndex
		b. valuesPointerIndex
		c. valuesNameOffset
		d. valuesPointerOffset
		e. addressesNameIndex
		f. addressesPointerIndex
		g. addressesNameOffset
		h. addressesPointerOffset
	2. No other variables should be declared in main, above main, in any function, or in any function
	parameter list except those explicitly noted in the instructions.
	3. You must a symbolic constant for the array size wherever it is needed. Do not create a
	variable for the size.
	4. All output must display exactly as it appears in the sample run. Note that your actual
	addresses may differ.
*/

#include <stdio.h>
#define ARRAY_SIZE 5

// function prototypes
void valuesNameIndex (int a[]);
void valuesPointerIndex (int *a);
void valuesNameOffset (int a[]);
void valuesPointerOffset (int *a);
void addressesNameIndex (int a[]);
void addressesPointerIndex (int *a);
void addressesNameOffset (int a[]);
void addressesPointerOffset (int *a);

/*
	Requirements for The Main Function
	1. Declare and initialize an integer array of size 5. Use the symbolic constant for the size.
	Initialize it with the values 11, 18, 23, 62, and 63.
	2. Call each function with the appropriate argument.
*/

int main
(void)
{
	int theArray[ARRAY_SIZE] = {11, 18, 23, 62, 63};
	
	valuesNameIndex(theArray);
	valuesPointerIndex(theArray);
	valuesNameOffset(theArray);
	valuesPointerOffset(theArray);
	
	addressesNameIndex(theArray);
	addressesPointerIndex(theArray);
	addressesNameOffset(theArray);
	addressesPointerOffset(theArray);
	
}

/*
	Requirements for the valuesNameIndex Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the values in the array.
	Parameter: integer array (square bracket notation)
	Algorithm: 
	1. Print the name of the function.
	2. Print the values of the input array using a loop with array index notation.
	• Be sure to use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	Return value: None
*/

void valuesNameIndex
(int theArray[])
{
	printf("Printing array values from function valuesNameIndex\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %d\n", i, theArray[i]);
	}
}

/*
	Requirements for the valuesPointerIndex Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the values in the array.
	Parameter: Pointer to an int array
	Algorithm: 
	1. Print the name of the function.
	2. Print the values of the input array using a loop with pointer index notation.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	Return value: None
*/
void valuesPointerIndex
(int *theArray)
{
	printf("\nPrinting array values from function valuesPointerIndex\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %d\n", i, theArray[i]);
	}
}

/*
	Requirements for the valuesNameOffset Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the values in the array.
	Parameter: integer array (square bracket notation)
	Algorithm: 
	1. Print the name of the function.
	2. Print the values of the input array using a loop with pointer offset notation using
	the array name.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	Return value: None
*/

void valuesNameOffset
(int theArray[])
{
	printf("\nPrinting array values from function valuesNameOffset\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %d\n", i, *(theArray + i));
	}
}

/*
	Requirements for the valuesPointerOffset Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the values in the array.
	Parameter: Pointer to an int array
	Algorithm: 
	1. Print the name of the function.
	2. Print the values of the input array using a loop with pointer offset notation using
	the pointer.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	Return value: None
*/

void valuesPointerOffset
(int *theArray)
{
	printf("\nPrinting array values from function valuesPointerOffset\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %d\n", i, *(theArray + i));
	}
}

/*
	Requirements for the addressesNameIndex Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the address of each element of the array.
	Parameter: integer array (square bracket notation)
	Algorithm: 
	1. Print the name of the function.
	2. Print the address of each element of the array using a loop with array index
	notation.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	• Use the appropriate format control string for printing addresses.
	Return value: None
*/

void addressesNameIndex
(int theArray[])
{
	printf("\nPrinting array addresses from function addressesNameIndex\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %x\n", i, &theArray[i]);
	}
}

/*
	Requirements for the addressesPointerIndex Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the address of each element of the array.
	Parameter: Pointer to an int array
	Algorithm: 
	1. Print the name of the function.
	2. Print the address of each element of the array using a loop with pointer index
	notation.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	• Use the appropriate format control string for printing addresses.
	Return value: None
*/

void addressesPointerIndex
(int *theArray)
{
	printf("\nPrinting array addresses from function addressesPointerIndex\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %x\n", i, &theArray[i]);
	}
}

/*
	Requirements for the addressesNameOffset Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the address of each element of the array.
	Parameter: integer array (square bracket notation)
	Algorithm: 
	1. Print the name of the function.
	2. Print the address of each element of the array using a loop with pointer offset
	notation using the array name.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	• Use the appropriate format control string for printing addresses.
	Return value: None
*/

void addressesNameOffset
(int theArray[])
{
	printf("\nPrinting array addresses from function addressesNameOffset\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %x\n", i, (theArray + i));
	}
}

/*
	Requirements for the addressesPointerOffset Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Purpose: This function prints the address of each element of the array.
	Parameter: Pointer to an int array
	Algorithm: 
	1. Print the name of the function.
	2. Print the address of each element of the array using a loop with pointer offset
	notation using the pointer.
	• Use the symbolic constant.
	• You must use the parameter.
	• Do not declare any other variables except a loop control variable.
	• Use the appropriate format control string for printing addresses.
	Return value: None
*/

void addressesPointerOffset
(int *theArray)
{
	printf("\nPrinting array addresses from function addressesPointerOffset\n");
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("theArray[%d] = %x\n", i, (theArray + i));
	}
}

