#include <stdio.h>
#include <string.h>

int main(void) {

  char str[50];
  printf("Enter a string : ");
  scanf("%s", str);
    int a = 0;
    int len = strlen(str);
    while (a < len) {
        printf("%s\n", str);
        a = a + 1;
    }
return 0;
}
