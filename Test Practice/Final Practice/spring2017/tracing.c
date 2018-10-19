/*
// "1 - 2"
// "2 - 7"
// "3 - 8"
// "4 - 9"
#include <stdio.h>
int function(int num) {
 if (num == 0) return 0;
 int val1 = num % 10;
 int val2 = function(num/10);
 if (val1 > val2) return val1;
 else return val2;
}
int main( void ) {
 printf("1 - %d\n", function(21) );
 printf("2 - %d\n", function(2274) );
 printf("3 - %d\n", function(888) );
 printf("4 - %d\n", function(13579) );
 return 0;
}
// CS UofA
// "C SS"
// "U oo fff AAAA"
#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[] ) {
 int a, b, c, d;
 char str[1024];
 for (a=1; a<argc; a++) {
 d = strlen(argv[a]);
 strcpy(str, argv[a]);
 for (b=0; b<d; b++) {
 for (c=0; c<=b; c++)
 printf("%c", str[b]);
 printf(" ");
 }
 printf("\n");
 }
 return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
 char *name;
 struct node *next;
} Node;
Node *fun1(Node *ptr, char *text) {
 Node *new = (Node *) malloc (sizeof(Node));
 new->name = (char *) malloc (strlen(text) + 1);
 strcpy(new->name, text);
 new->next = NULL;
 if (ptr == NULL) return new;
 Node *temp = ptr;
 while (temp->next != NULL) temp = temp->next;
 temp->next = new;
 return ptr;
}
int fun2(Node *ptr, char *text) {
 int a=0;
 while ( strcmp(ptr->name, text) != 0 ) {
 a = a + 1;
 ptr = ptr->next;
 if (ptr == NULL) return -1;
 }
 return a;
}
int main( void ) {
 Node *head = NULL;
 char input[1024];
 scanf("%s", input);
 while ( strcmp(input, "quit") != 0 ) {
 head = fun1(head, input);
 scanf("%s", input);
 }
 scanf("%s", input);
 while ( strcmp(input, "exit") != 0 ) {
 int ans = fun2(head, input);
printf("%s is %d\n", input, ans);
 scanf("%s", input);
 }
 return 0;
}
