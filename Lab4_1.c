// Written by Colin Stachelrodt
// Lab 4-1: Repetition
// Initial code copied from document then modified

/*
03 Lab 01 - Repetition
The while loop below prints the following output:
Num is 0
Num is 1
Num is 2
Num is 3
Num is 4
Num is 5
Num is 6
Num is 7
Num is 8
Num is 9
Replace the while loop with a for loop that gives the same output. Do not change
any
other part of the program. Change only the loop!
Additional requirements:
You must use the increment operator as part of the for loop syntax.
*/

#include <stdio.h>

int main(void)
{
	int max = 10;
	int num; //loop control variable
	num = 0; //initialization step for while loop
	
	//start of loop - replace this with a for loop
	for (int counter = 0;counter < max; ++counter)
	{
		printf("Num is %d.\n", num);
		++num;
	}
	/*
	while (num < max) //test step for while loop
	{
		printf("Num is %d\n", num);
		num = num + 1; //update step for while loop
	}
	*/
	//end of loop
	return(0);
}

