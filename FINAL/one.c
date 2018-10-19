#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

  char str1[100], str2[100], str3[100];
  int sensors=atoi(argv[1]), bad1=0, bad2=0, bad3=0, unknown=0, none=0;
  FILE *data1 = fopen(argv[2], "r");
  FILE *data2 = fopen(argv[3], "r");
  FILE *data3 = fopen(argv[4], "r");

  fscanf(data1, "%s", str1);
  fscanf(data2, "%s", str2);
  fscanf(data3, "%s", str3);

for(int i=0; i<sensors; i++){
  if(strcmp(str1, str2)==0 && strcmp(str2, str3)==0) {
    none++;
  }
  if(strcmp(str1, str3)==0 && strcmp(str1, str2)!=0) {
    bad2++;
  }
  if(strcmp(str1, str2)!=0 && strcmp(str2, str3)==0) {
    bad1++;
  }
  if(strcmp(str1, str3)!=0 && strcmp(str1, str2)==0) {
    bad3++;
  }
  if(strcmp(str1, str2)!=0 && strcmp(str1, str3)!=0 && strcmp(str2, str3)!=0) {
    unknown++;
  }
  fscanf(data1, "%s", str1);
  fscanf(data2, "%s", str2);
  fscanf(data3, "%s", str3);
}
printf("Data1 has %d possible bad values\n", bad1);
printf("Data2 has %d possible bad values\n", bad2);
printf("Data3 has %d possible bad values\n", bad3);
printf("There are %d unknown cases\n", unknown);


  fclose(data1);
  fclose(data2);
  fclose(data3);
return 0;
}
