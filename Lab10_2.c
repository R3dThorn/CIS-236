// Written by Colin Stachelrodt
// Lab 10-1: Pointers, pt.2
// Initial code copied from assignment

/* 10 Lab 2 - Pointers, Part 2
* This lab demonstrates printing the addresses of array elements.
* Refer to slides 21-50 and example fig07_20.c
*/

// Student Note: I was trying to use the sizeof operator for the value in the for loop,
// but it kept returning that the size of array was 40 and the size of *ptr was 8.
// I ended up using the defined variable to make this code work.
// I really shouldn't take a nap before I have assignments due... lesson learned hahaha.


#include <stdio.h>
#define ARRAY_SIZE 10

int main() 
{
	int array[] = {8,1,5,2,8,0,2,4,8,6};
	printf("Addresses printed using the address of each array element:\n");
	//STEP 1
	// Use a loop to print the value and address of each element in the above array.
	// The loop must use the array name.
	// The output must look like this (actual address may vary):
	// Index 0: value = 8, address = 62fde0
	// Index 1: value = 1, address = 62fde4
	// Index 2: value = 5, address = 62fde8
	// Index 3: value = 2, address = 62fdec
	// Index 4: value = 8, address = 62fdf0
	// Index 5: value = 0, address = 62fdf4
	// Index 6: value = 2, address = 62fdf8
	// Index 7: value = 4, address = 62fdfc
	// Index 8: value = 8, address = 62fe00
	// Index 9: value = 6, address = 62fe04
	// Your loop here:
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		printf("Index %d: value = %d, address = %x\n", i, array[i], &array[i]);
	}
	printf("\nAddresses printed using a pointer to each array element:\n");
	
	int * ptr = array;
	//STEP 2
	// Use a loop to print the value and address of each element in the above array.
	// The loop must use the ptr pointer declared above.
	// The output must look like this (actual address may vary):
	// Index 0: value = 8, address = 62fde0
	// Index 1: value = 1, address = 62fde4
	// Index 2: value = 5, address = 62fde8
	// Index 3: value = 2, address = 62fdec
	// Index 4: value = 8, address = 62fdf0
	// Index 5: value = 0, address = 62fdf4
	// Index 6: value = 2, address = 62fdf8
	// Index 7: value = 4, address = 62fdfc
	// Index 8: value = 8, address = 62fe00
	// Index 9: value = 6, address = 62fe04
	// Your loop here:
	
	int j;
	for (j = 0; j < ARRAY_SIZE; j++)
	{
		printf("Index %d: value = %d, address = %x\n", j, ptr[j], &ptr[j]);
	}
	
	
}
