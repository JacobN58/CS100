#include <stdio.h>
#include <string.h>

int main(void) {
  char word[20];
  int i;
  int length;

  printf("Enter word(s) (ctr-d to exit):\n");
  scanf("%s", word);

  while (! feof(stdin)) {
    length = strlen(word);
    for (i = length; i >= 0; --i) {
      printf("%c", word[i]);
    }
    printf("\n");
    scanf("%s", word);
  }

  return 0;
}
