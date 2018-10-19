#include <stdio.h>
#include <string.h>

int main(void) {

  char str[50];
  printf("Enter a strings, terminating with xxx\n");
  scanf("%s", str);

  int a = 0;
  int b = strlen(str) - 1;
  int c = 0;

  while (strcmp(str, "xxx") != 0) {
    if (str[a] == str[b])
    c = c + 1;

    a = a + 1;
    b = b - 1;
    scanf("%s", str);
    }
    printf("%d have same first and last character\n", c);

  return 0;
}
