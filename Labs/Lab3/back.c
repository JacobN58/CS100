#include <stdio.h>
#include <string.h>

int main(void) {

  char str[20];
  printf("Enter a string : ");
  scanf("%s", str);

  int len = strlen(str);

  while (! feof(stdin)) {
    if (len != 0){
      printf("%c", str[len-1]);
      len--;
    }
    else{
      printf("\nEnter a string : ");
      scanf("%s", str);
      len = strlen(str);
    }
  }
  return 0;
  }
