#include <stdio.h>
int main(void)

{
int cal;
printf("How many calories :");
scanf("%d", &cal);
double num;
num = cal / 190;
printf("Eat %lf donuts\n", num);
return 0;
}
