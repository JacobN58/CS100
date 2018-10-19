//Jacob Nelson. Program to merge two files of text in and out to make it into readable text
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char *readableTime(int); //makes the epoch time readable
void phonenumber(char*, FILE*); //formats the phonenumber
void merge(FILE*, FILE*, char*, char*, int); //merges the two formatted files
void process1(FILE*, int, char*, long); //formats the text_in data
void process2(FILE*, int, char*, long); //formats the text_out data


int main(int argc, char *argv[]) {
  char str1[100], str2[100];
  int wordCount = 0;

  FILE *text_in = fopen(argv[1], "r");
  FILE *text_out = fopen(argv[2], "r");
  if (argv[1] == NULL||argv[2] == NULL) {
    printf("Input file entered incorrectly\n");
    return 0;
  }

  merge(text_in, text_out, str1, str2, wordCount);

  fclose(text_in);
  fclose(text_out);
return 0;
}


char *readableTime(int sec) {
 time_t epoch_time = (time_t) sec;
 return asctime( localtime( &epoch_time ) );
}


void phonenumber(char* str, FILE* text_in) {
  fscanf(text_in, "%s", str);
  str[11] = str[9];
  str[10] = str[8];
  str[9] = str[7];
  str[8] = str[6];
  str[7] = '-';
  str[6] = str[5];
  str[5] = str[4];
  str[4] = str[3];
  str[3] = '-';
  str[2] = str[2];
  str[1] = str[1];
  str[0] = str[0];
  printf("%s", str);
  return;
}


void merge(FILE* text_in, FILE* text_out, char* str1, char* str2, int wordCount) {
  long time1=0, time2=0;
  fscanf(text_in, "%ld", &time1);
  fscanf(text_out, "%ld", &time2);
  while (! feof(text_in) && ! feof(text_out)){
    if ( time1 < time2 ){
      process1(text_in, wordCount, str1, time1);
      fscanf(text_in, "%ld", &time1);
    }
    else{
      process2(text_out, wordCount, str2, time2);
      fscanf(text_out, "%ld", &time2);
    }
  }
  while (! feof(text_in)){
    process1(text_in, wordCount, str1, time1);
    fscanf(text_in, "%ld", &time1);
  }
  while (! feof(text_out)) {
    process2(text_out, wordCount, str2, time2);
    fscanf(text_out, "%ld", &time2);
  }
  return;
}


void process1(FILE* text_in, int wordCount, char* str1, long time1) {
  char* strTime= readableTime(time1);
  strTime[(strlen(strTime)-1)]=' ';
  printf("%s From ", strTime);
  phonenumber(str1, text_in);
  printf(" | ");
  int len = 0;
  fscanf(text_in, "%d", &wordCount);
  for(int i=0; i<wordCount; i++) {
    fscanf(text_in, "%s", str1);
    if(len == 0 ) {
      printf("%s", str1);
      len = strlen(str1);
    }
    else {
      len = len + strlen(str1) + 1;
      if(len <= 40) {
        printf("%s", str1);
      }
      if(len > 40) {
        len = 0;
        printf("\n\t\t\t\t\t");
        printf("    | ");
        printf("%s", str1);
        len = len + strlen(str1) + 1;
      }
    }
    printf(" ");
  }
  printf("\n");
}


void process2(FILE* text_out, int wordCount, char* str2, long time2) {
  char* strTime= readableTime(time2);
  strTime[(strlen(strTime)-1)]=' ';
  printf("%s   To ", strTime);
  phonenumber(str2, text_out);
  printf(" | ");
  int len = 0;
  fscanf(text_out, "%d", &wordCount);
  for(int i=0; i<wordCount; i++) {
    fscanf(text_out, "%s", str2);
    if(len == 0 ) {
      printf("%s", str2);
      len = strlen(str2);
    }
    else {
      len = len + strlen(str2) + 1;
      if(len <= 40) {
        printf(" %s", str2);
      }
      if(len > 40) {
        len = 0;
        printf("\n\t\t\t\t\t");
        printf("    | ");
        printf("%s ", str2);
        len = len + strlen(str2) + 1;
      }
    }
  }
  printf("\n");
}
