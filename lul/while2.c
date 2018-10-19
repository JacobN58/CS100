#include <stdio.h>

int main(void) {
  int num, total = 0;

  printf("Enter numbers, terminating w/ -1\n");
  // read initial number
  scanf("%d", &num);

  // while we have not hit -1
  while (num != -1) { // while (! feof(stdin)) and terminate w/ ctr-d
    // process this number
    total = total + num;
    // read next value
    scanf("%d", &num);
  }

  printf("The total is %d\n", total);

  return 0;
}
