// Written by Colin Stachelrodt
// Homework 12: Structures and Enums

#include <stdio.h>
#include <string.h>

// Begin typedefs

typedef enum
{
	action = 1,
	animation, // animation isn't a genre! it is an medium!
	drama,
	fantasy,
	superhero
}
Genre;

typedef struct 
{
	char title[26]; // Max title length 25 characters + null terminator
	int downloads;
	Genre genre;
}
Movie;

// Begin function prototypes

void getMovieDetails(Movie *movie);
void printDetails(Movie list[], int count);


// Begin function header definitions

int main
(void)
{
	int numMovies = 0;
	
	printf("Enter number of movies to process: ");
	scanf("%d", &numMovies);
	getchar(); // clear buffer of newline character
	
	Movie list[numMovies];
	
	int i;
	for (i = 0; i < numMovies; i++)
	{
		getMovieDetails(&list[i]);
	}
	
	printDetails(list, numMovies);
	
	return 0;
}

void getMovieDetails
(Movie *movie)
{
	char tempTitle[50];
	
	printf("Enter the movie title: ");
	fgets(tempTitle, sizeof(tempTitle), stdin);
	
	// This block checks for and removes the newline character that fgets keeps recording into my title string
	// I needed this for my previous homework assignment... sucks that it took me until now to work it out
	/* 
		To the professor: Is it best practice to use a size_t over an int for indexing? I was reviewing the data types and was astonished to find
		I had missed the section on size_t on page 246 of the textbook, and it notes that "size_t represents an unsigned integral type and is recommended for 
		any variable representing an array’s size or subscripts".
	*/
	size_t len = strlen(tempTitle);
	if (len > 0 && tempTitle[len -1] == '\n')
		tempTitle[len -1] = '\0';
	
	
	if (strlen(tempTitle) > 25)
		printf("Title is too long. Truncating it to the first 25 characters.\n");
		
	strncpy(movie->title, tempTitle, 25);
	movie->title[25] = '\0'; // making sure the title has its terminator
	
	printf("Enter the number of downloads: ");
	scanf("%d", &movie->downloads);
	getchar(); // clear buffer of newline character
	
	int genreInput = 99; // initializing this to a number outside of expecation to make the do...while loop logic work
	
	do {
		printf("Enter the genre (1 = action, 2 = animation, 3 = drama, 4 = fantasy, 5 = superhero): ");
		scanf("%d", &genreInput);
		getchar(); // clear buffer of newline character
		
		if (genreInput < action || genreInput > superhero)
			printf("Invalid genre. Please enter a number between 1 and 5.\n");
			
	} while (genreInput < action || genreInput > superhero);
	
	movie->genre = (Genre)genreInput; // convert integer from user input to enum constant	
}

void printDetails
(Movie list[], int count)
{
	printf("\n%-25s %-12s %-10s\n", "Title", "Downloads", "Genre");
	printf("-----------------------------------------------------\n");
	
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%-25s %-12d ", list[i].title, list[i].downloads);
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
