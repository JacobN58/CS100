#include <stdio.h>

int fact(int a) {
  int answer = 0;
  for(int i =a; i>0; i--) {
    answer = answer + i;
  }
  return answer;
}

int fact2(int a) {
  if(a==1) return 1; //base case, when to stop
  return a + fact2(a-1); //recursive case
}

int main(void) {

  printf("Enter a number : ");
  int num;
  scanf("%d", &num);

  int ans = fact(num);
  printf("%d ! is %d\n", num, ans);

  int ans2 = fact2(num);
  printf("%d ! is %d\n", num, ans2);
  return 0;
}
