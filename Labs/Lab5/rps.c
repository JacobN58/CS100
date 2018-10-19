#include <stdio.h>
#include <stdlib.h>

int getNumgames(void){
  int games;
  printf("Enter the number of games you wish to play : ");
  scanf("%d", &games);
  return games;
}

int findWinner(int p1move, int p2move){
  //ties
  if (p1move == 0 && p2move == 0)
    return 0;
  if (p1move == 1 && p2move == 1)
    return 0;
  if (p1move == 2 && p2move == 2)
    return 0;

//p1wins
  if (p1move == 0 && p2move == 2)
    return 1;
  if (p1move == 1 && p2move == 0)
    return 1;
  if (p1move == 2 && p2move == 1)
    return 1;

  //p2wins
  if (p1move == 2 && p2move == 0)
    return 2;
  if (p1move == 0 && p2move == 1)
    return 2;
  if (p1move == 1 && p2move == 2)
    return 2;
}

void printResults(int ties, int p1wins, int p2wins){
  printf("Ties : %d\n", ties);
  printf("P1 wins : %d\n", p1wins);
  printf("P2 wins : %d\n", p2wins);
  return;
}

int main(void){
  srand(0);
  int games, p1move, p2move, ans;
  int ties=0, p1wins=0, p2wins=0;
  games=getNumgames();
  for(int a=0; a<games; a++){
    p1move=rand() % 3;
    p2move=rand() % 3;
    ans = findWinner(p1move, p2move);
    if (ans ==0) ties++;
    if (ans ==1) p1wins++;
    if (ans ==2) p2wins++;
  }
  printResults(ties, p1wins, p2wins);
  return 0;
}
