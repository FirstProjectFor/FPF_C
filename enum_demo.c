#include <stdio.h>

typedef enum {
    spring = 1,
    summer,
    autumn,
    winter
} season;

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
        case winter:
            printf("switch season:winter\n");
            break;
        default: {
            printf("switch season:default\n");
            break;
        }
    }
}


int main() {
    testEnum();
    return 0;
}