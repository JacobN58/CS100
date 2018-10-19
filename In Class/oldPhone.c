#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"


//Jacob Nelson: This program is a simple phone directory program meant to add in contacts or update them and then print
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int search(MultiLinkedList *list, char *first, char *last) {
	Node *ptr = list->headFirstName;
	while (ptr != NULL) {
		if(strcasecmp(ptr->first, first)!=0 || strcasecmp(ptr->last, last)!=0)
			return 1;
	}
	return 0;
}

//addTOFirstNameList(Node *head, Node *newNode) {

//}

//addTOLastNameList(Node *head, Node *newNode) {

//}

MultiLinkedList *add(MultiLinkedList *list, char *first, char *last, long num) {
	// allocate a new node
	Node *newNode = malloc ( sizeof(Node) );
	newNode->first = malloc ( strlen(first) + 1 );
	strcpy(newNode->first, first);
	newNode->last = malloc ( strlen(last) + 1 );
	strcpy(newNode->last, last);
	newNode->number = num;
	// add this new node at the head of the "byFirst" list
	newNode->nextFirst = list->headFirstName;
	list->headFirstName = newNode;
			//list->headFirstName = addTOFirstNameList(list->headFirstName, newNode);
	// add this new node at the head of the "byLast" list
	newNode->nextLast = list->headLastName;
	list->headLastName = newNode;
			//list->headLastName = addTOLastNameList(list->headLastName, newNode);
	// return the multi-list object with updated head pointers
	return list;
}

int size(MultiLinkedList *list) {
	// return the number of names in the list
	Node *ptr = list->headFirstName;
	int count = 0;
	while(ptr != NULL) {
		count++;
		ptr = ptr->nextFirst;
	}
	return count;
}

void printNumber(long val) {
	int g[10], h;
	for(h = 9; h >= 0; h--){
		g[h] = val % 10;
		val /= 10;
	}
	printf("%d%d%d-%d%d%d-%d%d%d%d ", g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]);
	return;
}

void printByFirst(MultiLinkedList *list) {
	// print (traverse the byFirst list)
	Node *ptr = list->headFirstName;
	while (ptr != NULL) {
					printf("%s %s ", ptr->first, ptr->last);
					printNumber(ptr->number);
					printf("\n");
					ptr = ptr->nextFirst;
	}
	return;
}

void printByLast(MultiLinkedList *list) {
	// print (traverse the byLast list)
	Node *ptr = list->headLastName;
	while (ptr != NULL) {
					printf("%s %s ", ptr->last, ptr->first);
 					printNumber(ptr->number);
					printf("\n");
					ptr = ptr->nextLast;
	}
	return;
}

int lookup(MultiLinkedList *list, char *name) {
	// print all instances of name (as either a first name or a last name)
	Node *ptr = list->headFirstName;
	int match = 0;
	while (ptr != NULL) {
			if(strcasecmp(ptr->first, name)==0 || strcasecmp(ptr->last, name)==0) {
				printf("%s %s ", ptr->first, ptr->last);
				printNumber(ptr->number);
				match++;
			}
			ptr = ptr->nextFirst;
	}
	return match;
}

void updatePhone(MultiLinkedList *list, char *first, char *last, long number) {
	// update the phone number for the individual specified
	/*if(search(list, first, last)==1) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return;
	}*/
	Node *ptr = list->headFirstName;
	while (ptr != NULL) {
			if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0) {
				ptr->number = number;
			}
			ptr = ptr->nextFirst;
	}
	return;
}

MultiLinkedList *removeItem(MultiLinkedList *list, char *first, char *last) {
	// remove the individual specified from the list
	if(search(list, first, last)==1) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	Node *ptr = list->headFirstName;
	Node *next = ptr->nextFirst;
			if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0) {
				list->headFirstName = next;
			}
			else
				while (next != NULL) {
					if(strcasecmp(next->first, first)==0 && strcasecmp(next->last, last)==0) {
						ptr->nextFirst = next->nextFirst;
					}
					ptr = next;
					next = next->nextFirst;
				}
	ptr = list->headLastName;
	next = ptr->nextLast;
				if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0) {
					list->headFirstName = next;
				}
				else
					while (next != NULL) {
						if(strcasecmp(next->first, first)==0 && strcasecmp(next->last, last)==0) {
							ptr->nextFirst = next->nextFirst;
						}
						ptr = next;
						next = next->nextFirst;
					}

	return list;
}

MultiLinkedList *updateFirst(MultiLinkedList *list, char *first, char *last, char *newFirst) {
	// update the first name of the individual specified
	if(search(list, first, last)==1) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	Node *ptr = list->headFirstName;
	while (ptr != NULL) {
			if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0) {
				strcpy(ptr->first, newFirst);
			}
			ptr = ptr->nextFirst;
	}
	return list;
}

MultiLinkedList *updateLast(MultiLinkedList *list, char *first, char *last, char *newLast) {
	// update the last name of the individual specified
	Node *ptr = list->headFirstName;

	if(search(list, first, last)==1) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	while (ptr != NULL) {
			if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0) {
				strcpy(ptr->last, newLast);
			}
			ptr = ptr->nextFirst;
	}
	return list;
}
