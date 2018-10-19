#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char str[50];
  int counts[26] = {0};
  int a;

  printf("Enter a string (ctr-d to end): ");
  scanf("%s", str);

  while (! feof(stdin)) {
    int len = strlen(str);
    for ( a = 0; a < len; ++a) {
      char ch = str[a];
      if (islower(ch)) {
        int sub = ch - 97;
        ++counts[sub];
      }
      if (isupper(ch)) {
        int sub = ch - 65;
        ++counts[sub];
      }
    }
    scanf("%s", str);
  }
  for (a = 0; a < 26; ++a) {
    printf("%d ", counts[a]);
  }
  printf("\n");

  int max = counts[0];
  for (a = 1; a < 26; ++a) {
    if (counts[a] > max)
      max = counts[a];
  }
  printf("%d ", max);

  for (a = 0; a < 26; ++a) {
    if (counts[a] == max)
      printf("%c", a + 97);
  }
  printf("\n");

  return 0;
}
