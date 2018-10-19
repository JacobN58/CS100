#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

  char str[100];
  FILE *datafile = fopen("datafile", "r");
  FILE *words = fopen("words", "w");
  FILE *numbers = fopen("numbers", "w");

  fscanf(datafile, "%s", str);

while(! feof(datafile)){
  int word=0, number=0;
  int len=strlen(str);
for(int a=0; a<len; a++){
if (isalpha(str[a])){
  word++;
}
if(isdigit(str[a])){
  number++;
}
}

if(word==len){

    fprintf(words, "%s\n", str);
}
if(number==len){

    fprintf(numbers, "%s\n", str);
  }
  fscanf(datafile, "%s", str);
}
  fclose(datafile);
  fclose(words);
  fclose(numbers);
return 0;
}
