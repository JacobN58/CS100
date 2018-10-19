#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
     int rows;
     int columns;
     int **data;
} Grid;

Grid *readData(FILE *fp) {

  Grid *theGrid = malloc(sizeof(Grid));

  fscanf(fp, "%d", &theGrid->rows);

  fscanf(fp, "%d", &theGrid->columns);

  theGrid->data = malloc(sizeof(int*) * theGrid->rows);

  int i, j = 0;

  for (i = 0; i < theGrid->rows; ++i) {
    theGrid->data[i] = malloc(sizeof(int) * theGrid->columns);

    for(j = 0; j < theGrid->columns; ++j)
      fscanf(fp, "%d", &theGrid->data[i][j]);

    }

  return theGrid;
 }

 double findAvg(Grid *myGrid) {

  int total = 0;

  int n = 0;

  for(int i = 0; i < myGrid->rows; i++) {

    for(int j = 0; j < myGrid->columns; j++) {

      total += myGrid->data[i][j];

      n++;
    }
  }

   return total / n;
 }

 void printStats(Grid *myGrid) {

   printf("The average elevation is %lf", findAvg(myGrid));

   return;
 }

 int main(int argc, char *argv[]) {

   Grid *myGrid;

   FILE *fp = fopen(argv[1], "r");

   if (!fp) {
     printf("No such file\n");
     exit(1);
   }

   myGrid = readData(fp);

   printStats(myGrid);

   fclose(fp);

   return 0;
 }
