#include <stdio.h>
#include <string.h>

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


int main(int argc, char *args[]) {
    //run struct
    testStruct();
}
