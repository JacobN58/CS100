#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int, int);
void initMatrix(int **, int, int);
int findRange(int **, int, int);
double findAverage(int **, int, int);
void printCorners(int **, int, int);

int main(int argc, char *argv[]) {
	int **data;
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	data = allocateMatrix(row, col);
	initMatrix(data, row, col);
	printf("The range of values is %d\n", findRange(data, row, col) );
	printf("The average of all values is %lf\n", findAverage(data, row, col) );
	printCorners(data, row, col);

	return 0;
}

int **allocateMatrix(int r, int c) {
	// allocate a two-dimensional array of integers
	//	array has r rows and c columns
	//	do NOT initialize any of the values in the matrix
	//	return a pointer to this newly allocated matrix
  int **array = malloc (sizeof(int) * r);
  for(int x=0; x<r; x++)
      array[x] = malloc (sizeof(int) * c);
	return array;
}

void initMatrix(int **array, int r, int c) {
	// initialize your random number generator with srand(0)
	// using a nested loop, put a value 0-999 in each element of the array, rand()%1000
  srand(0);
  for(int x=0; x<r; x++) {
    for(int y=0; y<c; y++)
      array[x][y] = rand()%1000;
    }
    return;
}

int findRange(int **array, int r, int c) {
	// find the range of all values in the matrix
	//	find the maximum value and minimum values
	//	range is simply max - min
  int max = array[0][0], min = array[0][0];
  for(int x=0; x<r; x++) {
    for(int y=0; y<c; y++) {

      if (array[x][y] > max)
        max = array[x][y];
      else if (array[x][y] < min)
        min = array[x][y];
      }
    }
    int range = max - min;
	return range;
}


double findAverage(int **array, int r, int c) {
	// find the average of all values in the matrix
  double avg = 0.0, avgfin, avgcount = 0.0;
  for(int x=0; x<r; x++) {
    for(int y=0; y<c; y++) {
      avg = avg + array[x][y];
      avgcount++;
    }
  }
  avgfin = avg / avgcount;
	return avgfin;
}

void printCorners(int **array, int r, int c) {
	// print the four corners of the matrix
	//	print format
	//		upper-left upper-right
	//		lower-left lower-right
	// for a 1x1 matrix, print the single value four times
  printf("\n%d %d\n%d %d", array[0][0], array[0][c-1], array[r-1][0], array[r-1][c-1]);
  return;
}
