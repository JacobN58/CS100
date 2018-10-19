#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

FILE *inputFile, *outputFile =  NULL;

inputFile = fopen(argv[1], "r");

if(inputFile == NULL)
  printf("Error. File does not exist.");

else {

outputFile = fopen("integers", "w");

char string[110];

fscanf(inputFile, "%s", string);

while (!feof(inputFile)) {

  int count = 0;

  int i = 1;

  if(isdigit(string[0]) || string[0] == '-') {

  for(i = 1; i < strlen(string); ++i) {

      if(isdigit(string[i]))
        count++;
  }
}
    if(count == strlen(string) - 1)
      fprintf(outputFile, "%s\n", string);

    fscanf(inputFile, "%s", string);
}

fclose(inputFile);

fclose(outputFile);

}

  return 0;
}
