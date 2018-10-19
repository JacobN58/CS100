#include <stdio.h>
int main ( ) {
 int a, num, len;
 int oldGuy=0, count1=0, count2=0;
 scanf("%d", &len);
 for (a=0; a<len; a++) {
 scanf("%d", &num);
 if ( num%2 == 0) count1++;
 if (num > oldGuy)
 { oldGuy = num; count2++; }
 printf("%d %d %d\n", num, count1, count2);
 }
 printf("%d %d\n", count1, count2);
 return 0;
}
