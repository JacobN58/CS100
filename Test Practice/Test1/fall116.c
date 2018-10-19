#include <stdio.h>
int main ( ) {
 int a, b;
 for (a = 0; a < 5; a++) {
 for (b = 0; b < 5; b++)
 if (a<2 && b<2)
 printf("T");
 else if (a<2 && b>2)
 printf("I");
 else if (a>2 && b<2)
 printf("D");
 else if (a>2 && b>2)
 printf("E");
 else
 printf("-");
 printf("\n");
 }
 return 0;
}
