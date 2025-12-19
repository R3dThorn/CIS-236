// Written by Colin Stachelrodt
// Homework 14: File Processing, pt.2
// Code is a modification of Homework 12: Structures and Enums
// and a continuation of Homework 13: File Processing, pt.1

// Begin headers

#include <stdio.h>
#include <string.h>

#define FILE_NAME "movies.dat"
#define MAX_RECORDS 10

// Begin typedefs

typedef enum
{
	action = 1,
	animation,
	drama,
	fantasy,
	superhero
}
Genre;

typedef struct 
{
	char title[26]; // Max title length 25 characters + null terminator
	unsigned int downloads;
	Genre genre;
}
Movie;

// Begin function prototypes
FILE *openFile ();
void addMovie (FILE *filePtr);
void deleteMovie (FILE *filePtr);
void updateMovie (FILE *filePtr);
void displayMovieInfo (FILE *filePtr);
int  displayMenu ();
// Begin function header definitions

int main
(void)
{
	// Execute openFile() and check to see if the file opened successfully
	FILE *filePtr = openFile();
	if(!filePtr)
	{
		printf("Failed to open the file. Exiting...\n");
		return 1;
	}
	
	// call displayMenu and use its return value to determine if the main while loop should continue
	int choice = displayMenu();
	
	// Switch selection structure to determine which function to call, and call displayMenu in the event of an invalid input.
	while(choice != 5)
	{
		switch (choice)
		{
            case 1:
                addMovie(filePtr);
                break;
            case 2:
                deleteMovie(filePtr);
                break;
            case 3:
                updateMovie(filePtr);
                break;
            case 4:
                displayMovieInfo(filePtr);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
        choice = displayMenu();
	}
	
    // After the loop, close the file
    fclose(filePtr);
	return 0;
}

// openFile returns a file pointer
FILE *openFile()
{
	// Attempt to open the binary file "movies.dat" at the specified address and check to see if creation was successful. Return NULL if not.
	FILE *filePtr = fopen(FILE_NAME, "wb");
	if (filePtr == NULL)
	{
		puts("File could not be created.\n");
		return NULL;
	}
	
	// Create blank movie structure with default values
	Movie blank = {"", 0, action};
	// and fill the file with 10 of these blank records
	size_t i;
	for(i = 0; i < MAX_RECORDS; i++)
	{
		fwrite(&blank, sizeof(Movie), 1, filePtr);
	}
	// Close the file
	fclose(filePtr);
	
	// Then reopen the file for writing, checking to see if the file opened successfully.
	filePtr = fopen(FILE_NAME, "rb+");
	if(!filePtr)
	{
		printf("Failed to open file for writing.\n");
		return NULL;
	}
	
	// return file pointer
	return filePtr;
}

void addMovie
(FILE *filePtr)
{
	Movie movie;
	char buffer[200];
	
	// Get movie title
	printf("\nTitle of movie (max 25 chars): ");
	fgets(buffer, sizeof(buffer), stdin);
	// look for the newline character and swap it with a null terminator
	buffer[strcspn(buffer, "\n")] = '\0';
	
	// Give warning of title length exceeds 25 characters
	if (strlen(buffer) > 25)
	{
		printf("Title exceeds 25 characters and will be trunctated.\n");
	}
	
	// copy title info into movie structure
	strncpy(movie.title, buffer, 25);
	movie.title[25] = '\0';
	
	
	// Get movie downloads
	printf("Number of downloads: ");
	scanf("%u", &movie.downloads);
	getchar();
	
	// Get movie genre as int for enum constant
	printf("Add genre info (1 = action, 2 = animation, 3 = drama, 4 = fantasy, 5 = superhero): ");
	int g;
	scanf("%d", &g);
	getchar();
	// Handle invalid input
	if (g < action || g > superhero)
	{
		printf("Invalid genre. Try again: ");
		scanf("%d", g);
		getchar();
	}
	
	// Assign integer to movie struct genre
	movie.genre = g;
	
	// Reset file read to beginning of file to begin search algorithm for first available empty record
	rewind(filePtr);
	// Create a temp Movie struct to use for comparison purposes
	Movie temp;
	size_t i;
	for (i = 0; i < MAX_RECORDS; i++)
	{
		fread(&temp, sizeof(Movie), 1, filePtr);
		// If currently loaded record is blank in the first section of the char array, assume record is blank
		// and proceed to override blank with inputted information
		if (temp.title[0] == '\0')
		{
			fseek(filePtr, i * sizeof(Movie), SEEK_SET);
			fwrite(&movie, sizeof(Movie), 1, filePtr);
			printf("Movie added successfully\n\n");
			return;
		}
	}
	
	printf("File is full. Delete an existing record.\n\n");
}

void deleteMovie
(FILE *filePtr)
{
	int userIn;
	printf("Which movie to delete? (1 - 10): ");
	scanf("%d", &userIn);
	getchar();
	
	// This loop handles invalid inputs
	while(userIn < 1 || userIn > MAX_RECORDS)
	{
		printf("Invalid choice. Enter a number between 1 and 10: ");
		scanf("%d", &userIn);
		getchar();
	}
	
	// Checking to see if selection is blank. End function and go back to main menu on error
	Movie temp;
	fseek(filePtr, (userIn - 1) * sizeof(Movie), SEEK_SET);
	fread(&temp, sizeof(Movie), 1, filePtr);

	if (temp.title[0] == '\0')
	{
		printf("Movie entry does not exist\n\n");
		return;
	}
	
	// Override successful entry detect with a blank and give success message
	Movie blank = {"", 0, action};
	fseek(filePtr, (userIn - 1) * sizeof(Movie), SEEK_SET);
	fwrite(&blank, sizeof(Movie), 1, filePtr);
	printf("Movie deleted successfully\n\n");
}
void updateMovie
(FILE *filePtr)
{
	// Literally just the same beginning code as above with a few tweaks
	int userIn;
	printf("Which movie to update? (1 - 10): ");
	scanf("%d", &userIn);
	getchar();
	
	// This loop handles invalid inputs
	while(userIn < 1 || userIn > MAX_RECORDS)
	{
		printf("Invalid choice. Enter a number between 1 and 10: ");
		scanf("%d", &userIn);
		getchar();
	}
	
	Movie temp;
	fseek(filePtr, (userIn - 1) * sizeof(Movie), SEEK_SET);
	fread(&temp, sizeof(Movie), 1, filePtr);
	if (temp.title[0] == '\0')
	{
		printf("Movie entry does not exist\n\n");
		return;
	}
	
	// Here are where the differences begin
	printf("Current title: %s\n", temp.title);
	printf("Current downloads: %u\n", temp.downloads);
	
	// Copied this portion from the addMovie function
	char buffer[200];
	
	// Get movie title
	printf("Updated title of movie (max 25 chars): ");
	fgets(buffer, sizeof(buffer), stdin);
	// look for the newline character and swap it with a null terminator
	buffer[strcspn(buffer, "\n")] = '\0';
	
	// Give warning of title length exceeds 25 characters
	if (strlen(buffer) > 25)
	{
		printf("Title exceeds 25 characters and will be trunctated.\n");
	}
	
	// copy title info into movie structure
	strncpy(temp.title, buffer, 25);
	temp.title[25] = '\0';
	
	
	// Get movie downloads
	printf("Updated downloads: ");
	scanf("%u", &temp.downloads);
	getchar();
	
	// Get movie genre as int for enum constant
	printf("Updated genre (1 = action, 2 = animation, 3 = drama, 4 = fantasy, 5 = superhero): ");
	int g;
	scanf("%d", &g);
	getchar();
	// Handle invalid input
	if (g < action || g > superhero)
	{
		printf("Invalid genre. Try again: ");
		scanf("%d", g);
		getchar();
	}
	temp.genre = g;
	
	fseek(filePtr, (userIn - 1) * sizeof(Movie), SEEK_SET);
	fwrite(&temp, sizeof(Movie), 1, filePtr);
	
	printf("Movie updated successfully\n\n");
}

void displayMovieInfo
(FILE *filePtr)
{
	rewind(filePtr);
	Movie movie;
	int order = 1;
	
	printf("%-6s %25s %12s %10s\n", "Number", "Title", "Downloads", "Genre");
	size_t s; // s for squiggle! though i could've used t for tilde. 56 because i just did the math. it's bad coding, i know. but this was the best i could come up with.
	for (s = 0; s < 56; s++)
	{
		printf("~");
	}
	printf("\n");
	size_t i;
	for (i = 0; i < MAX_RECORDS; ++i)
	{
		fread(&movie, sizeof(Movie), 1, filePtr);
		if(movie.title[0] != '\0')
		{
			printf("%6d %25s %12u ", order, movie.title, movie.downloads);
			switch(movie.genre)
			{
				case action: 
					printf("%10s\n", "Action"); 
					break;
				case animation:
					printf("%10s\n", "Animation");
					break;
				case drama:
					printf("%10s\n", "Drama");
					break;
				case fantasy:
					printf("%10s\n", "Fantasy");
					break;
				case superhero:
					printf("%10s\n", "Superhero");
					break;					
			}
		}
		order++;
	}
	printf("\n");
}

// displayMenu returns an int representing the user's choice
int displayMenu()
{
	int choice;
    printf("%-13s%s%13s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", " ", "MAIN MENU", " ");
    printf("Choose from the following menu options:\n");
    printf("1. Add a movie\n");
    printf("2. Delete a movie\n");
    printf("3. Update a movie\n");
    printf("4. Display all movies\n");
    printf("5. Exit\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}
