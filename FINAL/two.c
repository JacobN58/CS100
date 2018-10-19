#include <stdio.h>
#include <string.h>

int sameWhenShifted(char *s1, char *s2){
  int len = strlen(s1);
  if(strlen(s1)!=strlen(s2)) return -1;
  for(int i=0; i<len; i++){
    if(strcmp(s1,s2)==0) return i;
    s2[4]=s1[0];
    s2[3]=s1[1];
    s2[2]=s1[2];
    s2[1]=s1[3];
    s2[0]=s1[4];

      printf("%s\n", s2);
  }
}

int main(int argc, char *argv[]) {
  char s1[100], s2[100];
  printf("Enter string 1 : ");
  scanf("%s", s1);
  printf("Enter string 2 : ");
  scanf("%s", s2);
  int ans = sameWhenShifted(s1, s2);
  if ( ans != -1 )
    printf("%s shifts %d to get %s\n", s1, ans, s2);
  else
    printf("Cannot build %s from %s\n", s2, s1);
  return 0;
}
