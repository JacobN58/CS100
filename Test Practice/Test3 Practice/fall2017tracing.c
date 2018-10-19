//./a.exe ABC dog hike COP 13597
/*
#include <stdio.h>
#include <string.h>
int function(char *str) {
 int len = strlen(str) - 1;
 for (int a=0; a<len; a++)
 if (str[a] > str[a+1])
 return 1;
 return 0;
}
int main(int argc, char *argv[]) {
 for (int a=1; a<argc; a++)
 printf("%d\n", function(argv[a]) );
 return 0;
}
*/

//./a.exe data1

#include <stdio.h>
int main(int argc, char *argv[]) {
int num, data[3][3];
for (int a=0; a<3; a++)
for (int b=0; b<3; b++)
data[a][b] = 0;
FILE *fp = fopen(argv[1], "r");
fscanf(fp, "%d", &num);
while ( ! feof(fp) ) {
int x = num / 10;
int y = num % 10;
data[x][y] = data[x][y] + 1;
fscanf(fp, "%d", &num);
}
fclose(fp);
for (int a=0; a<3; a++) {
for (int b=0; b<3; b++)
printf("%d ", data[a][b]);
printf("\n");
}
return 0;
}
