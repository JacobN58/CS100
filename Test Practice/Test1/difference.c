#include <stdio.h>
int main(void) {
int a, x, y, z=0;
for (a=0; a<4; a++) {
scanf("%d %d", &x, &y);
if (x < y) {
z = z - x;
printf("%d\n", y%x);
}
else
z = z + x;
}
printf("%d\n", z);
return 0;
}
