#include <stdio.h>
int main(void)

{
int a, b, c;

printf("Enter 3 numbers to find the average : ");
scanf("%d %d %d", &a, &b, &c);

double avg = (a * b * c) / 3.0;
printf("Your average is %lf\n", avg);
return 0;
}
