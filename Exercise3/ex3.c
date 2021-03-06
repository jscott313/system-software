/*
 * Name: 		Exercise3, ex3.c
 * Author: 		Joshua Scott
 * Description:
 *		1. asks user to give 10 integer numbers and places them in an array
 *		2. counts the average of the numbers and prints it on screen
 *		3. sorts the numbers in ascending order and prints the array elements on screen
 *		4. checks if the average (that is type casted to integer) is a prime number and is a number in Tribonacci sequence.
 */

#include <stdio.h>
#include <stdlib.h>

// Prototypes
void addIntsToArray(int array[], int length, int autoGenerate);
void printArray(int array[], int length);
double getAverageOfArray(int array[], int length);
void bubbleSort(int array[], int length);
int checkIfPrime(int toCheck);
int checkIfTribonacci(int toCheck);

int main (void)
{
    int arrayOfTenInts[10];
    // Let's use the standard way of getting an array's length in C:
    const int lengthOfArray = sizeof(arrayOfTenInts) / sizeof(arrayOfTenInts[0]);

    // Task 1, place 10 ints into an array:
    addIntsToArray(arrayOfTenInts, lengthOfArray, 0); // Change 1 to 0 to ask for input

    // Print the current array
    printf("Initial array:\n");
    printArray(arrayOfTenInts, lengthOfArray);

    // Task 2, get and display the average:
    double average = getAverageOfArray(arrayOfTenInts, lengthOfArray);
    printf("The average of the array's contents is %.02f.\n", average);

    // Task 3, sort in ascending order (bubble sort):
    bubbleSort(arrayOfTenInts, lengthOfArray);
    printf("\nHere's the array now it's been sorted:\n");
    printArray(arrayOfTenInts, lengthOfArray);

    // Task 4.1, check for prime:
        // Note that due to int casting, average is always rounded down, e.g. 4.7 will become 4, not 5)
    checkIfPrime((int)average);

    // Task 4.2, check for tribonacci:
    if(checkIfTribonacci((int)average))
        printf("Yes, %d is in the Tribonacci sequence.\n", (int)average);
    else
        printf("No, %d is not in the Tribonacci sequence.\n", (int)average);
}

/*  Gets input from the user and adds integers to an array.
    Does not check for input errors.
    Has a simple autogenerate feature for faster testing. */
void addIntsToArray(int array[], int length, int autoGenerate)
{
    for (int i = 0; i < length; i++)
    {
        if (autoGenerate)
            array[i] = 10 - i;
        else
        {
            printf("Enter value at index %d: ", i);
            // fflush avoids a bug with Eclipse and scanf()
            fflush(stdout);
            scanf("%d", &array[i]);
        }
    }
}

/*  Prints an array of ints, one per line. New line after. */
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
}

/*  Returns the average of an array of ints, as a double. */
double getAverageOfArray(int array[], int length)
{
    double total = 0;
    for (int i = 0; i < length; i++)
        total += array[i];
    return total/10;
}

/*  Sorts an array of ints using Bubblesort algorithm.
    Optimised; will not loop again if no swaps were required on the previous loop.
    Prints each time a swap was made. */
void bubbleSort(int array[], int length)
{
    printf("\nSorting array using Bubble sort:\n");
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swapped = 1;
                printf("Swapping %d with %d...\n", array[i], array[i + 1]);
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (swapped);
}

/*  Checks if a given int is prime. Prints the result and, if not prime, its largest factor. */
int checkIfPrime(int toCheck)
{
    // Edge case
    if (toCheck == 2)
        printf("Yes, 2 is a prime number.\n");

    int potentialFactor = toCheck/2;
    int hasAFactor = 0;

    while (!hasAFactor && potentialFactor > 1)
    {
        if (toCheck % potentialFactor == 0)
            hasAFactor = 1;
        potentialFactor--;
    }
    if (hasAFactor)
    {
        printf("No, %d is not prime. %d is its largest non-self factor.\n", toCheck, potentialFactor + 1);
        return 1;
    }
    else
    {
        printf("Yes, %d is a prime number.\n", toCheck);
        return 0;
    }
}

/*  Checks if a given int is in the Tribonacci sequence. */
int checkIfTribonacci(int toCheck)
{
    // Edge case
    if (toCheck == 0)
		return 1;

	// The first three Tribonacci numbers
	int first = 0;
	int second = 0;
	int third = 1;

	// Adds the preceding three numbers to find the next number in sequence. Checks for equality.
	while (third < toCheck)
	{
		int willBecomeThird = first + second + third;
		if (willBecomeThird == toCheck)
			return 1;
		first = second;
		second = third;
		third = willBecomeThird;
	}
	return 0;
}
