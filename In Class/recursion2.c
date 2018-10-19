#include <stdio.h>

int sumDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum = sum + num%10;
    num = num / 10;
  }
  return sum;
}

int sumDigits2(int num) {
  if(num == 0) return 0;
  return num%10 + sumDigits2(num/10);
}

int main(void) {
  printf("Enter a number : ");
  int num;
  scanf("%d", &num);

  int ans = sumDigits(num);
  printf("sum of %d digits is %d\n", num, ans);

  int ans2 = sumDigits2(num);
  printf("sum of %d digits is %d\n", num, ans2);
}
