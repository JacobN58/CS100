#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"


//Jacob Nelson: This program is a simple phone directory program meant to add in contacts or update them and then print
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
Node *search(MultiLinkedList *list, char *first, char *last) {
	Node *ptr = list->headFirstName;
	while (ptr != NULL) {
		if(strcasecmp(ptr->first, first)==0 && strcasecmp(ptr->last, last)==0)
			return ptr;
		ptr = ptr->nextFirst;
	}
	return NULL;
}

void printNumber(long val) {
	int array[10], i;
	for(i = 9; i >= 0; i--){
		array[i] = val % 10;
		val /= 10;
	}
	printf("%d%d%d-%d%d%d-%d%d%d%d", array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]);
	return;
}

MultiLinkedList *add(MultiLinkedList *list, char *first, char *last, long num) {
	// allocate a new node
	if(search(list, first, last)!=NULL) {
		printf("ERROR: The name %s %s already exists.\n", first, last);
		return list;
	}
	Node *newNode = malloc ( sizeof(Node) );
	newNode->first = malloc ( strlen(first) + 1 );
	strcpy(newNode->first, first);
	newNode->last = malloc ( strlen(last) + 1 );
	strcpy(newNode->last, last);
	newNode->number = num;
	// add this new node at the head of the "byFirst" list
		//newNode->nextFirst = list->headFirstName;
		//list->headFirstName = newNode;
	Node *prevPtr = list->headFirstName;
	if(prevPtr==NULL || strcasecmp(newNode->first, prevPtr->first)<0) {
		newNode->nextFirst = prevPtr;
		list->headFirstName = newNode;
	}
	else if(strcasecmp(newNode->first, prevPtr->first)==0 && strcasecmp(newNode->last, prevPtr->last)<0) {
		newNode->nextFirst = prevPtr;
		list->headFirstName = newNode;
	}
	else {
		Node *nextPtr = prevPtr->nextFirst;
		while(nextPtr!=NULL) {
			if(strcasecmp(newNode->first, nextPtr->first)<0) {
				prevPtr->nextFirst = newNode;
				newNode->nextFirst = nextPtr;
				break;
			}
			if(strcasecmp(newNode->first, nextPtr->first)==0) {
				while (nextPtr!=NULL) {
					if(strcasecmp(newNode->first, nextPtr->first)!=0 || strcasecmp(newNode->last, nextPtr->last)<0) {
						prevPtr->nextFirst = newNode;
						newNode->nextFirst = nextPtr;
						break;
					}
					prevPtr = nextPtr;
					nextPtr = nextPtr->nextFirst;
				}
				break;
			}
			prevPtr = nextPtr;
			nextPtr = nextPtr->nextFirst;
		}
		if(nextPtr==NULL) {
			prevPtr->nextFirst = newNode;
			newNode->nextFirst = NULL;
		}
	}
	// add this new node at the head of the "byLast" list
		//newNode->nextLast = list->headLastName;
		//list->headLastName = newNode;
		prevPtr = list->headLastName;
		if(prevPtr==NULL || strcasecmp(newNode->last, prevPtr->last)<0) {
			newNode->nextLast = prevPtr;
			list->headLastName = newNode;
		}
		else if(strcasecmp(newNode->last, prevPtr->last)==0 && strcasecmp(newNode->first, prevPtr->first)<0) {
			newNode->nextLast = prevPtr;
			list->headLastName = newNode;
		}
		else {
			Node *nextPtr = prevPtr->nextLast;
			while(nextPtr!=NULL) {
				if(strcasecmp(newNode->last, nextPtr->last)<0) {
					prevPtr->nextLast = newNode;
					newNode->nextLast = nextPtr;
					break;
				}
				if(strcasecmp(newNode->last, nextPtr->last)==0) {
					while (nextPtr!=NULL) {
						if(strcasecmp(newNode->last, nextPtr->last)!=0 || strcasecmp(newNode->first, nextPtr->first)<0) {
							prevPtr->nextLast = newNode;
							newNode->nextLast = nextPtr;
							break;
						}
						prevPtr = nextPtr;
						nextPtr = nextPtr->nextLast;
					}
					break;
				}
				prevPtr = nextPtr;
				nextPtr = nextPtr->nextLast;
			}
			if(nextPtr==NULL) {
				prevPtr->nextLast = newNode;
				newNode->nextLast = NULL;
			}
		}
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
					printf("%s %s ", ptr->first, ptr->last);
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
	Node *ptr = search(list, first, last);
	if(ptr==NULL) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return;
	}
		ptr->number = number;
	return;
}

MultiLinkedList *removeItem(MultiLinkedList *list, char *first, char *last) {
	// remove the individual specified from the list
	if(search(list, first, last)==NULL) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	//first name remove
	Node *prevPtr = list->headFirstName;
	Node *nextPtr = prevPtr->nextFirst;
			if(strcasecmp(prevPtr->first, first)==0 && strcasecmp(prevPtr->last, last)==0) {
				list->headFirstName = nextPtr;
			}
			else
				while (nextPtr != NULL) {
					if(strcasecmp(nextPtr->first, first)==0 && strcasecmp(nextPtr->last, last)==0) {
						prevPtr->nextFirst = nextPtr->nextFirst;
					}
					prevPtr = nextPtr;
					nextPtr = nextPtr->nextFirst;
				}
	//last name remove
	prevPtr = list->headLastName;
	nextPtr = prevPtr->nextLast;
				if(strcasecmp(prevPtr->first, first)==0 && strcasecmp(prevPtr->last, last)==0) {
					list->headFirstName = nextPtr;
				}
				else
					while (nextPtr != NULL) {
						if(strcasecmp(nextPtr->first, first)==0 && strcasecmp(nextPtr->last, last)==0) {
							prevPtr->nextLast = nextPtr->nextLast;
						}
						prevPtr = nextPtr;
						nextPtr = nextPtr->nextLast;
					}
	return list;
}

MultiLinkedList *updateFirst(MultiLinkedList *list, char *first, char *last, char *newFirst) {
	// update the first name of the individual specified
	Node *ptr = search(list, first, last);
	if(ptr==NULL) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	if(search(list, newFirst, last)!=NULL) {
		printf("ERROR: The name %s %s already exists.\n", newFirst, last);
		return list;
	}
			strcpy(ptr->first, newFirst);
		return list;
}

MultiLinkedList *updateLast(MultiLinkedList *list, char *first, char *last, char *newLast) {
	// update the last name of the individual specified
	Node *ptr = search(list, first, last);
	if(ptr==NULL) {
		printf("ERROR: The name %s %s does not exist.\n", first, last);
		return list;
	}
	if(search(list, first, newLast)!=NULL) {
		printf("ERROR: The name %s %s already exists.\n", first, newLast);
		return list;
	}
			strcpy(ptr->last, newLast);
		return list;
}
