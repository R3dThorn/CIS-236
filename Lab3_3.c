/*
The following code will print the name of a college major when the
user inputs the first letter. The first letter can be upper or lowercase.

Refactor the switch statement into the multiple-alternative format
of the if statement.

You must also use the logical || operator to combine
the two simple conditions that must be checked in each if.
*/

#include <stdio.h>

int
main (void)
{
	int major;

	printf("%s", "Type the first letter of a major: ");
	scanf ("%c", &major);
	/*
	switch(major)
	{
		// If either the lowercase c or the uppercase C, print Cybersecurity
		case 'c':
		case 'C':
			printf("%s\n", "Cybersecurity");
			break;
		// If either the lowercase s or the uppercase S, print Computer science
		case 's':
		case 'S':
			printf("%s\n", "Computer science");
			break;
		// If either the lowercase n or the uppercase N, print Networking
		case 'n':
		case 'N':
			printf("%s\n", "Networking");
			break;
		// If either the lowercase w or the uppercase W, print Web development
		case 'w':
		case 'W':
			printf("%s\n", "Web development");
			break;
		// If none of the above, print Invalid major
		default:
			printf("%s\n", "Invalid major");
	}
	*/

	if (major == 'c' || major == 'C'){
		printf("\nCybersecurity");
	}
	else if (major == 's'|| major == 'S'){
		printf("\nComputer science");	
	}
	else if (major == 'n'|| major == 'N'){
		printf("%c,\nNetworking", major);
	}
	else if (major == 'w'|| major == 'W'){
		printf("%c,\nWeb development", major);
	}
	else{
		printf("%c,\nInvalid major", major);
	}
	
	return (0);
// Student note: I am aware that the return statement is depreciated.
// I am going to use it anyway. It just feels right.
// If this will be a problem, please let me know and I will act accordingly on future assignments.
}
