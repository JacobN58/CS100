//./a.exe data
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
 int x = 0, y = 0, z = 0;
 FILE *fp = fopen(argv[1], "r");
 while ( x >= 0 ) {
 fscanf(fp, "%d", &x);
 y = y + 1;
 z = z + x;
 }
 printf("A: %d\n", x);
 printf("B: %d\n", y);
 printf("C: %d\n", z);
 char str[] = "ABC";
 int w = strlen(str);
 char *s=(char *) malloc (sizeof(char)*(w+1));
 for (int a=0; a<w; a++)
 s[a] = str[w-a-1];
 s[w] = '\0';
 printf("D: %s\n", str);
 printf("E: %s\n", s);
 return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
 int value;
 struct node *next;
} Node;
int main(void) {
 Node *one = (Node *) malloc (sizeof(Node));
 Node *two = (Node *) malloc (sizeof(Node));
 one->value = 0; one->next = two;
 two->value = 1; two->next = one;
 Node *ptr = one;
 printf("A: %d\n", ptr->value);
 for (int a=0; a<3; a++)
 ptr = ptr->next;
 printf("B: %d\n", ptr->value);

 ptr = one;
 for (int a=1; a<=5; a++) {
 ptr->value = ptr->value + a;
 ptr = ptr->next;
 }
 printf("C: %d\n", one->value);
printf("D: %d\n", two->value);
 return 0;
}
