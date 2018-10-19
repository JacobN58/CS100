#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int commonStart(char [], char []);

int main(void) {
  char str1[50], str2[50];
  printf("Enter two strings : ");
  scanf("%s %s", str1, str2);
  printf("There are %d common letters at start of %s and %s\n\n", commonStart(str1, str2), str1, str2);
  return 0;
}

int commonStart(char str1[50], char str2[50]) {
  int num=0;
  for(int i=0; i<50; i++) {
    char ch1 = str1[i];
    char ch2 = str2[i];
    if(ch1==ch2) {
      num++;
    }
    if(ch1!=ch2) {
      return num;
    }
  }
  return num;
}
