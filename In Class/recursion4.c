#include <stdio.h>
#include <string.h>

int countCs(char *str) {
  if(str[0] == '\0') return 0;

  if(str[0] == 'C' || str[0] == 'c') return 1 + countCs(str+1);

  return 0 + countCs(str+1);
}

int main(void) {
  char str[100];
  printf("Enter a string : ");
  scanf("%s", str);
  int ans = countCs(str);

  printf("%s contains %d C's\n", str, ans);
  return 0;
}
