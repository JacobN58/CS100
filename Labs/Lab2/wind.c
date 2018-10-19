#include <stdio.h>
#include <math.h>

int main(void) {

int temp = 0, windsp = 0;

printf("Enter the temperature and wind speed : \n");
scanf("%d %d", &temp, &windsp);

double windch = 35.74 + (0.6215 * temp) - (35.75 * pow(windsp, 0.16)) + (0.4275 * temp * pow(windsp, 0.16));

printf("The wind chill is %lf\n", windch);

return 0;
}
