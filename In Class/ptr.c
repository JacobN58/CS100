#include <stdio.h>

int main(void) {

int a = 5;

printf("The value of a is %d\n", a);
printf("The location of a is %p\n", &a);


int *p;
p = &a;
printf("The location stored at p is %p\n", p);
printf("The value that p points to is %d\n", *p);

return 0;
}
