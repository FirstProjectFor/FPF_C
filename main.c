#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


typedef enum {
    spring = 1,
    summer,
    autumn,
} season;

typedef uint32_t i;
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

void testEnum() {
    season s1 = spring;
    season s2 = autumn;

    printf("enum: %d\n", s1);
    printf("enum: %d\n", s2);

    s1++;
    printf("enum: %d\n", s1);

    switch (s1) {
        case summer: {
            printf("switch season:summer\n");
            break;
        }
        default: {
            printf("switch season:default\n");
            break;
        }
    }
}

int main(int argc, char *args[]) {
    //run struct
    testStruct();
    //enum
    testEnum();
}
