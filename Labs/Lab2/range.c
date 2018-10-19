#include <stdio.h>

int main(void) {

    int num1, num2, num3, numl = 0, nums = 0, range;
    printf("Enter three numbers\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num1 > num3)
      numl = num1;
    else if (num2 > num3 && num2 > num1)
      numl = num2;
    else
      numl = num3;

    if (num1 < num2 && num1 < num3)
      nums = num1;
    else if (num2 < num1 && num2 < num3)
      nums = num2;
    else
      nums = num3;

range = numl - nums;
    printf("The range is %d\n", range);
    return 0;
}
