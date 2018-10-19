#include <stdio.h>

int main(void) {
  int scores[11] = {0};
  int num, a;

  printf("Enter quiz scores: ");
  scanf("%d", &num);
  while (! feof(stdin)) {
    ++scores[num];
    scanf("%d", &num);
  }

  int max = 0;
  for (a = 0; a < 11; ++a) {
    if (scores[a] > max)
      max = scores[a];
  }

  printf("The score[s] seen the most are: ");
  for (a = 0; a < 11; ++a) {
    if (scores[a] == max)
      printf("%d \n", scores[a]);
  }

  return 0;
}
