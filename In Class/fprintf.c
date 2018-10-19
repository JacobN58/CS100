#include <stdio.h>
// read numbers from one file, write to another
int main(void){

int num;
FILE *fpIn, *fpOut;

printf("Enter the name of the input file : ");
char str[50];
scanf("%s", str);
fpIn = fopen(str, "r");

if (fpIn == NULL){
  printf("The file %s does not exist\n", str);
  return 0;
}

printf("Enter the name of the output file : ");
scanf("%s", str);
fpOut = fopen(str, "w");

fscanf(fpIn, "%d", &num);
while( ! feof(fpIn)){
  fprintf(fpOut, "%d\n", num);
  fscanf(fpIn, "%d", &num)
}
fclose(fpIn)
fclose(fpOut);
return 0;
}
