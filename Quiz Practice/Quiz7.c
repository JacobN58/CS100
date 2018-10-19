#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main( int argc, char *argv[] ) {
 char str[] = "CRIMSON-TIDE";
 int x = atoi(argv[1]);
 int y = atoi(argv[2]);
 int z = strlen(str);
 for (int a=x; a<z; a=a+y)
 printf("%c", str[a]);
 printf("\n");
 for (int b=z; b>0; b=b-y)
 printf("%d\n", b);
 return 0;
}
