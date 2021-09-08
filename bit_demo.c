#include <stdio.h>

struct {
    unsigned int first: 1;
    unsigned int second: 1;
    unsigned int third: 1;
    unsigned int fourth: 1;
} ptr;

int main() {
    ptr.fourth = 0;
    ptr.third = 0;
    ptr.second = 1;
    ptr.first = 1;

    printf("%d", ptr);
}
