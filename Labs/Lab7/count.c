#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void counts(char *, int *, int *, int *);

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  char str[100];
  fscanf(fp, "%s", str);
  while(! feof(fp)) {
    int upper, lower, digit;
    counts(str, &upper, &lower, &digit);
    printf("%s has %d uppercase, %d lowercase, and %d digits\n", str, upper, lower, digit);
    fscanf(fp, "%s", str);
  }
  return 0;
}

void counts(char *string, int *up, int *low, int *dig) {
  int len = strlen(string);
  *up =0;
  *low =0;
  *dig =0;
  for(int i=0; i<len; i++) {
    if(isupper(string[i])) {
      *up = *up + 1;
    }
    if(islower(string[i])) {
      *low = *low + 1;
    }
    if(isdigit(string[i])) {
      *dig = *dig + 1;
    }
  }
  return;
}
