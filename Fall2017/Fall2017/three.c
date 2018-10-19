#include <stdio.h>
#include <stdlib.h>

int hasDups(int **matrix, int size, int row) {

  int i, j = 0;

  for(i = 0; i < size; ++i) {

    for(j = i + 1; j < size; ++j) {

      if(matrix[row][i] == matrix[row][j])
        return 1;
    }
  }

return 0;

}

int main(int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");

  int size = atoi(argv[2]);

  // allocate the matrix

  int **matrix;

  matrix = malloc( sizeof(int *) * size );

  for (int a = 0; a < size; a++)
    matrix[a] = malloc(sizeof(int) * size);

  // read the matrix
  for (int a = 0; a < size; a++)
    for (int b = 0; b < size; b++)
      fscanf(fp, "%d", &matrix[a][b]);

  int row;

  printf("Enter the row : ");

  scanf("%d", &row);

  // compute the answer
  int ans = hasDups(matrix, size, row);

  if (ans == 1)
    printf("Row %d has duplicates\n", row);

  else
    printf("No dupicates in row %d\n", row);

  return 0;

}
