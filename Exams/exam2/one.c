#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

  int prev, next;
  FILE *good = fopen("good", "w");
  FILE *bad = fopen("bad", "w");

printf("Enter your data: ");
scanf("%d", &prev);
fprintf(good, "%d\n", prev);
scanf("%d", &next);

while(! feof(stdin)){
  if(prev>next) {
    fprintf(bad, "%d\n", next);
  }
  if(prev<next){
    fprintf(good, "%d\n", next);
  }
  prev=next;
  scanf("%d", &next);
}
  fclose(good);
  fclose(bad);
return 0;
}
