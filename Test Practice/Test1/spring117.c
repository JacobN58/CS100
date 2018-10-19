#include <stdio.h>
int main(void) {
int a, b, c=0, d=0;
for (a=1; a<=5; a++) {
scanf("%d", &b);
printf("val = %d\n", b*a);
c = c + b;
d = d + b%10;
}
printf("c = %d\n", c);
printf("d = %d\n", d);
return 0;
}
