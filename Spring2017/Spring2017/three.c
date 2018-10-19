#include <stdio.h>
#include <stdlib.h>

int *allocateArray(int);
void readArray(int *, int);
int alternates(int *, int);

int main( void ) {

  int size;

  printf("Enter the size of the array : ");

  scanf("%d", &size);

  int *array = allocateArray(size);

  printf("Enter array values (%d values) : ", size);

  readArray(array, size);

  int ans = alternates(array, size);

  if (ans == 1)
    printf("The array alternates\n");

  else
    printf("The array does not alternate\n");

  return 0;
}

int *allocateArray(int size) {

  int *arr = (int*) malloc(sizeof(int) * size);

  return arr;

}

void readArray(int *matrix, int size) {

  int i = 0;

  for(i = 0; i < size; i++)
    scanf("%d", &matrix[i]);

  return;

}

int alternates(int *arr, int size) {

  int i = 0;

  for(i = 0; i + 1 < size; ++i) {

    if((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1))
      return 0;
  }
  
  return 1;
}
