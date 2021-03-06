/*
 *  Name: 			Exercise4Advanced, ex4a.c
 *  Author: 		Joshua Scott
 *  Task description:
 * - Code a doubly linked list of structs. Each struct is an element in the periodic table.
 * - Each struct contains the element's name (e.g. Hydrogen), chemical symbol (e.g. H), atomic number (e.g. 1) and state (liquid, solid, gas, unknown)
 * - Each struct shall also contain a pointer to the next element and a pointer to the previous element
 * - You shall be able to add new elements to the list (either read user input or from a file)
 * - New elements shall go to correct place in the list based on their atomic number
 * - You shall be able to find an element by using the chemical symbol as a key
 * - You shall be able to print out the element's information
 * - You shall be able to print out the elements that currently exist periodic table
 * - You shall be able to empty the whole list and free the memory
 * - Use pointers and functions and allocate memory dynamically for each element
*/

#define NAME_LENGTH 20

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char name[NAME_LENGTH];    // e.g. Hydrogen
    char chemicalSymbol[2];    // e.g. H or Ag
	short int atomicNumber;     // e.g. 1
	char state;                 // s, l, g or u (unknown)

	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(char name[NAME_LENGTH], char chemicalSymbol[2],
                        short int atomicNumber, char state)
{
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->name, name);
	strcpy(newNode->chemicalSymbol, chemicalSymbol);
	newNode->atomicNumber = atomicNumber;
	newNode->state = state;

	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node into Doubly linked list based on the atomic number
void InsertBasedOnAtomicNumber(struct Node* toInsert)
{
	struct Node* current = head;

	// If first item in the list
	if(current == NULL)
	{
		head = toInsert;
		return;
	}

	// Else go to the element that will link to toInsert (note this could be on either side, more checks will confirm...)
	while(current->atomicNumber < toInsert->atomicNumber && current->next != NULL)
	{
		current = current->next; // Go to next Node
	}

	// if toInsert should become the FIRST in the list
	if (current == head && current->atomicNumber > toInsert->atomicNumber)
	{
		toInsert->next = current;
		current->prev = toInsert;
		head = toInsert;
	}
	// if toInsert should become the SECOND in the list
	else if (current == head && current->atomicNumber < toInsert->atomicNumber)
	{
		toInsert->next = current->next;
		toInsert->prev = current;
		current->next = toInsert;
	}
	// if toInsert should go ANYWHERE ELSE BUT THE END
	else if (current->next != NULL)
	{
		// Update pointers of toInsert
		toInsert->next = current;
		toInsert->prev = current->prev;
		current->prev = toInsert;
		(toInsert->prev)->next = toInsert;
	}
	// if toInsert should go AT THE END
	else
	{
		current->next = toInsert;
		toInsert->prev = current;
	}
}

//Prints all the elements in linked list in forward traversal order
void Print()
{
	struct Node* current = head;
	printf("Forward:\n");
	while(current != NULL)
	{
		printf("%s, %s, %d, %c\n",current->name, current->chemicalSymbol, current->atomicNumber, current->state);
		current = current->next;
	}
	printf("\n");
}

int main()
{
	head = NULL; // empty list. set head as NULL.

	// create some chemical elements
	struct Node* hydrogen = GetNewNode("Hydrogen", "H", 1, 'g');
	struct Node* helium = GetNewNode("Helium", "He", 2, 'g');
	struct Node* lithium = GetNewNode("Lithium", "Li", 3, 's');
	struct Node* beryllium = GetNewNode("Beryllium", "Be", 4, 's');

	InsertBasedOnAtomicNumber(hydrogen);
	InsertBasedOnAtomicNumber(lithium);
	InsertBasedOnAtomicNumber(beryllium);
	InsertBasedOnAtomicNumber(helium);

	Print();

	/* All functions here should work as intended. Eclipse will give errors about having 2 main functions, for
	 * example (because my and Robin's file are in the same project, but this will change if/when we complete it) */

	/* todo:
	 user to insert information (scanf or fgets, prompt for each value)
	 read data from csv file (i.e. combine with Robin's)
	 print an element's info by using the chemical symbol as a key
	 empty the whole list and free the memory
	 "Use pointers and functions and allocate memory dynamically for each element"
	 implement commands for the user to carry out these tasks /*
}
