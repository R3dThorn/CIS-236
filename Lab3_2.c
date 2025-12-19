/*
Write a double-selection statement that prints
"true" if the user enters a letter, and false if
the user enters any other character.
*/

#include <stdio.h>

int
main (void)
{
	char user_input;
	
	printf("Type a character: ");
	scanf("%c", &user_input);
	
// Write a double-selection statement that prints
// "true" if the user has entered a letter, and "false" if
// the user has entered any other character.
// You must use a logical condition.

	if ((user_input >= 'a' && user_input <= 'z') || (user_input >= 'A' && user_input <= 'Z'))
	{
		printf("TRUE");
	}
	
	else {
	printf("FALSE");
	}
/*
	Student notes:
	Using double quotes in the if statement's evaluation condition
	caused a compiler error stating that pointers and integers cannot be compared.
	Why do double quotes cause the letter to convert to a pointer,
	and single quotes cause the letter to be evaluated as an integer?
*/
	// a-z, A-Z
	return (0);
}


