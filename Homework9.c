// Written by Colin Stachelrodt
// Homework 9 - Pointers, pt.1

// I showed my code to a coworker who has a masters in CS and he critiqued 
// my formatting, so I'm gonna try implementing his feedback in this code.

/*
	Description
	~~~~~~~~~~~~
	Write a program to compute internet charges according to a rate schedule.
	The rate schedule is as follows:
	
	$0.21 per GB for usage between 0 and 140 GB, inclusive
	$0.19 per GB for usage between 141 GB and 170 GB, inclusive
	$0.15 per GB for usage between 171 GB and 210 GB, inclusive
	$0.11 per GB for usage greater than 210 GB
	
	Learning Objectives
	~~~~~~~~~~~~~~~~~~~
	1. Use a selection control structure.
	2. Use functions with input parameters, output parameters, and return values.
	3. Display neatly formatted output to the screen.
	
	Requirements
	~~~~~~~~~~~~
	Your code must use three functions in addition to main. Give these functions meaningful names
	based on their functionality.
	You must use function prototypes. All functions must be defined below main.
*/

/*
	Requirements for main
	~~~~~~~~~~~~~~~~~~~~~
	1. Main calls the functions that implement the functionality of this program:
		a. Function 1 gets the account number and the GB used from the user.
		b. Function 2 calculates the charges.
		c. Function 3 displays the transaction information.
	2. Variable declarations in main should only include the variables needed within main. Do not
	declare all the variables needed in the program here – only the ones needed within main.
	3. Call the appropriate functions with the appropriate arguments. Save any result returned from
	the function as necessary.
	4. All numbers in the output must be right-aligned.
*/
#include <stdio.h>

// Function prototypes
void accountLookup (int *a, int *b);
double calculateCharge (int a);
void displayTransaction( int a, int b, double c);

int main
(void)
{
	// initialization of required variables
	// one for the account number, one for data usage, and one for the total charges
	int accNum = 0;
	int dataUsage = 0;
	double charge = 0;

	accountLookup(&accNum, &dataUsage);
	charge = calculateCharge(dataUsage);
	displayTransaction(accNum, dataUsage, charge);

	return (0);
}

// Function 1: Prompt user for account number and GB usage (integer). No input params, 2 output params, no return value.
void accountLookup
(int *accNum, int *dataUsage)
{
	printf("Enter account number: ");
	scanf("%d", accNum);
	fflush(stdin);
	printf("Enter data usage: ");
	scanf("%d", dataUsage);
	fflush(stdin);
}

// Function 2: Calculate charges based on data usage. One input param, no output params, return value of the charge
double calculateCharge
(int dataUsage)
{
	double rate = 0;
	double charge = 0;
	
	if (dataUsage <= 140)
		rate = 0.21;
	else if (dataUsage >= 141 && dataUsage <= 170) // probably could have written this better but I'm running out of time before work
		rate = 0.19;
	else if (dataUsage >= 171 && dataUsage <= 210)
		rate = 0.15;
	else if (dataUsage > 210)
		rate = 0.11;
	
	charge = dataUsage * rate;
	return charge;
}

// Function 3: Display transaction information. 3 input params, no output params, no return value.
void displayTransaction
(int accNum, int dataUsage, double charge)
{
	printf("\n%-20s%10d\n", "Account Number:", accNum);
    printf("%-20s%10d\n", "GB Used:", dataUsage);
    printf("%-20s%10.2f\n", "Charges ($):", charge);
}
