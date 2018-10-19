#include <stdio.h>
#include <string.h>

int main(void) {
  char str[50];
  printf("Enter a string : ");
  scanf("%s", str);
  printf("The string is %s\n", str);

  int len = strlen(str);
  str[11] = str[9];
  str[10] = str[8];
  str[9] = str[7];
  str[8] = str[6];
  str[7] = '-';
  str[6] = str[5];
  str[5] = str[4];
  str[4] = str[3];
  str[3] = '-';
  str[2] = str[2];
  str[1] = str[1];
  str[0] = str[0];

  printf("The string is %s\n", str);
  return 0;
}
