/*#include <stdio.h>
#include <string.h>
void f(int *a, int *b) {
 *a = *a + *b;
 *b = *b - *a;
 return;
}
int main(void) {
 char str[]= "ABCDEFGHIJKLMNOPQRST";
 int a = strlen(str), b = 1;
 while (b < a) {
 printf("%c", str[b]);
 b = b * 2;
 }
 printf("\n");
 int x = 10, y = 5;
 f(&x, &y);
 printf("%d and %d\n", x, y);
 f(&x, &y);
 printf("%d and %d\n", x, y);
 return 0;
}
*/

/*#include <stdio.h>
int f1(int a) { return a * a; }
int f2(int a) { return a + a; }
int funct(int z) {
 if (z % 2 == 0)
 return z * f1(z);
 else
 return z + f2(z);
}
int main(void) {
 FILE *fp1 = fopen( "data1", "r" );
 int a;
 for (int x=0; x<5; x++) {
 fscanf(fp1, "%d", &a);
 printf( "%d\n", funct(a) );
 }
 fclose(fp1);
 return 0;
}
*/
