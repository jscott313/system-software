/*
 *  Name: 			Exercise4, ex4.c
 *  Author: 		Joshua Scott
 *  Task description:
 * 1. 
 *  - Create an array of 10 elements (random integer numbers between 0-1000) in main function.
 *  - Create a function and inside the function you print out the value and memory location of each element of that array.
 *  - Use pointers. Remember to pass the pointer and the array size to the function as arguments.
 *  - Do not pass the array as argument.
 *  - Do not create an array inside the function.
 *  - Why do you need to pass the array size as argument?
 * 2. 
 *  - Create a function and inside the function create an array of characters, each character of your names shall be in the array.
 * 	- Create another array of pointers, whose type is char. Initialize each pointer to NULL.
 * 	- In one loop, set each pointer to point to one character in the other array.
 * 	- So in pointer array location [0] there is a char pointer that points to character array location [0] etc.
 * 	- In another loop, print out the value and memory location of each character twice (once by handling the character array directly
 * 		and once by using the pointer array).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArrayInfo(int *arrayFirstElement, int arraySize);
void task2();

int main (void)
{
    // Seed for RNG
    srand(time(NULL));

    // TASK 1:
    // Array of 10 random ints from 0-1000
    int array10Ints[10];
    for (int i = 0; i < 10; i++)
        array10Ints[i] = rand() % 1000;

    // Get pointer to the first element
    int* pointerToFirstElement = &array10Ints[0];
    // Pass the pointer with arraySize so it can be printed
    printArrayInfo(pointerToFirstElement, 10);

    // TASK 2:
    task2();
}

/* Prints the index/value/address of elements in an array of ints. */
void printArrayInfo(int *arrayFirstElement, int arraySize)
{
	printf("Printing the index/value/address of each element, using a pointer and incrementing 4 bytes each time:\n");
    for (int i = 0; i < arraySize; i++)
    {
    	/* We use * to dereference the pointer (i.e. get the value).
    	 No & is needed to get the address: it's a pointer, so the value IS an address!
    	 If we did use &, we'd have the address of the pointer itself, not the address it points to. */
    	printf("Index:\t%d\nValue:\t%d\nAddress:%p\n\n", i, *arrayFirstElement, arrayFirstElement);
        // Because pointer type is int, next line increments by 4 bytes.
        arrayFirstElement++;
    }
}


void task2()
{
    char ourNames[] = { 'J', 'O', 'S', 'H', '+', 'R', 'O', 'B', 'I', 'N' };

    // Array of 10 pointers, initialise each to null
	char *pointers[10];
	for (int i = 0; i < 10; i++)
		pointers[i] = NULL;

	// Print each pointer's address to confirm they're null
	printf("\nPointers initialised as null:\n");
	for (int i = 0; i < 10; i++)
		printf("Address:%p\n", pointers[i]);

	// Make each pointer point to the chars in ourNames
	for (int i = 0; i < 10; i++)
		pointers[i] = &ourNames[i];

	// Print each pointer's address to confirm:
	printf("\nPointers now have addresses, 1 byte apart:\n");
	for (int i = 0; i < 10; i++)
		printf("Address:%p\n", pointers[i]);

	// Print each char's info twice, once using pointers and once using the actual variable
	printf("\nNow we can access each char using both pointers and variables:\n");
	for (int i = 0; i < 10; i++)
	{
		// Here we use * to dereference the pointer (i.e. get the value)
		printf("Value: %c in memory location %p\n", *pointers[i], pointers[i]);
		// Here we use & to get the address of the variable
		printf("Value: %c in memory location %p\n", ourNames[i], &ourNames[i]);
	}
}
