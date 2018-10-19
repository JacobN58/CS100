#include <stdio.h>
#include <string.h>

int main(void) {

  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];
  printf("Enter 4 strings : ");
  scanf("%s %s %s %s", str1, str2, str3, str4);

  if (strcmp(str1, str2) == 0 || strcmp(str1, str3) == 0 || strcmp(str1, str4) == 0)
  printf("Match");
  else if (strcmp(str2, str1) == 0 || strcmp(str2, str3) == 0 || strcmp(str2, str4) == 0)
  printf("Match");
  else if (strcmp(str3, str1) == 0 || strcmp(str3, str2) == 0 || strcmp(str3, str4) == 0)
  printf("Match");
  else if (strcmp(str4, str1) == 0 || strcmp(str4, str2) == 0 || strcmp(str4, str3) == 0)
  printf("Match");
  else
  printf("No Match");

  return 0;
}
