#include<stdio.h>
#include"OddEven.h"

void checkIfOddOrEven(int number)
{
	if(number % 2 == 0)
		printf("%d is even.\n", number);
	else
		printf("%d is odd.\n", number);
}
