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

int nextRandom(int prev) {
    if (prev == 0) {
        srand((unsigned) time(NULL));
    } else {
        srand(prev);
    }
    return rand();
}

//reSortIndex
void reSortIndex(int size, int *resortIndex) {
    int prevRandom = 0;
    char getTag[size];
    for (int i = 0; i < size; i = i + 1) {
        getTag[i] = 0;
    }
    for (int i = 0; i < size; i = i + 1) {
        prevRandom = nextRandom(prevRandom);
        int nextIndex = prevRandom % size;
        //get next nextIndex
        if (getTag[nextIndex] == 1) {
            int left = nextIndex;
            int right = nextIndex;
            while (1 == 1) {
                if (right < size - 1) {
                    right = right + 1;
                    if (getTag[right] == 0) {
                        nextIndex = right;
                        break;
                    }
                }
                if (left > 0) {
                    left = left - 1;
                    if (getTag[left] == 0) {
                        nextIndex = left;
                        break;
                    }
                }
            };
        }
        getTag[nextIndex] = 1;
        resortIndex[i] = nextIndex;
    }
}

//encrypt data
void encrypt(long offset, int size, char (*data)[]) {
    int resortIndex[size];
    reSortIndex(size, resortIndex);
    //encrypt
};


int check(int size, const int *resortIndex) {
    int errorCount = 0;
    char temp[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        if (temp[resortIndex[i]] == 1) {
            printf("repeat:%d:%d\n", size, resortIndex[i]);
        }
        temp[resortIndex[i]] = 1;
    }

    for (int i = 0; i < size; ++i) {
        if (temp[i] != 1) {
            errorCount++;
            printf("size:%d,index:%d,actual index: %d\n", size, i, resortIndex[i]);
        }
    }
    if (errorCount > 0) {
        return 0;
    }
    return 1;
}

int testResort(int times) {
    int errorCount = 0;
    for (int i = 0; i < times; ++i) {
        //test reSortIndex
        int count = i;
        int indexArr[count];
        for (int j = 0; j < count; ++j) {
            indexArr[j] = j;
        }
        reSortIndex(count, indexArr);

        int checkResult = check(count, indexArr);
        if (checkResult == 0) {
            errorCount++;
            printf("reSortIndex failed\n");
        }
    }
    return errorCount;
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

    int failCount = testResort(10000);
    printf("failed count:%d", failCount);
}
