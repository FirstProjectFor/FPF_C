#include "header.h"

struct Person {
    char name[50];
    char address[200];
    int age;
};

int testStruct() {

    struct Person p1;
    strcpy(p1.name, "zs");
    strcpy(p1.address, "bj");
    p1.age = 20;

    printf("%s\n", p1.name);
    printf("%s\n", p1.address);
    printf("%d\n", p1.age);
    return 0;
}

int add(int x, int y) {
    return x + y;
};

int main(int argc, char *args[]) {

    printf("Hello World!\n");
    printf("%d\n", argc);
    printf("%s\n", args[0]);
    printf("%llu\n", sizeof(int));
    printf("%llu\n", sizeof(float));
    printf("%f\n", FLT_MIN);
    printf("%f\n", FLT_MAX);
    printf("%llu\n", sizeof(double));
    printf("%f\n", DBL_MIN);
    printf("%f\n", DBL_MAX);

    int a = 0;
    printf("%p\n", &a);

    //func_ptr
    int (*addFunc)(int, int) = &add;
    int sum = addFunc(1, 2);
    printf("%d\n", sum);

    char name[] = "ZS";
    printf("%s\n", name);
    printf("%llu\n", strlen(name));

    //run struct
    testStruct();
}
