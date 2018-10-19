/*#include <stdio.h>
#include <string.h>

int main(void) {

  char str[50];
  printf("Enter your text: ");
  scanf("%s", str);
  printf("\n");
  while(! feof(stdin)) {
    int len = strlen(str);
      if(strlen(str)==1) {
        printf("%c\n", str[0]);
          scanf("%s", str);
      }
      else {
        printf("%c", str[0]);
        printf("%c\n", str[len-1]);
          scanf("%s", str);
      }
  }
return 0;
}
*/


FUCKED PROGRAM v
/*#include <stdio.h>

int main(void) {

int students=0, num, score;
  printf("Enter a score to check on the exam: ");
  scanf("%d", &score);
  FILE *DATA = fopen("DATA", "r");

  fscanf(DATA, "%d", &num);

  while(score != -1) {
    while(! feof(DATA)){
      if(num<score) {
        students++;
      }
      fscanf(DATA, "%d", &num);
    }
    printf("%d scored lower than %d\n", students, score);
    printf("Enter a score to check on the exam: ");
    scanf("%d", &score);
    students=0;
  }
  fclose(DATA);
return 0;
}
*/
