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

void memory() {
    //malloc double
    double *PI = malloc(sizeof(double));
    if (PI == NULL) {
        printf("malloc failed\n");
        return;
    }
    *PI = 3.1415926;
    printf("double address:%p\n", PI);
    printf("double   value:%f\n", *PI);

    //address + 8
    printf("double point:%p\n", PI + 1);
    printf("double value:%d\n", *(PI + 1));
    //free
    free(PI);
    PI = NULL;
    printf("after free double address:%p\n", PI);

    //int
    int *age = malloc(sizeof(int));
    printf("int point:%p\n", age);
    printf("int value:%d\n", *age);

    //address+4
    printf("int point:%p\n", age + 1);
    printf("int value:%d\n", *(age + 1));

    free(age);
    age = NULL;
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


void memoryVariable() {
    char cval[] = "hello";
    int i;
    int ival[] = {1, 2, 3, 4};
    int arr_val[][2] = {{1, 2},
                        {3, 4}};
    const char *pconst = "hello";
    char *p;
    int *pi;
    int *pa;
    int **par;

    p = cval;
    p++;              //addr增加1
    pi = ival;
    pi += 1;          //addr增加4
    pa = arr_val[0];
    pa += 1;          //addr增加4
    par = (int **) arr_val;
    par++;           //addr增加8
    for (i = 0; i < sizeof(cval); i++) {
        printf("%d ", cval[i]);
    }
    printf("\n");
    printf("pconst:%s\n", pconst);
    printf("addr:%p, %p\n", cval, p);
    printf("addr:%p, %p\n", ival, pi);
    printf("addr:%p, %p\n", arr_val, pa);
    printf("addr:%p, %p\n", arr_val, par);
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
    sum sumFunc = &add;
    int sum = sumFunc(1, 2);
    printf("sum:%d\n", sum);

    char name[] = "ZS";
    printf("string: %s\n", name);
    printf("string: %llu\n", strlen(name));

    //run struct
    testStruct();


    //test resort
    int failCount = testResort(1000);
    printf("failed count:%d\n", failCount);

    //test uint32
    uint32_t *uint23Point = (uint32_t *) -1;
    printf("%p\n", uint23Point);


    //memory
    memory();
    memoryVariable();

    //enum
    testEnum();
}
