/*#include <stdio.h>
typedef struct item {
int value;
struct item *next;
} Item;
int main(void) {
Item a, b;
a.value = 0; a.next = &b;
b.value = 0; b.next = &a;
Item *ptr = &a;
for (int z=1; z<5; z++) {
ptr->value = ptr->value + z;
ptr = ptr->next;
}
printf("%d and %d\n", a.value, b.value);
return 0;
}
*/
#include <stdio.h>
int main(void) {
int data[2][4] = { {1,2,3,4}, {5,4,3,2} };
int x = 0, y = 0;
for (int a=0; a<2; a++) {
for (int b=0; b<4; b++) {
if ( (a+b)%2 == 0 )
x = x + data[a][b];
else
y = y + data[a][b];
 }
 }
printf("%d and %d\n", x, y);
return 0;
}
/*
#include <stdio.h>
typedef struct node {
 int val;
 struct node *next;
} Node;
int main(void) {
 Node one, two;
 one.val = 2; one.next = &two;
 two.val = 3; two.next = &one;
 Node *ptr = &one;
 while (ptr->val < 8) {
 printf("%d and %d\n", one.val, two.val);
 ptr->val = ptr->val * 2;
 ptr = ptr->next;
 }
 printf("ONE : %d\n", one.val);
 printf("TWO : %d\n", two.val);
 return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
 char ch;
 struct node *next;
} Node;
int main(void) {
 char str[] = "UofA";
 int a, b = strlen(str);
 Node *p1 = NULL, *p2 = NULL;
 for (a=0; a<b; a++) {
 p1 = (Node *) malloc (sizeof(Node));
 p1->ch = str[b-a-1];
 p1->next = p2;
 p2 = p1;
 }
 while (p1 != NULL) {
 printf("%c\n", p1->ch);
 p1 = p1->next;
 }
 return 0;
}
*/
