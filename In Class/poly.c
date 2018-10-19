#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct poly {
  double coeff;
  int degree;
  struct poly *next;
} Poly;

Poly *add(Poly *, double, int);
void printPoly(Poly *);
double evaluate(Poly *, int);

int main(void) {
    Poly *head = NULL;
    double x;
    int y, val;
    printf("Enter a term (double coefficient & integer degree) : ");
    scanf("%lf %d", &x, &y);
    while (x != 0 || y!= 0) {
        myPoly = add(myPoly, x, y);
        printf("The polynomial is now : ");
        printPoly(myPoly);
        printf("Enter another term or 0 0 to exit : ");
        scanf("%lf %d", &x, &y);
    }

    printf("\n\n The final polynomial is : ");
    printPoly(myPoly);
    printf("\n\nEnter a value for x : ");
    scanf("%d", &val);
    printf("The value of the polynomial at x=%d is %lf\n", val, evaluate(myPoly, val));

    return 0;
}

void printPoly(Poly *ptr) {
  printf("[");
  while (ptr) {
      if(ptr->degree == 0)
          printf("%lf", ptr->coeff);
      if(ptr->degree == 1)
          printf("%lfx\n", ptr->coeff);
      if(ptr->degree == NULL)
          printf(" + ");
      ptr = ptr->next;
  }
  printf("]\n");
  return;
}

double evaluate(Poly *ptr, int val) {
    double value = 0.0;
    while (ptr) {
        value = value + ptr->coeff * pow(val, ptr->degree);
        ptr = ptr->next;
    }
    return value;
}

Poly *add(Poly *thePoly, double c, int d) {
  //add to the front
  //build new Node
      Poly *newNode = (Poly *) malloc (sizeof(Poly));
      newNode->coeff = c;
      newNode->degree = d;

  //new node points to the original list (everything is behind it)
      newNode->next = thePoly;

  //tell the user that he start of the list is this new Node
      return newNode;
}
