#include <stdio.h>

int main(void) {

int num, count1 =0, count2=0;

printf("Enter integers, ending with ctrl-d\n");
scanf("%d", &num);
  while (! feof(stdin)) {
    if (num % 5 == 0 && num > 0)
      count1++;
    if (num < 0 && num > -101)
      count2++;
    scanf("%d", &num);
  }
  printf("%d positve multiples of 5\n", count1);
  printf("%d small negative values\n", count2);
return 0;
}
