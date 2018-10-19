#include <stdio.h>
#include <limits.h>

int main(void) {

    int num, max = 0, min = 0;
    printf("Enter five numbers : ");

    for (int a=0; a<5 ; a++){
        scanf("%d", &num);
        if (num < min)
            min = num;
        if (num > max)
            max = num;

    }

    printf("The max is %d\n", max);
    printf("%d-%d\n", max, min);
    return 0;
}
