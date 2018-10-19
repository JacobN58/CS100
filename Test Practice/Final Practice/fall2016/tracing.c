/*
// "*CRIM"
// "CRIMS"
// "RIMSO"
// "IMSON"
// "MSON*"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
char str[] = "CRIMSON";
int a, b;
for (a=0; a<=4; a++) {
for (b=0; b<5; b++)
if ( (a+b-1) < 0 )
printf("*");
else if ( (a+b-1) < strlen(str) )
printf("%c", str[a+b-1]);
else
printf("*");
printf("\n");
}
return 0;
}

// ROLL TIDE CS100 UA
// "-R-T-C-U"
// "-O-I-S-A"
// "-L-D-1--"
// "-L-E-0--"
// "-----0--"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
int a, b, m=0;
for (a=1; a<argc; a++)
if (strlen(argv[a]) > m)
m = strlen(argv[a]);
printf("%d\n", m);
for (a=0; a<m; a++) {
for (b=1; b<argc; b++)
if ( a < strlen(argv[b]) )
printf("-%c", argv[b][a]);
else
printf("--");
printf("\n");
}
return 0;
}
*/
// 123 4567 2468 13579
// "123 is 4"
// "4567 is 12"
// "2468 is 0"
// "13579 is 25"
#include <stdio.h>
#include <stdlib.h>
int foo(int a) {
 if (a == 0) return 0;
 if (a%2 == 1) return a%10 + foo(a/10);
 return foo(a/10);
}
int main(int argc, char *argv[]) {
int a, num;
for (a=1; a<argc; a++) {
num = atoi(argv[a]);
printf("%d is %d\n", num, foo(num) );
}
return 0;
}
