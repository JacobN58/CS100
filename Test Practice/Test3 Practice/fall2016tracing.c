//./a.out Tide 5
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
int a, b, c;
char *str = argv[1];
int len = strlen(str);
int num = atoi(argv[2]);
printf("%s, %d and %d\n", str, len, num);
char *ans = (char *) malloc(len*num + 1);
c = 0;
for (a=0; a<len; a++)
for (b=0; b<num; b++) {
ans[c] = str[a];
c = c + 1;
}
ans[c] = '\0';
printf("%s\n", ans);
return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int val;
struct node *next;
} Node;
int main(int argc, char *argv[]) {
Node *a = (Node *) malloc (sizeof(Node));
Node *b = (Node *) malloc (sizeof(Node));
Node *c = (Node *) malloc (sizeof(Node));
a->val = 10; a->next = b;
b->val = 15; b->next = c;
c->val = 20; c->next = a;
Node *ptr = a;
while (ptr->val < 50) {
printf("%d\n", ptr->val);
ptr->val = ptr->val + ptr->next->val;
ptr = ptr->next;
}
printf("%d\n", a->val);
printf("%d\n", b->val);
printf("%d\n", c->val);
return 0;
}
