#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void process(){

int c;

int leftHand = 0, rightHand = 0, leftIndex = 0, rightIndex = 0, leftPinky = 0, rightPinky = 0,

leftMiddle = 0, rightMiddle = 0, leftRing = 0, rightRing = 0, strings = 1, strokes = 0;

char *leftIndexChars = "45rtfgvb";

char *rightIndexChars = "67yuhjnm";

char *leftMiddleChars = "3edc";

char *rightMiddleChars = "8ijk,<";

char *leftPinkyChars = "~`1!qaz";

//char *rightPinkyChars = "0)|-_+=p{}[]|\:;'\"?/";

char *leftRingChars = "@2wsx";

char *rightRingChars = "9(ol>.";

while(1){

c = getchar(); //reading character as Ascii Int

if(c == EOF){ //checking for ctrl + D

break;

}

if(c > 64 && c < 91){ //checking for capital letters

strokes++; //adding extra stroke for caps

}

strokes++;

if(c == ' '){

strings++; //word ending as space

continue;

}

if(strchr(leftIndexChars, c) != NULL){

leftHand++;

leftIndex++;

}else if(strchr(rightIndexChars, c) != NULL){

rightHand++;

rightIndex++;

}else if(strchr(leftMiddleChars, c) != NULL){

leftHand++;

leftMiddle++;

}else if(strchr(rightMiddleChars, c) != NULL){

rightHand++;

rightMiddle++;

}else if(strchr(leftRingChars, c) != NULL){

leftHand++;

leftRing++;

}else if(strchr(rightRingChars, c) != NULL){

rightHand++;

rightRing++;

}else if(strchr(leftPinkyChars, c) != NULL){

leftHand++;

leftPinky++;

}else if(strchr(rightIndexChars, c) != NULL){

rightHand++;

rightPinky++;

}

}

printf("%d strings entered\n %d typed using only the left hand\n %d typed using only the right hand\n %d total keystrokes\n %d – Left index\n %d – Left middle\n %d – Left ring\n %d – Left pinky\n %d – Right index\n %d – Right middle\n %d – Right ring\n %d – Right pinky",

strings, leftHand, rightHand, strokes,

leftIndex, leftMiddle, leftRing, leftPinky,

rightIndex, rightMiddle, rightRing, rightPinky

);

}

int main(void) {

process();

return EXIT_SUCCESS;

}
