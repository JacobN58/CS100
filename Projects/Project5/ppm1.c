#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

//////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(char *fileName) {
	char P3[5];
	int r;
	int c;

	FILE *fp;
	fp = fopen(fileName, "r");

	ppmPic *myPic = malloc ( sizeof (ppmPic) );

	fscanf(fp,"%s", P3);

	if (strcmp(P3, "P3") != 0) {
		printf("\nUse a proper image");
	}

	else {
		fscanf(fp, "%d", &myPic->cols);
		fscanf(fp, "%d", &myPic->rows);
		fscanf(fp, "%d", &myPic->colors);

		r = myPic->rows;
		c = myPic->cols;

		myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
		for (int i = 0; i < r; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}

		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				fscanf(fp, "%d", &myPic->pixels[i][j].red);
				fscanf(fp, "%d", &myPic->pixels[i][j].green);
				fscanf(fp, "%d", &myPic->pixels[i][j].blue);

			//	printf("%d %d %d\n", myPic->pixels[i][j].red, myPic->pixels[i][j].green, myPic->pixels[i][j].blue);
			}
		}

	//	printf("%d %d %d\n", myPic->cols, myPic->rows, myPic->colors);
	}
	fclose(fp);
	return myPic;
}

void writePic(ppmPic *myPic, char *fileName) {
	int len = strlen(fileName);
	int lenNew = len - 4;
	char newPicName[len];

	strcpy(newPicName, fileName);

	newPicName[lenNew] = '\0';

	strcat(newPicName, "-NEW.ppm\0");

	FILE *fp;
	fp = fopen(newPicName, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d ", myPic->cols, myPic->rows);
	fprintf(fp, "%d\n", myPic->colors);

	for (int i = 0; i < (myPic->cols); i++) {
		for (int j = 0; j < (myPic->rows); j++) {
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);

	return;
}

ppmPic *rotateLeft(ppmPic *thePic) {
	return NULL;
}

ppmPic *rotateRight(ppmPic *thePic) {
	return NULL;
}

ppmPic *flipHorizontal(ppmPic *thePic) {
	return NULL;
}

ppmPic *flipVertical(ppmPic *thePic) {
	return NULL;
}

ppmPic *invert(ppmPic *thePic) {
	return NULL;
}

ppmPic *duplicate(ppmPic *thePic) {
	return thePic;
}
