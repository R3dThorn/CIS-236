// Written by Colin Stachelrodt
// Lab 13: File Processing, pt.1
// Initial code copied from assignment

#include <stdio.h>
#include <string.h>

int main()
{
	// STEP 1 - Open the data file 13LabData.txt in a text editor and
	// observe its contents. Determine which character is the
	// separator character.
	
	// STEP 2 - Write the statement to open this data file FOR READING.
	// Use the variable name filePtr.
	FILE *filePtr = fopen("C:\\Users\\Colin\\Downloads\\13LabData.txt", "r");
	
	if (filePtr == NULL)
	{
		puts("File could not be opened.");
		return 1;
	}
	
	int index = 0;
	
	// This is a list of strings. Each row in this list will hold one
	// line of data from the data file.
	char book_info[11][100];
	
	// STEP 3 - Write the statement to read ONE LINE of this file, and store
	// what is read in book_info[index]. Use 100 for the number of
	// characters to read.
	fgets(book_info[index], 100, filePtr);
	
	// The loop below will continue to read from the file until the EOF.
	while ( ! feof(filePtr) )
	{
		index++;
		
		// STEP 4 - Copy the statement from step 3 here.
		fgets(book_info[index], 100, filePtr);
	}
	
	// STEP 5 - Write the statement that closes the data file.
	// This loop will read each row in the list of strings.
	fclose(filePtr);
		
	for (index = 0; index < 10; index++)
	{
		// STEP 6 - Write a statement to print the value of book_info[index]
		printf("\nLINE %d: %s\n", index + 1, book_info[index]);
		
		// STEP 7 - Complete the strtok function call below. The words "parameter 2"
		// must be replaced with the separator character you observed in Step 1.
		// Be sure to use double-quotes around this character.
		
		char *tokenPtr = strtok(book_info[index], ",");
		
		// The loop below will continue tokenizing the string until tokenPtr becomes NULL
		while (tokenPtr != NULL)
		{
			printf("%s\n", tokenPtr);
			// STEP 8 - Replace the words "parameter 2" with the separator character
			tokenPtr = strtok(NULL, ",");
		}
	}
	return 0;
}

