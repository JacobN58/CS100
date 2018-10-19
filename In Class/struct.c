#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient {
  char *first;
  char *last;
  int cwid;
  char gender;
} PATIENT;

void printPatient(PATIENT *p);
PATIENT *readPatient();

int main(void) {
  PATIENT *p;
  p = readPatient();
  printPatient(*p);

return 0;
}

PATIENT *readPatient() {
  char str[100];
  PATIENT *p;

  p = malloc(sizeof(PATIENT));

  printf("Enter patient information:\n");
  printf("\tFirst name : ");
  scanf("%s", str);
  p->first = malloc(strlen(str) + 1);
  strcpy(p->first, str);

  printf("\tLast name : ");
  scanf("%s", str);
  p->last = malloc(strlen(str) + 1);
  strcpy(p->last, str);

  printf("\tCWID : ");
  scanf("%d", &p->cwid);
  printf("\tGender : ");
  scanf(" %c", &p->gender);

}

void printPatient(PATIENT *p) {
  printf("The patient %s %s, CWID %d, Gender %c\n",
          p->first, p->last, p->cwid, p->gender);
  return;
}
