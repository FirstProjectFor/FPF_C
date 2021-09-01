# include <stdio.h>

#define SIZE 100

void initArray(int *data, int length, int value);

int main() {
    int data[SIZE];
    int length = sizeof(data) / sizeof(data[0]);
    initArray(data, length, 0);
    printf("data[0]:%d\n", data[0]);
    printf("data[1]:%d\n", data[1]);
    printf("data[2]:%d\n", data[2]);
    printf("data[99]:%d\n", data[99]);

    for (int i = 0; i < SIZE; ++i) {
        printf("%d: %d, %d\n", i, data[i], *(data + i));
    }

    //two
    int two[3][5];

    //60
    printf("%lld\n", sizeof(two));
    //000000000061FC40
    printf("%p\n", &two);
    //000000000061FC7C = 000000000061FC40+60
    printf("%p\n", &two + 1);
    //20
    printf("%lld\n", sizeof(two[0]));
    //000000000061FC40
    printf("%p\n", &two[0]);
    //000000000061FC54
    printf("%p\n", &two[1]);
    //000000000061FC68
    printf("%p\n", &two[2]);

    //000000000061FC40
    printf("%p\n", &two[0][0]);
    //000000000061FC44
    printf("%p\n", &two[0][0] + 1);
}

void initArray(int *data, int length, int value) {
    for (int i = 0; i < length; ++i) {
        data[i] = value;
    }
}
