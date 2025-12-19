// Written by Colin Stachelrodt
// Lab 14: File Processing, Pt.2
// Initial code copied from assignment

#include <stdio.h>
#include <string.h> // Initial code was missing this header

typedef struct {
	unsigned int jerseyNum;
	char teamName[15];
	char mascotName[15];
} mascot_t;

int main() {
	// STEP 1 - Create a FILE * variable to open a binary file.
	FILE *filePtr;
	
	// STEP 2 - Write the statement that opens a binary file for WRITING.
	// Use the file name mascots.dat.
	// You do not have to check if the file was opened successfully.
	filePtr = fopen("C:\\Users\\Colin\\OneDrive\\Documents\\Code\\CIS 236\\Lab14\\mascots.dat", "wb");
	
	mascot_t mascot;
	mascot.jerseyNum = 10;
	strcpy(mascot.teamName, "JJC");
	strcpy(mascot.mascotName,"Wiley");
	
	// STEP 3 - Using the file pointer from Step 2, write the statement to
	// write the above mascot structure variable to the file.
	fwrite(&mascot, sizeof(mascot_t), 1, filePtr);
	
	// STEP 4 - Write the statement to close the file
	fclose(filePtr);
	
	// STEP 5 - Write the statement that opens the binary file created above for READING.
	// You do not have to check if the file was opened successfully.
	filePtr = fopen("C:\\Users\\Colin\\OneDrive\\Documents\\Code\\CIS 236\\Lab14\\mascots.dat", "rb");
	
	// STEP 6 - Write the statement to read from the file, and store the data in the
	// structure variable mascot.
	fread(&mascot, sizeof(mascot_t), 1, filePtr);
	
	// STEP 7 - Print the structure data to the screen.
	printf("Jersey #: %u\nTeam: %s\nName: %s\n",
			mascot.jerseyNum, mascot.teamName, mascot.mascotName);
	// STEP 8 - Write the statement to close the file (copy the statement from Step	4).
	fclose(filePtr);
	
	return 0;
}
