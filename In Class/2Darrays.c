#include <stdio.h>
#include <stdlib.h>

//declare a 5 row, 10 column matrix

int main(void) {
  int x, y;

  int **matrix = malloc (sizeof(int*) * 5);
  for(x=0; x<5; x++)
      matrix[x] = malloc (sizeof(int) * 10);


  //initialize
  for(x=0; x<5; x++) {
    for(y=0; y<10; y++)
      matrix[x][y] = x+y;
  }
  //print
  for(x=0; x<5; x++) {
    for(y=0; y<10; y++)
      printf("%2d ", matrix[x][y]);
    printf("\n");
  }
  //retrieve values
  printf("Enter subscripts or -9 -9 to exit ");
  scanf("%d %d", &x, &y);
  while (x != -9 || y != -9) {
    printf("matrix[%d][%d] is %d\n", x, y, matrix[x][y]);
    printf("Enter subscripts or -9 -9 to exit ");
    scanf("%d %d", &x, &y);
  }
  return 0;
}
