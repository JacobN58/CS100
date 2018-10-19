#include <stdio.h>
int main(void) {
 int a, b=0, data[5];
 for (a=0; a<5; a++) {
 scanf("%d", &data[a]);
 }
 for (a=0; a<5; a++) {
 data[a] = data[a] * a;
 printf("%d\n", data[a]);
 b = b + data[a];
 }
 printf("%d\n", b);
}
