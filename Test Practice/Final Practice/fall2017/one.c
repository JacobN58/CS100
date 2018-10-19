#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

  char str[100];
  FILE *datafile = fopen("datafile", "r");

  fscanf(datafile, "%s", str);

while(! feof(datafile)){
  int number=0, neg=0;
  int len=strlen(str);
for(int a=0; a<len; a++){
  if(str[a]=='-'){
    neg++;
  }
  if(isdigit(str[a]) || neg==1){
    number++;
}

}
if(number==len){

    printf("%s\n", str);
  }
  fscanf(datafile, "%s", str);
}
  fclose(datafile);
return 0;
}
