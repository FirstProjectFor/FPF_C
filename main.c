#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef int (*sum)(int, int);

int add(int x, int y) {
    return x + y;
};

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

int nextRandom(int prev) {
    if (prev == 0) {
        srand((unsigned) time(NULL));
    } else {
        srand(prev);
    }
    return rand();
}

//messIndex
void messIndex(int size, int *resortIndex) {
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
    messIndex(size, resortIndex);
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
        //test messIndex
        int count = i;
        int indexArr[count];
        for (int j = 0; j < count; ++j) {
            indexArr[j] = j;
        }
        messIndex(count, indexArr);

        int checkResult = check(count, indexArr);
        if (checkResult == 0) {
            errorCount++;
        }
    }
    return errorCount;
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

    printf("Hello World!\n");
    printf("%d\n", argc);
    printf("%s\n", args[0]);
    printf("%d\n", (int) sizeof(int));
    printf("%d\n", (int) sizeof(float));
    printf("%f\n", FLT_MIN);
    printf("%f\n", FLT_MAX);
    printf("%d\n", (int) sizeof(double));
    printf("%f\n", DBL_MIN);
    printf("%f\n", DBL_MAX);

    int a = 0;
    printf("%p\n", &a);

    //func_ptr
    sum sumFunc = add;
    int sum = sumFunc(1, 2);
    printf("sum:%d\n", sum);

    char name[] = "ZS";
    printf("string: %s\n", name);
    printf("string length: %d\n", (int) strlen(name));

    //run struct
    testStruct();


    //test resort
    int failCount = testResort(1000);
    printf("failed count:%d\n", failCount);

    //test uint32
    uint32_t *uint23Point = (uint32_t *) -1;
    printf("%p\n", uint23Point);
    //enum
    testEnum();
}
