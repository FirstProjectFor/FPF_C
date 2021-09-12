#include <stdio.h>

int main() {
    int number = 10;
    int *numberPointer = &number;
    int **numberPointerPointer = &numberPointer;

    printf("number:%d\n", number);
    printf("numberPointer:%p\n", numberPointer);
    printf("numberPointerPointer:%p\n", numberPointerPointer);
}
