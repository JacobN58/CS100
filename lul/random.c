#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));
  int a;
  for (a = 0; a < 50; ++a) {
    int x;
    x = rand() % 10;
    printf("%d ", x);
  }

  printf("\n");

  return 0;
}
