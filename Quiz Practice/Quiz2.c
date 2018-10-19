#include <stdio.h>
int main(void) {
 int a=2, b=3, c=20;
 double d=3.14159;
 printf("%d and %d\n", c%a, c/b);
 if ( a*b > c/b )
 printf("Roll\n");
 else
 printf("Tide\n");
 if ( (a<b) || (b>d) )
 if ( b%a == 0)
 printf("UA\n");
 else
 printf("CS\n");
 else
 printf("Alabama\n");
 return 0;
}
