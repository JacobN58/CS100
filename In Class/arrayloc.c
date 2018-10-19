#include <stdio.h>

int main(void) {
  int array[5] = {1,2,3,4,5};

  printf("array[0] is %d at location %p\n", array[0], &array[0]);
  printf("array[1] is %d at location %p\n", array[1], &array[1]);
  printf("array[2] is %d at location %p\n", array[2], &array[2]);
  printf("array[3] is %d at location %p\n", array[3], &array[3]);
  printf("array[4] is %d at location %p\n", array[4], &array[4]);

printf("and the array itself starts at %p\n", array);
return 0;
}
