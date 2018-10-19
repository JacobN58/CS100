#include <stdio.h>
#include <string.h>

int main(void) {

  char str[50];
  printf("Enter a string : ");
  scanf("%s", str);

  while (strcmp(str, "") != 0) {
    printf("%s\n", str);
    int len = strlen(str);
    str[len-1] = '\0';
  }
  return 0;
  }
