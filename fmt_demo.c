#include <stdio.h>
#include <float.h>

int main(int argc, char *args[]) {
    printf("Hello World!\n");
    printf("%d\n", argc);
    printf("%s\n", args[0]);
    printf("%d\n", (int) sizeof(int));
    printf("%d\n", (int) sizeof(float));
    printf("%f\n", FLT_MIN);
    printf("%f\n", FLT_MAX);
    printf("%d\n", (int) sizeof(double));
    printf("%f\n", DBL_MIN);
    printf("%f\n", DBL_MAX);
    return 0;
}
