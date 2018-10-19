#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*);

int main(int argc, char* argv[]) {
  for(int a=1; a<argc; a++) {
    printf("%s becomes ", argv[a]);
    reverse(argv[a]);
    printf("%s\n", argv[a]);
  }
  return 0;
}

void reverse(char *string) {
  int len = strlen(string);
  char temp[len];
  int lenc = len -1;
  strcpy(temp, string);

  for(int i=0; i<len; i++) {
    string[i] = temp[lenc];
    lenc--;
  }

return;
}
