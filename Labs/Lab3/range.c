#include <stdio.h>

int main(void) {

int input, range;
int max, min;


printf("Enter in numbers to find the range : \n");
scanf("%d", &input);
max = input; min = input;

while (input != 0){

  if (input > max)
  max = input;

  else if (input < min)
  min = input;

  scanf("%d", &input);
}
range = max - min;
printf("Range of input = %d", range);
return 0;
}
