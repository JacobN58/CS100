#include <stdio.h>
#include <stdlib.h>
typedef struct node {
 int value;
 struct node *next;
} Node;

int findAverage(Node *ptr) {
  int total = 0;
  int n = 0;
  while(ptr) {
    total += ptr->value;
    n++;
    ptr = ptr->next;
  }
  return total / n;
}

void aboveAverage(Node *ptr) {
  int average = findAverage(ptr);
  while(ptr) {
    if(ptr->value > average)
      printf("%d\n", ptr->value);

    ptr = ptr->next;
  }
}

int main( void ) {
 int num;
 Node *head = NULL;
 printf("Enter a number to add to the list : ");
 scanf("%d", &num);
 while ( num != -999 ) {
 Node *ptr = (Node *) malloc ( sizeof(Node) );
 ptr->value = num;
 ptr->next = head;
 head = ptr;
 printf("Enter another number or -999 to exit : ");
 scanf("%d", &num);
 }
 aboveAverage(head);
 return 0;
}
