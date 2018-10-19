#include <stdio.h>

int main(void) {

int num;

printf("Enter a positve integer : \n");
scanf("%d", &num);

for (int x = 0; x < num; x++){

  for (int y = 0; y < num; y++){

    if (x == 0 || x == num-1)
        printf("X");
    else if (y == 0 || y == num-1)
        printf("X");
    else
    printf("O");
  }
  printf("\n");
}
return 0;
}
