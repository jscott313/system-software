#include <stdio.h>

int main (int argc, char **argv)
{
	// If incorrect args, complain
	if (argc != 4)
	{
		printf("Insufficient arguments.");
		return -1;
	}
	char selectedMode = argv[1][0];
	if (selectedMode == 'c' || selectedMode == 'e' ||
		selectedMode == 'C' || selectedMode == 'E')
	{
		encrypt(argv);
	}
	else if (selectedMode == 'd' || selectedMode == 'D')
	{
		decrypt(argv);
	}
	else 
	{
		printf("Second argument should be 'crypt'/'encrypt', or 'decrypt'");
	}
}