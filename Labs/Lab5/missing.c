#include <stdio.h>
#include <string.h>
#include <ctype.h>

void incrementCounts (char str[100], int counts[26]){
  int len = strlen(str);
  for (int a = 0; a < len; ++a) {
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
  return;
}

void printMissing (int counts[26]){
  printf("Missing letters : ");
  for (int a = 0; a < 26; ++a) {
    if (counts[a] == 0)
      printf("%c ", a + 97);
    }
}

int main(void) {

char str[100];
int counts[26] = {0}, a;

printf("Enter some text, ending with <control-d> :");
scanf("%s", str);

while (! feof(stdin)) {
  incrementCounts(str, counts);
  scanf("%s", str);
}

printMissing(counts);
return 0;
}
