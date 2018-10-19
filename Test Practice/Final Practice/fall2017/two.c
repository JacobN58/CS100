#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
 char *name;
 struct node *next;
} Node;

void printAfter(Node *ptr, char *name){
  while(strcmp(ptr->name, name) !=0 && ptr != NULL){
    ptr = ptr->next;
  }
  if(ptr == NULL){
    printf("Error: the name does not exist");
  }
  else{
    ptr = ptr->next;
    while (ptr != NULL) {
      printf("%s ", ptr->name);
      ptr = ptr->next;
    }
  }
}
Node *add(Node *ptr, char *name) {
 Node *newOne = malloc( sizeof(Node) );
 newOne->name = malloc( strlen(name) + 1 );
 strcpy(newOne->name, name);
 newOne->next = ptr;
 return newOne;
}
int main(void) {
 char str[100];
 Node *myList = NULL;
 printf("Enter a name to add : ");
 scanf("%s", str);
 while (strcmp(str, "quit") != 0) {
 myList = add(myList, str);
 printf("Enter a name or \"quit\" : ");
 scanf("%s", str);
 }
 printf("\n\n\nEnter a name : ");
 scanf("%s", str);
 printf("The list after %s\n", str);
 printAfter(myList, str);
 return 0;
}
