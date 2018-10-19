#include <stdio.h>
#include <stdlib.h>

typedef struct node {
     int data;
     struct node *next;
} Node;

Node *add(Node *head, int e) {
   Node *newOne = (Node *) malloc (sizeof(Node));
   newOne->data = e;
   newOne->next = NULL;
   if (head == NULL) return newOne;
   Node *temp = head;
   while (temp->next != NULL) temp = temp->next;
   temp->next = newOne;
   return head;
 }

 void listPrint(Node *list, int inc) {

   int count = 0;

  while(list) {

    if(count % inc == 0)
      printf("%d ", list->data);

    count++;

    list = list->next;

  }

  return;

 }

 int main(int argc, char *argv[]) {

   FILE *fp = fopen(argv[1], "r");;

   if (!fp) { printf("No such file\n"); exit(1); }

   int num;

   Node *theList = NULL;

   fscanf(fp, "%d", &num);

   while (!feof(fp)) {

   theList = add(theList, num);

   fscanf(fp, "%d", &num);
  }

  printf("Printing every Nth element\n");

  printf("\tEnter the print increment : ");

  scanf("%d", &num);

  listPrint(theList, num);

  fclose(fp);

  return 0;

}
