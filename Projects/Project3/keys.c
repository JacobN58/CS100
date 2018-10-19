#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  char str[100];
  int keyStroke=0, strCount=0, charCount=0, a, right, left;
  int rHand=0, rIndex=0, rMiddle=0, rRing=0, rPinky=0;
  int lHand=0, lIndex=0, lMiddle=0, lRing=0, lPinky=0;

  printf("Enter some text, ending with <control-d> : ");
  scanf("%s", str);

  while (! feof(stdin)) {
    int len = strlen(str);
    for (int a = 0; a < len; a++) {
      char ch = str[a];
      if (islower(ch)) {
        charCount++;
      }
      if (isupper(ch)) {
        charCount++;
      }
      if (isspace(ch)) {
        strCount++;
      }
      if (ispunct(ch)) {
        charCount++;
      }
      if (ch =='\\') {
        charCount++;
      }

      if (ch == 'y'||ch == 'u'||ch == 'h'||ch == 'j'||ch == 'n'||ch == 'm')
        rIndex++, right++;
      if (ch == '6'||ch == '7')
        rIndex++;
        if (ch == '^'||ch == '&'||ch == 'Y'||ch == 'U'||ch == 'H'||ch == 'J'||ch == 'N'||ch == 'M'){
          rIndex++; lPinky++;
        }
      if (ch == 'r'||ch == 't'||ch == 'f'||ch == 'g'||ch == 'v'||ch == 'b')
        lIndex++, left++;
      if (ch == '4'||ch == '5')
        lIndex++;
        if (ch == '$'||ch == '%'||ch == 'R'||ch == 'T'||ch == 'F'||ch == 'G'||ch == 'V'||ch == 'B'){
          lIndex++; rPinky++;
        }
      if (ch == 'i'||ch == 'k')
        rMiddle++, right++;
      if (ch == '8'||ch == ',')
        rMiddle++;
        if (ch == '*'||ch == 'I'||ch == 'K'||ch == '<'){
          rMiddle++; lPinky++;
        }
      if (ch == 'e'||ch == 'd'||ch == 'c')
        lMiddle++, left++;
      if (ch == '3')
        lMiddle++;
        if (ch == '#'||ch == 'E'||ch == 'D'||ch == 'C'){
          lMiddle++; rPinky++;
        }
      if (ch == 'o'||ch == 'l')
        rRing++, right++;
      if (ch == '9'||ch == '.')
        rRing++;
        if (ch == '('||ch == 'O'||ch == 'L'||ch == '>'){
          rRing++; lPinky++;
        }
      if (ch == 'w'||ch == 's'||ch == 'x')
        lRing++, left++;
      if (ch == '2')
        lRing++;
        if (ch == '@'||ch == 'W'||ch == 'S'||ch == 'X'){
          lRing++; rPinky++;
        }
      if (ch == '0'||ch == '-'||ch == '='||ch == '\\'||ch == ']'||ch == '['||ch == ';'||ch == '\''||ch == '/')
        rPinky++;
      if (ch == 'p')
        rPinky++, right++;
        if (ch == ')'||ch == 'P'||ch == ':'||ch == '/'||ch == '_'||ch == '{'||ch == '}'||ch == '"'||ch == '?'||ch == '|'||ch == '+'){
          rPinky++; lPinky++;
        }
      if (ch == 'q'||ch == 'a'||ch == 'z')
        lPinky++, left++;
      if (ch == '`'||ch == '1')
        lPinky++;
        if (ch == '~'||ch == '!'||ch == 'Q'||ch == 'A'||ch == 'Z'){
          lPinky++; rPinky++;
        }

    }
    if (right>0 && left==0)
          rHand++;
    if (left>0 && right==0)
          lHand++;
    if (len = (lIndex + lMiddle + lRing + lPinky))
      strCount++;
right=0; left=0;
    scanf("%s", str);
  }
keyStroke = rIndex + rMiddle + rRing + rPinky + lIndex + lMiddle + lRing + lPinky;
  printf("%d strings entered, %d total character\n", strCount, charCount);
  printf("\t %d typed using only the left hand\n", lHand);
  printf("\t %d typed using only the right hand\n", rHand);
  printf("%d total keystrokes\n", keyStroke);
  printf("\t %d - Left index\n", lIndex);
  printf("\t %d - Left middle\n", lMiddle);
  printf("\t %d - Left ring\n", lRing);
  printf("\t %d - Left pinky\n", lPinky);
  printf("\t %d - Right index\n", rIndex);
  printf("\t %d - Right middle\n", rMiddle);
  printf("\t %d - Right ring\n", rRing);
  printf("\t %d - Right pinky\n", rPinky);

  return 0;
}
