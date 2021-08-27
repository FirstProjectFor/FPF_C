#include <stdio.h>
#include <string.h>

struct person {
    char name[50];
    char address[200];
    int age;
};

int main() {
    struct person p1;
    strcpy(p1.name, "zs");
    strcpy(p1.address, "bj");
    p1.age = 20;

    printf("%s\n", p1.name);
    printf("%s\n", p1.address);
    printf("%d\n", p1.age);

    struct person *p2 = &p1;

    strcpy(p2->name, "ls");
    strcpy(p2->address, "tj");
    p2->age = 21;

    printf("pointer:%s\n", p2->name);
    printf("pointer:%s\n", p2->address);
    printf("pointer:%d\n", p2->age);
    return 0;
}