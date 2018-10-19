#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

char str[50];
int counts[26] = {0}, a;

printf("Enter your input :");
scanf("%s", str);

while (! feof(stdin)) {
  int len = strlen(str);
  for ( a = 0; a < len; ++a) {
    char ch = str[a];
    if (islower(ch)) {
      int sub = ch - 97;
      ++counts[sub];
    }
  }
scanf("%s", str);
}
    printf("Missing letters : ");
    for (a = 0; a < 26; ++a) {
      if (counts[a] == 0)
        printf("%c ", a + 97);
      }
}
