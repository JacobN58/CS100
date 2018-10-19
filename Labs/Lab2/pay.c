#include <stdio.h>

int main(void) {

double hrwage = 0;
int hrs = 0;
double total = 0;
printf("Enter your hourly wage and hours worked : \n");
scanf("%lf %d", &hrwage, &hrs);

if (hrs <= 40)
 total = hrwage * hrs;

if (hrs > 40 && hrs < 51)
total = (hrwage * 40) + (hrwage * 1.5 * (hrs - 40));

if (hrs > 40 && hrs >= 51)
total = (hrwage * 40) + (hrwage * 1.5 * 10) + (hrwage * 2 * (hrs - 50));

printf("Your pay is %lf", total);
return 0;
}
