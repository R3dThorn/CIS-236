// Written by Colin Stachelrodt
// Lab 10-1: Pointers, pt.2
// Initial code copied from assignment

/*
* 10 Lab 1 - Pointers, Part 2
*
* This lab demonstrates the relationship between arrays and pointer variables.
*/
#include <stdio.h>
int main()
{
	// STEP 1 - Create an array of 10 integers. No need to add values to the array.
	int theArray[10] = {0,0,0,0,0,0,0,0,0,0};
	// STEP 2 - Create a pointer to an int. Initialize it to the address of the
	// first element in the array.
	int *thePointer = &theArray[0];
	// STEP 3 - Add the name of the array in place of the empty spot.
	printf("%-44s%x\n", "Address of array, using array name: ", theArray); // 62fe20
	// STEP 4 - Add the pointer variable created in Step 2 in place of the empty spot.
	printf("%-44s%x", "Address of array, using ptr to 1st element: ", thePointer); //62fe20
}
