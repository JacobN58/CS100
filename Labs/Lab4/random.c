#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
  int num, random, unique=0, i;
  int numArray[10] = {0};

  srand(0);

  printf("How many random values to generate : ");
  scanf("%d", &num);

  for (i=0; i<num; i++){
    random = rand() % 10;
    numArray[random]++;
  }
  for (i=0; i<10; i++){
    if (numArray[i]>0)
    unique++;
  }
  printf("%d random numbers generated %d out of 10 possible values", num, unique);
return 0;
}
