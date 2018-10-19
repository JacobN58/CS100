#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ignoreCase(char *str1, char *str2) {

  if(strcasecmp(str1, str2) == 0)
    return 1;

  else
    return 0;
}

int main(void) {

  char input1[1024], input2[1024];

  printf("Enter a string : ");

  scanf("%s", input1);

  printf("Enter another string : ");

  scanf("%s", input2);

  if (ignoreCase(input1, input2))
    printf("%s and %s are the same if you ignore case\n", input1, input2);

  else
    printf("%s and %s are not the same, even ignoring case\n", input1, input2);

  return 0;

}
