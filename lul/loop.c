#include <stdio.h>
#include <string.h>

int main(void) {
  char str[50];
  printf("Enter a string: ");
  scanf("%s", str);

  int a = 0;
  while ( str[a] != '\0' ) {
    printf("%c\n", str[a]);
    ++a;
  }

  printf("\n\n");

  int len = strlen(str);
  for (a = 0; a < len; ++a) {
    printf("%c\n", str[a]);
  }

  return 0;
}
