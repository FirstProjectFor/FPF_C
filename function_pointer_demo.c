#include <stdio.h>

typedef int (*sum)(int, int);

int add(int x, int y) {
    return x + y;
};

int main() {
    sum func = add;
    int result = func(1, 2);
    printf("sum:%d\n", result);
    return 0;
}

