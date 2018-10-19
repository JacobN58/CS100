#include <stdio.h>

int main(void) {
  int num, max, min;

  printf("Enter a number: ");
  scanf("%d", &num);
  max = num;
  min = num;

  while (num != 0) {
    if (num < min)
      min = num;
    if (num > max)
      max = num;
    printf("Enter another number (0 to quit): ");
    scanf("%d", &num);
  }

  int range = max - min;
  printf("Range: %d\n", range);

  return 0;
}
