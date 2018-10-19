#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

  FILE* input = fopen("NAMES", "r");
  char buffer[500]; //place to store input name temp
  char* names[5000]; //pointers to the 5000 names

  for(int i=0; i<5000; i++) {
    fscanf("NAMES", %s, buffer);
    int len = strlen(buffer);
    names[i] = malloc(len+1);
    strcpy(names[i], buffer);
  }

  for(int i=0; i<5000; i++) {
    printf("%s ", names[i]);
    printf("\n");
  }
  return 0;
}
