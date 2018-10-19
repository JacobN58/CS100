#include <stdio.h>
#include <string.h>

int main(void) {

  int num;
  printf("Enter a number : ");
  scanf("%d", &num);
  int count = 0;

  while (num != 0) {
      count = count + 1;
      num = num / 10;
  }

    printf("The number has %d digits.", count);

    return 0;
    }
