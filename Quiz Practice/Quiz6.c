#include <stdio.h>
#include <string.h>
int main(void) {
char str[10] = "UofA";
int a, b, len;
len = strlen(str);
for (a=0; a<len; a++) {
for (b=0; b<(len-a); b++) {
printf("%c", str[a]);
}
printf("\n");
}
return 0;
}
