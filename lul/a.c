#include <stdio.h>
#include <string.h>

// counts A's in strings

int main(void) {
  char str[50];
  int count = 0;

  printf("Enter a string: ");
  scanf("%s", str);

  while (! feof(stdin)) { // ctr-d to exit
    int len = strlen(str);
    for (int x = 0; x < len; x++) {
      if ((str[x] == 'A') || (str[x] == 'a'))
        count++;
    }
    printf("Enter another string: ");
    scanf("%s", str);
  }

  printf("We saw %d A's\n", count);

  return 0;
}
