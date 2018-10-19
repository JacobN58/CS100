#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

//////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(char *fileName) {
	FILE *fp;
	fp = fopen(fileName, "r");
	//allocate space
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	//P3
	char p3[3];
	fscanf(fp, "%s", p3);
	//read cols rows and colors
	fscanf(fp, "%d %d", &myPic->cols, &myPic->rows);
	fscanf(fp, "%d", &myPic->colors);

//printf("%s %d %d %d\n", p3, myPic->cols, myPic->rows, myPic->colors);

	//allocate for 2d array
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for(int i=0; i<(myPic->rows); i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	//read pixel values
	for(int a=0; a<(myPic->rows); a++) {
		for(int b=0; b<(myPic->cols); b++) {
			fscanf(fp, "%d", &myPic->pixels[a][b].red);
			fscanf(fp, "%d", &myPic->pixels[a][b].green);
			fscanf(fp, "%d", &myPic->pixels[a][b].blue);

//printf("%d %d %d\n", myPic->pixels[a][b].red, myPic->pixels[a][b].green, myPic->pixels[a][b].blue);
		}
//printf("\n");
	}
	fclose(fp);
	return myPic;
}

void writePic(ppmPic *myPic, char *fileName) {
	int len = strlen(fileName);
	char newfileName[len];
	strcpy(newfileName, fileName);
	newfileName[len-4] = '-'; newfileName[len-3] = 'N'; newfileName[len-2] = 'E'; newfileName[len-1] = 'W';
	strcat(newfileName, ".ppm\0");

//printf("%s\n", newfileName);

	FILE *fp;
	fp = fopen(newfileName, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d %d\n", myPic->cols, myPic->rows, myPic->colors);

//printf("%d %d %d\n", myPic->cols, myPic->rows, myPic->colors);

	for(int a=0; a<(myPic->rows); a++) {
		for(int b=0; b<(myPic->cols); b++) {
			fprintf(fp, "%d ", myPic->pixels[a][b].red);
			fprintf(fp, "%d ", myPic->pixels[a][b].green);
			fprintf(fp, "%d ", myPic->pixels[a][b].blue);
			fprintf(fp, "\t");
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}

ppmPic *rotateLeft(ppmPic *thePic) {
	ppmPic *tempPic = malloc(sizeof(ppmPic));
	tempPic->cols = thePic->rows;
	tempPic->rows = thePic->cols;
	tempPic->colors = thePic->colors;
	tempPic->pixels = malloc(sizeof(Pixel *) * tempPic->rows);

	for(int i=0; i<(tempPic->rows); i++) {
		tempPic->pixels[i] = malloc(sizeof(Pixel) * tempPic->cols);
	}
	for(int r=0; r<(tempPic->rows); r++) {
		for(int c=0; c<(tempPic->cols); c++) {
			int len = (tempPic->rows);
			tempPic->pixels[r][c].red = thePic->pixels[c][len-r-1].red;
			tempPic->pixels[r][c].green = thePic->pixels[c][len-r-1].green;
			tempPic->pixels[r][c].blue = thePic->pixels[c][len-r-1].blue;
		}
	}
	return tempPic;
}

ppmPic *rotateRight(ppmPic *thePic) {
	ppmPic *tempPic = malloc(sizeof(ppmPic));
	tempPic->cols = thePic->rows;
	tempPic->rows = thePic->cols;
	tempPic->colors = thePic->colors;
	tempPic->pixels = malloc(sizeof(Pixel *) * tempPic->rows);

	for(int i=0; i<(tempPic->rows); i++) {
		tempPic->pixels[i] = malloc(sizeof(Pixel) * tempPic->cols);
	}
	for(int r=0; r<(tempPic->rows); r++) {
		for(int c=0; c<(tempPic->cols); c++) {
			int len = (tempPic->cols);
			tempPic->pixels[r][c].red = thePic->pixels[len-c-1][r].red;
			tempPic->pixels[r][c].green = thePic->pixels[len-c-1][r].green;
			tempPic->pixels[r][c].blue = thePic->pixels[len-c-1][r].blue;
		}
	}
	return tempPic;
}

ppmPic *flipHorizontal(ppmPic *thePic) {
	for(int r=0; r<(thePic->rows); r++) {
		for(int c=0; c<(thePic->cols/2); c++) {
			Pixel tempPic = thePic->pixels[r][c];
			thePic->pixels[r][c] = thePic->pixels[r][thePic->cols-c-1];
			thePic->pixels[r][thePic->cols-c-1] = tempPic;
		}
	}
	return thePic;
}

ppmPic *flipVertical(ppmPic *thePic) {
	for(int r=0; r<(thePic->rows/2); r++) {
		for(int c=0; c<(thePic->cols); c++) {
			Pixel tempPic = thePic->pixels[r][c];
			thePic->pixels[r][c] = thePic->pixels[thePic->rows-r-1][c];
			thePic->pixels[thePic->rows-r-1][c] = tempPic;
		}
	}
	return thePic;
}

ppmPic *invert(ppmPic *thePic) {
	for(int r=0; r<(thePic->rows); r++) {
		for(int c=0; c<(thePic->cols); c++) {
			thePic->pixels[r][c].red = (thePic->colors) - (thePic->pixels[r][c].red);
			thePic->pixels[r][c].green = (thePic->colors) - (thePic->pixels[r][c].green);
			thePic->pixels[r][c].blue = (thePic->colors) - (thePic->pixels[r][c].blue);
		}
	}
	return thePic;
}

ppmPic *duplicate(ppmPic *thePic) {
	return thePic;
}
