#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *args[]) {

    char *name = malloc(100 * sizeof(char));

    for (int i = 0; i < strlen(name); ++i) {
        printf("%c\n", name[i]);
    }

    getchar();

    for (int i = 0; i < 1000; ++i) {
        printf("%c\n", name[i]);
    }
}

