#include <stdio.h>
int main(void)

{
int weight = 0;
double gold = 0;

printf("Enter your weight in pounds: \n");
scanf("%d", &weight);
printf("Enter the current price of gold per ounce: \n");
scanf("%lf", &gold);

gold = weight * (gold * 16);
printf("Your weight in gold is worth $%lf", gold);
return 0;

}
