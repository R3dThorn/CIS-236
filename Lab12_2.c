// Written by Colin Stachelrodt
// Lab 12-1: Structures and Enums
// Initial Code copied from assignment

/* This lab demonstrates creating a structure
that includes an enum. Then a pointer to the
structure is created and the structures
components are accessed.
*/

#include <string.h>
#include <stdio.h>

// STEP 1 - Copy the enum typedef from Lab 01.
typedef enum
{
	sedan = 1,
	SUV,
	van
} carBodyType;

typedef struct {
	/* STEP 2 - Add the three structure components
	listed below. Be sure to use the
	appropriate data type for each component:
	1. make of the car (A make is a word like "Honda")
	2. year of the car
	3. body style of a car (use the enum defined above)
	*/
	char make[20];
	int year;
	carBodyType body;
	
	// STEP 3 - Give this car structure type a name.
} Car;

int
main (void)
{
	/* STEP 4 - Create a variable for a car, using
	the structure type name you created above.
	*/
	Car myCar;
	/* STEP 5 - Create a pointer to the above variable.
	Be sure to assign it a value!
	*/
	Car *carPtr = &myCar;
	/* STEP 6 - Using the pointer variable, assign a value
	to each component of this structure. You
	don't need to ask the user - just assign
	hard-coded values.
	Be sure to use an enum constant for the
	body style.
	*/
	strcpy(carPtr->make, "Toyota");
	carPtr->year = 2021;
	carPtr->body = sedan;
	/* STEP 7 - Using the pointer variable, print each
	component's value.
	Use the enum constant to determine which
	word to print (sedan, SUV, or van).
	*/
	
	printf("Make: %s\n", carPtr->make);
	
	printf("Body style: ");
	switch(carPtr->body)
	{
		case sedan: printf("sedan\n"); break;
		case SUV: printf("SUV\n"); break;
		case van: printf("van\n"); break;
	}
	
	printf("Year: %d", carPtr->year);
	
	return(0);
}
