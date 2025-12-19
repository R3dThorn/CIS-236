// Written by Colin Stachelrodt
// Homework 3: Selection

/*
	Objectives
	~~~~~~~~~~
	1. Implement selection control structures.
	2. Write arithmetic statements using C syntax.
	3. Display neatly formatted output to the screen.
*/

#include <stdio.h>

int main(void){
	
	// initialization of all variables
	float userInTotal;
	char  userSpWear;
	float discount;
	float tax = 0.04;
	float total;
	
	// prompt the user with context for program purpose
	
	printf("The JJC Bookstore is running a promotion!\n");
	printf("Purchase JJC Spirit Wear to get a discount!\n");
	printf("Get a 6%% discount on all purchases with Spirit Wear,\n");
	printf("plus an additional 3%% off on purchases over $100!");
	printf("\n\n");
	
	// Determine if customer will be purchasing JJC Spirit Wear
	printf("Will you be purchasing JJC Spirit Wear? (Y/N) ");
	scanf("%c", &userSpWear);
	fflush(stdin);
	
	// Determine subtotal
	printf("Please enter purchase total of goods before-tax\n");
	printf("to receive your total due at checkout: $");
	scanf("%f", &userInTotal);
	fflush(stdin);
	
	// using if...else statements to logic gate through the possible combinations
	
	if (userSpWear == 'n' || userSpWear == 'N') // No Spirit Wear purchase means no discount
	{
		discount = 0;
	}
	else if (userInTotal < 100 && (userSpWear == 'y' || userSpWear == 'Y')) // Purchase less than $100 with Spirit Wear gets 6% off
	{
		discount = 0.06;
	} 
	else if (userInTotal >= 100 && (userSpWear == 'y' || userSpWear == 'Y')) // Purchase greater than or equal to $100
	{																		 // with Spirit Wear gets 9% off
		discount = 0.09;
	}
	else 
	// I wanted this to reject invalid inputs. See below note.
	{
		printf("Invalid input.");
		return (0);
	}
	
	/*
		Student Note:
		I can't seem to figure out a way to reject non-number
		inputs into userInTotal using my current toolkit.
		Is this a subject covered in an upcoming chapter?
	*/
	
	// Begin receipt formatting
	printf("\n\n");
	printf("************** RECEIPT ***************\n");
	
	// This assignment is declared here specifically so that the Tax
	// and 'Discount Applied" read-outs can capture the discounted subtotal... [1]
	total = userInTotal - (userInTotal * discount);
	
	// Display Subtotal
	printf("Subtotal:                    $%8.2f\n", userInTotal);
	
	// Determine if the Discount lines need to be displayed, and
	// act accordingly.
	if (userSpWear == 'y' || userSpWear == 'Y')
	{
	
	printf("Discount Applied (%.0f%%):      -$%8.2f\n", (discount*100), (userInTotal * discount));
	printf("Subtotal with Discount:      $%8.2f\n", total);
		
	}

	// Tax readout
	printf("Tax (%.0f%%):                    $%8.2f\n", (tax*100), (total * tax));
	
	// [1]... before reusing the same variable to store the Grand Total,
	// which is the discounted total plus the tax on the discounted total.
	total = total + (total * tax);
	
	printf("Grand Total:                 $%8.2f", total);
	
	return (0);
} // end program
