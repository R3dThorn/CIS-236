// Written by Colin Stachelrodt
// Homework 7: Arrays pt.2

/*
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	1. Use parallel arrays to store related data.
	2. Use functions to handle array access.
	3. Implement a symbolic constant.
	4. Implement linear search.
	
	Requirement – Symbolic Constant
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Create a symbolic constant for the size of the arrays. Use this symbolic constant anywhere
	in the program where you need the array size. The sample runs below use a size of 3, but
	use any size you like.
	
	Requirements for The Main Function
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	1. Create two arrays, using a symbolic constant for the size of each array. One array will
	store product ids (as integers) and the other will store sales figures (as floats).
	2. Call Function 1.
	3. Call Function 2.
	4. Call Function 5.
*/

/*
	Student Notes
	~~~~~~~~~~~~~
	In my initial write-up of this code, I declared the index integers within the for loop's control parenthesis
	and my compiler handled it no problem. I ran into a snag while writing function 2's while loop and needed to
	take a break, so I saved the file as a .c extension. However, when I returned and rewrote the loop, my compiler
	rejected the declarations I made in every for loop, and mandated that I declare the index before the loop, 
	saying that the .c extension was not C11 or C99 compliant (or... something like that. I was a bit too focused on
	finishing the code to care).
	
	Do I need to be worried about C11/C99 compliance quite yet? Or is that a C++ thing?
*/

#include <stdio.h>
#define arraySize 3

// function prototypes
void productIdCheck(int a[]);
void salesCheck(int a[], float b[]);
int  searchArray(int a[], int b);
void salesUpdate(float a[], int b);
void salesTotal(int a[], float b[]);

int main (){
	// two arrays, using symbolic constant for size
	int productId[arraySize];
	float salesFigs[arraySize];
	
	productIdCheck(productId);
	salesCheck(productId, salesFigs);
	salesTotal(productId, salesFigs);
	
	return (0);
}

void productIdCheck(int userIn[]){
	int i;
	for (i = 0; i < arraySize; i++){
		printf("Product ID to store: ");
		scanf("%d", &userIn[i]);
		fflush(stdin);
	}
}

void salesCheck(int productId[], float salesFigs[]){
	int userIn = 0;
	
	while (userIn != -99){
		fflush(stdin);
		printf("\nEnter a Product ID to enter sales data: ");
		scanf("%d", &userIn);
		
		if (userIn == -99)
			printf("");
		else if ( searchArray(productId, userIn) != -1 ){
			int searchResult = searchArray(productId, userIn);
			fflush(stdin);
			salesUpdate(salesFigs, searchResult);
		}
		else {
			printf("Product not found.\n");
		}
	}
}

int searchArray(int productId[], int searchTarget){
	int i;
	for(i = 0; i < arraySize; i++){
		if (searchTarget == productId[i])
		return i;
	}
	
	return (-1);
}

void salesUpdate(float salesFigs[], int targetIndex){
	float userIn;
	printf("Enter the sales: ");
	scanf("%f", &userIn);
	salesFigs[targetIndex] += userIn;
	printf("Sales updated.\n");
	fflush(stdin);
}

void salesTotal(int productId[], float salesFigs[]){
	int i;
	printf("\n%s%13s\n", "Product ID", "Sales");
		for (i = 0; i < arraySize; i++){
		printf("\n%-3d%20.2f", productId[i], salesFigs[i]);
	}
}
