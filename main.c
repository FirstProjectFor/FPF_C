#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>

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


//encrypt data
void encrypt(long offset, int size, char (*data)[]) {
    int resortIndex[size];
};

int nextRandom(int prev) {
    if (prev == 0) {
        srand((unsigned) time(NULL));
    } else {
        srand(prev);
    }
    int randNum = rand();
    return randNum;
}

//resetIndex
void reSortIndex(int size, int resortIndex[]) {
    int prevRandom = 0;
    char getTag[size];
    for (int i = 0; i < size; i = i + 1) {
        int index = nextRandom(prevRandom) % size;
        //get next index
        if (getTag[index] == 1) {
            int left, right = index;
            do {
                if (right > 0) {
                    right = right - 1;
                }
                if (getTag[right] != 1) {
                    index = right;
                    break;
                }
                if (left < size) {
                    left = left + 1;
                }
                if (getTag[left] != 1) {
                    index = left;
                    break;
                }
            } while (1);
        }
        getTag[index] = 1;
        resortIndex[i] = index;
    }
}

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

    //rand
    int i;
    int prev = 0;
    for (i = 0; i < 10; i++) {
        if (prev == 0) {
            srand((unsigned) time(NULL));
        } else {
            srand(prev);
        }
        int randNum = rand();
        prev = randNum;
        printf("%d\n", randNum);
    };

    //test reSortIndex

    int data[5] = {1, 2, 3, 4, 5};
    reSortIndex(5, data);
    for (int j = 0; j < 5; ++j) {
        printf("%d\n", data[j]);
    }
}
