/*
 Name: 			Exercise3, Assignment1.c
 Author: 		Joshua Scott
 Description: 	A program that:
 	 	 	 	 	1. asks user to give 10 integer numbers and places them in an array
					2. counts the average of the numbers and prints it on screen
					3. sorts the numbers in ascending order and prints the array elements on screen
					4. checks if the average (that is type casted to integer) is a prime number and is a number in Tribonacci sequence.
 */

#include<stdio.h>
#include<stdlib.h>

// Prototype functions

int main (void)
{
	// Task 1 NOTE THIS DOESN'T WORK YET!!!!!!!!!!!!!!!!!!!!
	int arrayOf10Ints[10];
	for(int i = 0; i < 10; i++)
	{
		int a = 0;
		a = scanf("%d", &a);
		arrayOf10Ints[i] = a;
	}

	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", arrayOf10Ints[i]);
	}
}
