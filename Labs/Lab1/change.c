#include <stdio.h>
int main(void)

{
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;


  printf("Enter the number of quarters you have:\n");
  scanf("%d", &quarters);

  printf("Enter the number of dimes you have:\n");
  scanf("%d", &dimes);

  printf("Enter the number of nickels you have:\n");
  scanf("%d", &nickels);

  printf("Enter the number of pennies you have:\n");
  scanf("%d", &pennies);

double changeTotal = (0.25 * quarters) + (0.10 * dimes) + (0.05 * nickels) + (0.01 * pennies);
printf("The total amount of change you have is $%lf", changeTotal);
return 0;
}
