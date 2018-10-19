#include <stdio.h>

int count7s(int num) {
  if(num == 0) return 0;
  int digit = num % 10;
  if(digit == 7) return 1 + count7s(num/10);
  return 0 + count7s(num/10);
}

int main(void) {
  printf("Enter a number : ");
  int num;
  scanf("%d", &num);

  int ans = count7s(num);
  printf("%d has %d sevens\n", num, ans);
}
