#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    int red, green, blue;
} Pixel;

typedef struct ppm {
    int rows, cols, colors;
    Pixel **pixels;
} ppmPic;

void writeGrayScale(ppmPic *, char *);

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  ppmPic *pic = malloc(sizeof(ppmPic));
  char str[10];
  fscanf(fp, "%s", str);
  fscanf(fp, "%d %d", &pic->cols, &pic->rows);
  fscanf(fp, "%d", &pic->colors);
  pic->pixels = malloc(sizeof(Pixel *) * pic->rows);
  for (int i=0; i<pic->rows; i++)
      pic->pixels[i] = malloc(sizeof(Pixel) * pic->cols);
  for (int i = 0; i < pic->rows; i++) {
      for (int j=0; j < pic->cols; j++) {
          fscanf(fp, "%d", &pic->pixels[i][j].red);
          fscanf(fp, "%d", &pic->pixels[i][j].green);
          fscanf(fp, "%d", &pic->pixels[i][j].blue);
      }
  }
  fclose(fp);
  writeGrayScale(pic, argv[2]);
  return 0;
}

void writeGrayScale(ppmPic *pic, char *argv) {
	char newfileName[20] = "answer.pgm";

//printf("%s\n", newfileName);

	FILE *fp;
	fp = fopen(newfileName, "w");
	fprintf(fp, "P2\n");
	fprintf(fp, "%d %d %d\n", pic->cols, pic->rows, pic->colors);

//printf("%d %d %d\n", myPic->cols, myPic->rows, myPic->colors);

	for(int r=0; r<(pic->rows); r++) {
		for(int c=0; c<(pic->cols); c++) {
      int grayscale = (pic->pixels[r][c].red * 0.3) + (pic->pixels[r][c].green * 0.59) + (pic->pixels[r][c].blue * 0.11);
			fprintf(fp, "%d ", grayscale);
			fprintf(fp, "\t");
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
  return;
}
