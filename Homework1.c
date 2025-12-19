//This program prompts the user for a temperature in 
//Fahrenheit and displays the result to the screen.


/*
This program prompts the user for a temperature in 
Fahrenheit, converts it to Celsius, and 
displays the result to the screen.
*/

#include <stdio.h> // library for input and output
// main function required by all C Programs
int main (void) 
{
	// Variable declarations
	double tempInFarenheit;
	double tempInCelsius;
	
	// Displays a prompt so the user knows what to do
	printf("Enter the temperature in Fahrenheit: ");
	
	// Reads the number typed by the user, and saves it into
	// the variable tempInFarenheit
	scanf("%lf", &tempInFarenheit);
	
	// Computes the temperature in Celsius
	tempInCelsius = (tempInFarenheit -32) / 1.8;
	
	//(T(F) - 32) / 1.8 <-- Conversion formula for reference
	
	//Displays temperature in Celsius
	printf("%.2f F converts to %.2f degrees C", tempInFarenheit, tempInCelsius);
	
	// All C programs need this at the end of main
	return (0);
}
