#include <stdio.h>
int main(void)

{
  double plain, filled;
  double calories;

  printf("How many plain donuts have you eaten?\n");
  scanf("%lf", &plain);
  printf("How many filled donuts have you eaten?\n");
  scanf("%lf", &filled);

  calories = (plain * 190) + (filled * 350);

  printf("You consumed %lf calories.\n", calories);
  return 0;
}
