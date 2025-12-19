/* This lab demonstrates creating an enum,
creating a variable of that enum's type,
and checking the value of an enum variable
*/
#include <string.h>
#include <stdio.h>

/* STEP 1 - Create an enum for the body
style of a car. Include these
enum constants: sedan, SUV, van.
*/
enum carBodyType
{
	sedan,
	SUV,
	van
};

int main 
(void)
{
	/* STEP 2 - Create a variable called "choice"
	with the data type of the enum
	created in Step 1.
	*/
	enum carBodyType choice;
	puts("Type 1 for sedan, 2 for SUV, 3 for van: ");
	scanf("%d", &choice);
	/* STEP 3 - Complete the switch statement.
	*/
	
	switch (choice - 1)
	{
		case sedan:
			printf("You have chosen sedan");
			break;
		case SUV:
			printf("You have chosen SUV");
			break;
		case van:
			printf("You have chosen van");
			break;
	}
	return(0);
}
