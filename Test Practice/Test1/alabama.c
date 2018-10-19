#include <stdio.h>
#include <string.h>
int main(void) {
char str[20];
scanf("%s", str);
int a = 0;
int b = strlen(str) - 1;
int c = 0;
while (a <= b) {
if (str[a] == str[b])
c = c + 1;
printf("%c + %c\n", str[a], str[b]);
a = a + 1;
b = b - 1;
}
printf("%d\n", c);
return 0;
}
