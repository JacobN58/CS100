#include <stdio.h>
#include <string.h>

int myStrlen(char *);

int main(void) {
  char str[50];
  printf("Enter a string : ");
  scanf("%s", str);
  int len = myStrlen(str);
  printf("The string %s is %d characters long\n", str, len);

  return 0;
  }

int myStrlen(char *str) {
  int count = 0;
  char *ptr = str;
  while (*ptr != '\0'){
    count = count + 1;
    ptr = ptr + 1;
    }
    return count;
  }
