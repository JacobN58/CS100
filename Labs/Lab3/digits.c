#include <stdio.h>

int main(void) {

  int num;
  printf("Enter a number : ");
  scanf("%d", &num);
  int digits = 0;

  while (num != 0) {
      digits = digits + (num % 10);
      num = num / 10;
  }

    printf("%d", digits);

    return 0;
}
