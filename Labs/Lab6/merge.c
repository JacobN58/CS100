#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
  int num1=0, num2=0;
  FILE *data1 = fopen("data1", "r");
  FILE *data2 = fopen("data2", "r");
  fscanf(data1, "%d", &num1);
  fscanf(data2, "%d", &num2);

  while (! feof(data1) && ! feof(data2)){
    if ( num1 < num2 ){
      printf("%d ", num1);
      fscanf(data1, "%d", &num1);
    }
    if (num2 < num1){
      printf("%d ", num2);
      fscanf(data2, "%d", &num2);
    }
    else {
      printf("%d ", num1);
      fscanf(data1, "%d", &num1);
      fscanf(data2, "%d", &num2);
    }
}

  while (! feof(data1)) {
    printf("%d ", num1);
    fscanf(data1, "%d", &num1);
  }
  while (! feof(data2)) {
    printf("%d ", num2);
    fscanf(data2, "%d", &num2);
  }
  return 0;
}
