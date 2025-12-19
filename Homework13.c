// Written by Colin Stachelrodt
// Homework 13: File Processing, pt.1
// Code is a modification of Homework 12: Structures and Enums

#include <stdio.h>
#include <string.h>

#define SIZE 5

// Begin typedefs

typedef enum
{
	action,
	animation, // animation isn't a genre! it is an medium!
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

void getMovies(Movie *movie);
void printDetails(Movie list[]);
void writeToFile(Movie list[]);

// Begin function header definitions

int main
(void)
{
	// declare array of Movie structs of size 5
	Movie list[SIZE];
	
	// call function 1
	getMovies(list);
	
	// call function 2
	printDetails(list);
	
	// call function 3
	writeToFile(list);
	
	return 0;
}

void getMovies
(Movie *movies)
{
	FILE *filePtr = fopen("C:\\Users\\Colin\\OneDrive\\Documents\\Code\\CIS 236\\13 - Homework Data Files\\DataFileExtraCredit_includes_genre_as_num.txt", "r");
	
	// handle file open error
	if (filePtr == NULL)
	{
		puts("File could not be opened.");
		return;
	}
	
	size_t i = 0;
	
	// This was the only section that I struggled with.
	// I'm still struggling a bit with the concept of passing-by-reference
	// but I think I'm getting the hang of it by now
	
	while(!feof(filePtr) && i < SIZE)
	{
		fscanf
		(
			filePtr, 
			"%25s %u %d",
			movies[i].title,
			&movies[i].downloads,
			&movies[i].genre
		);
		
		
		movies[i].title[25] = '\0';
		
		i++; 
	}
	
	fclose(filePtr);
}

// Literally didn't touch a thing on this function
// thought about reconfiguring it so that downloads and genre
// were right-aligned, but it looked weird so i undid it
void printDetails
(Movie list[])
{
	printf("\n%-25s %-12s %-10s\n", "Title", "Downloads", "Genre");
	printf("-----------------------------------------------------\n");
	
	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("%-25s %-12u ", list[i].title, list[i].downloads);
		switch (list[i].genre)
		{
			case action:
				printf("Action");
				break;
			case animation:
				printf("Animation");
				break;
			case drama:
				printf("Drama");
				break;
			case fantasy:
				printf("Fantasy");
				break;
			case superhero:
				printf("Superhero");
				break;
		}
		printf("\n");
	}
}

void writeToFile
(Movie movies[])
{
	// Create output file if one doesn't exist called "movies_output"
	FILE *filePtr = fopen("C:\\Users\\Colin\\OneDrive\\Documents\\Code\\CIS 236\\13 - Homework Data Files\\movies_output.txt", "w");
	if (filePtr == NULL)
	{
		printf("Error creating output file.\n");
		return;
	}
	
	size_t i;
	for(i = 0; i < SIZE; i++)
	{
		fprintf
		(
			filePtr,
			"%s %d %d\n",
			movies[i].title,
			movies[i].downloads,
			movies[i].genre
		);
	}
	fclose(filePtr);
}
