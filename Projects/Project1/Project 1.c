#include <stdio.h>
int main(void)
//Jacob Nelson Project 1
//(Input amount of money user has and output the amount and the volume of both bills and coins)
{
int bill20 = 0;
int bill10 = 0;
int bill5 = 0;
int bill1 = 0;
int totalBills = 0;

int quarters = 0;
int dimes = 0;
int nickels = 0;
int pennies = 0;
double totalChange = 0;


printf("Enter the number of $20s you have:\n");
scanf("%d", &bill20);

printf("Enter the number of $10s you have:\n");
scanf("%d", &bill10);

printf("Enter the number of $5s you have:\n");
scanf("%d", &bill5);

printf("Enter the number of $1s you have:\n");
scanf("%d", &bill1);
//Calculate the total amount of bills then times it by the vol of one bill (assuming all bills are the same size)
totalBills = bill20 + bill10 + bill5 + bill1;
double volBills = totalBills * ((2.61 * 6.14 * 0.0043) * (2.54 * 2.54 * 2.54));

printf("Enter the number of quarters you have:\n");
scanf("%d", &quarters);

printf("Enter the number of dimes you have:\n");
scanf("%d", &dimes);

printf("Enter the number of nickels you have:\n");
scanf("%d", &nickels);

printf("Enter the number of pennies you have:\n");
scanf("%d", &pennies);
//Calculate the vol of each coin then multiply by how many of each coin entered and add each volume
double volQuarters = (quarters * (3.14159 * (12.13 * 12.13)) * 1.75) / 1000;
double volDimes = (dimes * (3.14159 * (8.955 * 8.955)) * 1.35) / 1000;
double volNickels = (nickels * (3.14159 * (10.605 * 10.605)) * 1.95) / 1000;
double volPennies = (pennies * (3.14159 * (9.525 * 9.525)) * 1.52) / 1000;
double volChange = volQuarters + volDimes + volNickels + volPennies;
//Calculate the total amount of money the user has
totalBills = (20 * bill20) + (10 * bill10) + (5 * bill5) + (1 * bill1);
totalChange = (25 * quarters) + (10 * dimes) + (5 * nickels) + (1 * pennies);

printf("You have %d dollars and %lf cents in change.\n", totalBills, totalChange);
printf("The volume of your bills is %lf cubic centimeters.\n", volBills);
printf("The volume of your change is %lf cubic centimeters.\n", volChange);

return 0;
}
