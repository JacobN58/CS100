#include <stdio.h>
#include <string.h>
int main(void) {
int a, b, c;
char str[20], ans[20] = "UA";
b = strlen(ans);
for (a=0; a<4; a++) {
scanf("%s", str);
c = strlen(str);
if (c > b) {
printf("Yes\n");
strcpy(ans, str);
b = c;
}
else
printf("No\n");
}
printf("%s and %d\n", ans, b);
return 0;
}
