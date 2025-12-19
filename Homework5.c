// Written by Colin Stachelrodt
// Homework 5: Functions
// Original code written by Colin Stachelrodt for Homework 3: Selection

/*
	Objectives
	~~~~~~~~~~
	1. Refactor (restructure) existing code.
	2. Implement programmer-defined functions with inputs and return values
*/

#include <stdio.h>

// prototype time
float userPrompt (void); // Function that has no parameters and returns float outputs
char  userSpirit (void); // Function that has no parameters and returns char outputs
float grandTotal (float, float); // Function that accepts 2 float parameters and returns a float value

int main(void){
	
	// initialization of all variables
	float userTotal;
	char  priceCut;
	float discount = 0;
	float tax = 4;
	float total;
	float taxAmount;
	float discTotal;
	
	// prompt the user with context for program purpose
	
	printf("The JJC Bookstore is running a promotion!\n");
	printf("Purchase JJC Spirit Wear to get a discount!\n");
	printf("Get a 6%% discount on all purchases with Spirit Wear,\n");
	printf("plus an additional 3%% off on purchases over $100!");
	printf("\n\n");
	
	// Swapped below statements in response to feedback from Homework 3
	
	// Function call to prompt the user for the subtotal
	userTotal = userPrompt();

	// Function call to determine if customer will be purchasing JJC Spirit Wear
	priceCut = userSpirit();
	
	// using if...else statements to logic gate through the possible combinations
	
	if (priceCut == 'n' || priceCut == 'N') // No Spirit Wear purchase means no discount
	{
		discount = 0;
	}
	else if (userTotal < 100 && (priceCut == 'y' || priceCut == 'Y')) // Purchase less than $100 with Spirit Wear gets 6% off
	{
		discount = 6;
	} 
	else if (userTotal >= 100 && (priceCut == 'y' || priceCut == 'Y')) // Purchase greater than or equal to $100
	{																		 // with Spirit Wear gets 9% off
		discount = 9;
	}
	else 
	// I wanted this to reject invalid inputs
	{
		printf("Invalid input.");
		return (0);
	}
	
	// Recording the discount total
	discTotal = userTotal - (userTotal * (discount / 100));	
	// Recording the tax amount
	taxAmount = discTotal * (tax / 100);

	// Function call for the final total to be calculated
	total = grandTotal(discTotal, taxAmount);

	// Begin receipt formatting
	printf("\n\n");
	printf("************** RECEIPT ***************\n");
	

	// Display Subtotal
	printf("Subtotal:                    $%8.2f\n", userTotal);
	
	// Determine if the Discount lines need to be displayed, and
	// act accordingly.
	if (priceCut == 'y' || priceCut == 'Y')
	{
	
	printf("Discount Applied (%.0f%%):      -$%8.2f\n", discount, (userTotal * discount / 100));
	printf("Subtotal with Discount:      $%8.2f\n", discTotal);
		
	}

	// Tax readout
	printf("Tax (%.0f%%):                    $%8.2f\n", tax, taxAmount);
	
	// Grand Total readout
	
	printf("Grand Total:                 $%8.2f", total);
	
	return (0);
} 

// function time
float userPrompt (void){
	/*
		Per assignment specs:
		- Function 1 prompts the user for the dollar amount of the purchase and returns it to main.
		- userPrompt in classic noun-Verb camelCase. it prompts the user.
		- No parameters
		- Returns the dollar amount of the purchase
		- Follows the following algorithm:
			1. Prompt user
			2. Save user input
			3. Call fflush
			4. Return user input
	*/
	float userTotal;
	printf("Please enter purchase total of goods before-tax: $"); // 1
	scanf("%f", &userTotal); // 2
	fflush(stdin); // 3
	return userTotal; // 4
}

char  userSpirit (void){
	/*
		Per assignment specs:
		- Function 2 prompts the user as to whether or not they're gonna buy spirit wear, and returns it to main
		- priceCut seems pretty self-explanatory
		- No parameters
		- Returns a char
		- Follows the following algorithm:
		  1. Prompt user
		  2. Save user input
		  3. Call fflush
		  4. Return user input
	*/
	char userIn;
	printf("Will you be purchasing JJC Spirit Wear? (Y/N) >"); // 1
	scanf("%c", &userIn); // 2
	fflush(stdin); // 3
	return userIn; // 4
}

float grandTotal (float total, float tax){
	/*
		Per assignment specs:
		- Function 3 calculates the total purchase amount and returns its value to main
		- grandTotal seems pretty straight-forward
		- Parameters are 2 float inputs; the 1st is the updated/original purchase amount, the 2nd the amount of tax
		- Returns a float
		- Follows the following algorithm:
			Calculate the total purchase amount by adding the purchase amount "total" to the dollar amount of "tax"
	*/
	float totalReturn;
	totalReturn = total + tax;
	return totalReturn;
}
