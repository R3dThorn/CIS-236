// Code written by Colin Stachelrodt
// Homework 2: Structured Programming

// Program's main function takes user input for the radius of a circle
// and outputs the circle's area and circumference

/* 
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~
	1. Implement an algorithm in C
	2. Read input from stdin
	3. Perform arithemtic calculations in C
	4. Display formatted output to stdout
*/

#include <stdio.h>

int main (void)
{
	// initialization of global variables
	
	// user input placeholder
	int userInRadius = 0;
	// set constant for pi
	float pi = 3.14;
	
	// Display prompt for user input and set user input to previously declared variable userInRadius
	printf("Enter a value for the radius of a circle in inches: ");
	scanf("%d", &userInRadius);
	
	// initialization of math variables
	
	// A = pi * r^2
	float area = pi * userInRadius * userInRadius;
	// C = pi * d = pi * 2 * r
	float circ = pi * 2 * userInRadius;
	
	// Display result of calculation for area followed by circumference on seperate lines
	printf("\nThe area of a circle with radius %d in inches: %.2f\nThe circumference of a circle with radius %d is %.2f",userInRadius,area,userInRadius,circ);
	
	return (0);
}
