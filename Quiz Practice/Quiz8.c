/*#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[ ] ) {
 for (int a=1; a<argc; a++) {
 int z = a;
 while ( z < strlen(argv[a]) ) {
 printf("%c ", argv[a][z]);
 z = z + 2;
 }
 printf("\n");
 }
 return 0;
}

#include <stdio.h>
#include <stdlib.h>
void function(char *str, char ch, int len) {
 for (int a=0; a<len; a++) {
 str[a] = ch;
 ch = ch + 1;
 }
 str[len] = '\0';
 return;
}
int main(void) {
 char *s1 = malloc ( sizeof(char) * 3 );
 function(s1, 'x', 2);
 printf("%s\n", s1);
 char *s2 = malloc ( sizeof(char) * 5 );
 function(s2, 'A', 4);
 printf("%s\n", s2);
 return 0;
}

#include <stdio.h>
int main( ) {
int a, b, c = 0;
int nums[16];
for (a=0; a<16; a++)
nums[a] = a % 7;
int data[4][4];
 for (a=0; a<4; a++)
 for (b=0; b<4; b++)
 data[a][b] = nums[c++];
 printf("A: %d\n", data[0][0]);
 printf("B: %d\n", data[0][3]);
 printf("C: %d\n", data[1][2]);
 printf("D: %d\n", data[2][2]);
 printf("E: %d\n", data[3][3]);
 return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
void function(int *a, int b) {
 for (int z=0; z<b; z++)
 a[z] = z*z - b;
 return;
}
int main( ) {
 int *x = (int *) malloc ( sizeof(int) * 3);
 function(x, 3);
 printf("%d and %d\n", x[0], x[2]);
 int *y = (int *) malloc ( sizeof(int) * 7);
 function(y, 7);
 printf("%d and %d and %d\n", y[2],y[4],y[6]);
 return 0;
}
