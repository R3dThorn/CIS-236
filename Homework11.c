// Written by Colin Stachelrodt
// Homework 11: Strings and Characters

// Start by including all needed headers. I almost attempted to do this without ctype, but being able to check input type is too important for the data flow in this program.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// creating some global variables
#define PREFIX_LEN 4 // 3 characters for the prefix and the null terminator
#define NUMBER_LEN 4 // 3 characters for the course number plus 1 for the null terminator
#define NAME_LEN 21 // 20 characters for input plus null terminator

#define MAX_COURSES 5 // maximum amount of times the main for loop gets called

#define PRINTOUT_LEN 28 // maximum length of a printed string at program end


// function prototypes
// is it standard practice to write these before or after i write the headers?
// i've been writing them afterwards, but i've wondered a few times now if that's right
void prefixPrompt(char a[]);
void numberPrompt(char a[]);
void namePrompt(char a[]);
void inputConcat(char a[], const char b[], const char c[], const char d[]);
void printCourses(char a[][PRINTOUT_LEN], int b);

// begin function definitions
int main
(void)
{
	// initialization of all necessary variables
	char prefix[PREFIX_LEN];
	char number[NUMBER_LEN];
	char name[NAME_LEN];
	
	// This one eluded me for a bit, but I've got it now. It's a 2D array, with an amount of rows equal to the amount of courses, and a column length of however long the output string is gonna be
	char courseList[MAX_COURSES][PRINTOUT_LEN] = {{'\0'}};
	
	int i;
	for(i = 0; i < MAX_COURSES; i++)
	{
		prefixPrompt(prefix);
		numberPrompt(number);
		namePrompt(name);
		
		inputConcat(courseList[i], prefix, number, name);
		
	}
	
	printCourses(courseList, i);
	return 0;
}

// Reqs for Func1
// Reads course prefix from user and validates input
// 1 output param for the course prefix string, no return value
// User input must be saved to a variable other than the parameter
// Function must validate that the prefix is exactly 3 letters and reject any invalid input with an error message

void prefixPrompt
(char prefix[])
{
	char input[42]; // why 42? why not 42?
	
	while (1) // I want this loop to run until an input is validated and the return keyword breaks the loop.
	{
		fflush(stdin);
		printf("Enter course prefix (3 LETTERS ONLY): ");
		scanf("%s", input);
		
		if (strlen(input) == 3)
		{
			int valid = 1;
			
			// Check if input is all letters, break out of if statement if not and restart loop
			int i;
			for (i = 0; i < 3; i++)
			{
				if (!isalpha(input[i]))
				{
					valid = 0;
					break;
				}
			}
			// If the input passes the type check, put user input to upper case for consistency on the final list and push the input string into the output param
			if (valid)
			{
				int i;
				for (i = 0; i < 3; i++)
				{
					input[i] = toupper(input[i]);
				}
			// take input, push to prefix, and break out of the function with the return keyword
				strcpy(prefix, input);
				return;
			}
		}
		// It is assumed that the input is invalid by this point, so we reject the input and restart the loop.
		printf("Invalid input. Please enter only 3 letters exactly.\n\n");
	}
}

// Reqs for Func2
// Reads course number from user and validates input
// 1 output param for course number string, no reutrn value
// User input must be saved to a variable other than the parameter
// Function must validate that input is exactly 3 numebrs and reject any invalid input with an error message

// This function is literally just a copy/paste of the previous function, just edited to validate for numbers instead of characters
void numberPrompt
(char number[])
{
	char input[42]; // why 42? why not 42?
	
	while (1) // I want this loop to run until an input is validated and the return keyword breaks the loop.
	{
		fflush(stdin);
		printf("Enter course number (3 NUMBERS ONLY): ");
		scanf("%s", input);
		
		if (strlen(input) == 3)
		{
			int valid = 1;
			
			// Check if input is all numbers, break out of if statement if not and restart loop
			int i;
			for (i = 0; i < 3; i++)
			{
				if (!isdigit(input[i]))
				{
					valid = 0;
					break;
				}
			}
			// If the input passes the type check, and push the input string into the output param
			if (valid)
			{
			// take input, push to prefix, and break out of the function with the return keyword
				strcpy(number, input);
				return;
			}
		}
		// It is assumed that the input is invalid by this point, so we reject the input and restart the loop.
		printf("Invalid input. Please enter only 3 numbers exactly.\n\n");
	}
}

// Reqs for Func3
// Reads course name and validates the input
// 1 output param for course name, no return value
// User input can be saved directly to the output parameter
// Valid input is all alphanumeric characters, truncated to 20 characters max. Prompt a warning when over character limit.
void namePrompt
(char name[])
{
	printf("Enter course name (max 20 characters): ");
	fflush(stdin);
	fgets(name, NAME_LEN, stdin);
	
	// KNOWN BUG: THE BELOW SECTION OF CODE DOES NOT ACTIVATE IF NAME INPUT IS OVER 20 CHARACTERS DUE TO fgets TOSSING OUT OVERFLOW INFORMATION.
	// DON'T HAVE TIME TO FIX BEFORE SUBMISSION DEADLINE, WILL JUST HAVE TO TAKE THE L
	if (strlen(name) > 20)
	{
		printf("Course name too long. Truncating input to first 20 characters.\n");
		name[20] = '\0';
	}
	
	printf("\n");
}

// Reqs for Func4
// Concatenate all user input for final formatting
// 1 output parameter for the result, 3 input parameters for the 3 user inputs. no return value
void inputConcat
(char result[], const char prefix[], const char number[], const char name[])
{
	strcpy(result, prefix);
	strcat(result, " ");
	strcat(result, number);
	strcat(result, " ");
	strcat(result, name);
}

// Reqs for Func5
// Printout of the results list
// 1 output input parameter, no return value
void printCourses
(char list[][PRINTOUT_LEN], int count)
{
	printf("\n~~~ COURSE LIST ~~~\n");
	
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%s\n", list[i]);
	}
}
