#include "stdio.h"
#include "string.h"

int hello(void);

int main(void) {
    char dogs[100];
    scanf("%s", dogs);
    printf("%s\n", dogs);
    printf("%d\n", (int) strlen(dogs));
    hello();
    getchar();
    getchar();
    return 0;
}


int hello() {
    printf("hello\n");
    return 0;
}