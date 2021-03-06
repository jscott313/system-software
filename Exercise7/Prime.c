#include<stdio.h>
#include"Prime.h"

void checkIfPrime(int toCheck)
{
    // Edge cases
	if (toCheck < 0)
	{
		printf("%d is negative, and therefore not prime.\n", toCheck);
		return;
	}
	if (toCheck == 0 || toCheck == 1)
	{
		printf("No, %d is not a prime number.\n", toCheck);
		return;
	}
    if (toCheck == 2)
    {
    	printf("Yes, %d is a prime number.\n", toCheck);
    	return;
    }

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
        return;
    }
    else
    {
        printf("Yes, %d is a prime number.\n", toCheck);
        return;
    }
}
