#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int value;
int count;
struct node *next;
} Node;
Node *addToList(Node *head, int num) {
  Node *temp = head;
    Node *pre = NULL;
    //loop to find if the number is present in the addToList
    while (temp != NULL) {
      if(temp->value == num){
        temp->count = temp->count + 1;
        return head;
      }
      pre = temp;
      temp = temp->next;
    }
    //if not presen temp = null and pre will contain pointer to
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = num;
    newNode->count = 1;
    newNode->next = NULL;
    if(num%2 == 0) {
      pre->next = newNode;
    }
    else {
      newNode->next = head;
      head = newNode;
    }
    return head;
}
void stats(Node *head) {
  int n_odd = 0;
  int n_even = 0;
  Node *temp = head;
  while (temp!=NULL) {
    if(temp->value%2 == 0)
      n_even = n_even + temp->count;
    else
      n_odd = n_odd + temp->count;
    temp=temp->next;
  }
  printf("\n %d even and %d odd numbers ", n_even, n_odd);
}
void printList(Node *ptr) {
 while (ptr)
 { printf("[%d-%d] ", ptr->value, ptr->count); ptr=ptr->next; }
printf("\n");
}
int main( int argc, char *argv[] ) {
Node *head = NULL;
if ( argc != 2 )
 { printf("Usage: ./a.out datafile\n"); exit(1); }
FILE *fp = fopen(argv[1], "r");
if ( ! fp )
 { printf("File %s does not exist\n", argv[1]); exit(1); }
int num;
fscanf(fp, "%d", &num);
while ( ! feof(fp) )
 { head = addToList( head, num ); fscanf(fp, "%d", &num); }
printList(head);
stats(head);
return 0;
}
