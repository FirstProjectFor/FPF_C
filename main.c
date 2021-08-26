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
    char hello[] = "hello";
    int i;
    int ival[] = {1, 2, 3, 4};
    int arr_val[][2] = {{1, 2},
                        {3, 4}};
    const char *pconst = "hello";
    char *p;
    int *pi;
    int *pa;
    int **par;

    p = hello;
    p++;              //addr增加1
    pi = ival;
    pi += 1;          //addr增加4
    pa = arr_val[0];
    pa += 1;          //addr增加4
    par = (int **) arr_val;
    par++;           //addr增加8
    for (i = 0; i < sizeof(hello); i++) {
        printf("%d ", hello[i]);
    }
    printf("\n");
    printf("pconst:%s\n", pconst);
    printf("addr:%p, %p\n", hello, p);
    printf("addr:%p, %p\n", ival, pi);
    printf("addr:%p, %p\n", arr_val, pa);
    printf("addr:%p, %p\n", arr_val, par);
}


typedef struct CodecItem {
    char *key;
    char *value;
} CodecItem1;


uint32_t readInt(const char *data, int start) {
    uint32_t first = (uint32_t) data[start];
    uint32_t second = (uint32_t) data[start + 1] << 8;
    uint32_t third = (uint32_t) data[start + 2] << 16;
    i fourth = (uint32_t) data[start + 3] << 24;
    return first + second + third + fourth;
}

void writeInt(char *data, int start, uint32_t value) {
    data[start] = (char) value;
    data[start + 1] = (char) (value >> 8);
    data[start + 2] = (char) (value >> 16);
    data[start + 3] = (char) (value >> 24);
}


void unmarshal(char data[], int start, uint32_t rowCount, CodecItem1 result[]) {
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        start = start + 4;
        uint32_t keyLength = readInt(data, start);
        start = start + 4;
        CodecItem1 row;
        char *key = malloc(keyLength + 1);
        key[keyLength] = '\0';
        memset(key, 0, keyLength);
        for (int keyIndex = 0; keyIndex < keyLength; ++keyIndex) {
            key[keyIndex] = data[start];
            start++;
        }
        row.key = key;
        start = start + 4;
        uint32_t valueLength = readInt(data, start);
        start = start + 4;
        char *value = malloc(valueLength);
        memset(value, 0, valueLength);
        value[valueLength] = '\0';
        for (int valueIndex = 0; valueIndex < valueLength; ++valueIndex) {
            value[valueIndex] = data[start];
            start++;
        }
        row.value = value;
        result[rowIndex] = row;
    }
}

void marshal(char *result, uint32_t rowCount, CodecItem1 data[]) {
    int start = 0;
    writeInt(result, start, rowCount);
    start = start + 4;
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        uint32_t keyLength = (uint32_t) strlen(data[rowIndex].key);
        writeInt(result, start, keyLength);
        start = start + 4;
        for (int keyIndex = 0; keyIndex < keyLength; ++keyIndex) {
            result[start] = data[rowIndex].key[keyIndex];
            start = start + 1;
        }
        data[rowIndex].key;
        uint32_t valueLength = (uint32_t) strlen(data[rowIndex].value);
        writeInt(result, start, valueLength);
        start = start + 4;
        for (int valueIndex = 0; valueIndex < valueLength; ++valueIndex) {
            result[start] = data[rowIndex].value[valueIndex];
            start = start + 1;
        }
    }
}

void hexToChar(char *hex, int length, char *result) {
    for (int hexIndex = 0; hexIndex < length; hexIndex = hexIndex + 2) {
        char temp;
        temp = (char) hex[hexIndex];
        temp = temp + (char) hex[hexIndex + 1];
//        result[hexIndex / 2] =;
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
    sum sumFunc = add;
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

    char bbb[] = {18, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0, 98, 100, 99, 100, 121, 104, 1, 0, 0, 0, 28, 0, 0, 0, 49, 49, 48,
                  49, 48, 53, 48, 49, 50, 48, 48, 49, 71, 66, 48, 48, 51, 49, 52, 70, 48, 48, 48, 51, 48, 48, 53, 53, 1,
                  0, 0, 0, 15, 0, 0, 0, 99, 97, 110, 99, 101, 108, 114, 105, 103, 104, 116, 100, 97, 116, 101, 1, 0, 0,
                  0, 0, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0, 99, 101, 114, 116, 110, 111, 1, 0, 0, 0, 36, 0, 0, 0, 228, 186,
                  172, 229, 164, 174, 40, 50, 48, 50, 48, 41, 229, 184, 130, 228, 184, 141, 230, 135, 130, 228, 186,
                  167, 230, 157, 131, 231, 172, 172, 48, 48, 48, 48, 48, 52, 1, 0, 0, 0, 15, 0, 0, 0, 99, 114, 101, 97,
                  116, 101, 114, 105, 103, 104, 116, 100, 97, 116, 101, 1, 0, 0, 0, 9, 0, 0, 0, 50, 48, 50, 49, 47,
                  54, 47, 50, 52, 1, 0, 0, 0, 4, 0, 0, 0, 102, 119, 120, 122, 1, 0, 0, 0, 9, 0, 0, 0, 229, 149, 134,
                  229, 147, 129, 230, 136, 191, 1, 0, 0, 0, 4, 0, 0, 0, 103, 104, 121, 116, 1, 0, 0, 0, 6, 0, 0, 0, 228,
                  189, 143, 229, 174, 133, 1, 0, 0, 0, 2, 0, 0, 0, 105, 100, 1, 0, 0, 0, 1, 0, 0, 0, 53, 1, 0, 0, 0, 10,
                  0, 0, 0, 105, 115, 95, 100, 105, 115, 115, 101, 110, 116, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 15, 0,
                  0, 0, 105, 115, 95, 109, 111, 114, 116, 102, 111, 114, 101, 99, 97, 115, 116, 1, 0, 0, 0, 1, 0, 0, 0,
                  48, 1, 0, 0, 0, 11, 0, 0, 0, 105, 115, 95, 109, 111, 114, 116, 103, 97, 103, 101, 1, 0, 0, 0, 1, 0, 0,
                  0, 48, 1, 0, 0, 0, 11, 0, 0, 0, 105, 115, 95, 114, 101, 115, 116, 114, 105, 99, 116, 1, 0, 0, 0, 0, 0,
                  0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 105, 115, 118, 97, 108, 105, 100, 1, 0, 0, 0, 1, 0, 0, 0, 49, 1, 0, 0,
                  0, 4, 0, 0, 0, 106, 122, 109, 106, 1, 0, 0, 0, 7, 0, 0, 0, 50, 50, 56, 48, 46, 54, 49, 1, 0, 0, 0, 3,
                  0, 0, 0, 113, 108, 114, 1, 0, 0, 0, 9, 0, 0, 0, 229, 173, 153, 233, 163, 158, 233, 190, 153, 1, 0, 0,
                  0, 6, 0, 0, 0, 113, 108, 114, 122, 106, 104, 1, 0, 0, 0, 18, 0, 0, 0, 49, 49, 48, 48, 48, 48, 48, 48,
                  48, 48, 48, 48, 48, 48, 48, 49, 51, 49, 1, 0, 0, 0, 7, 0, 0, 0, 113, 108, 114, 122, 106, 108, 120, 1,
                  0, 0, 0, 9, 0, 0, 0, 232, 186, 171, 228, 187, 189, 232, 175, 129, 1, 0, 0, 0, 5, 0, 0, 0, 114, 97,
                  116, 105, 111, 1, 0, 0, 0, 3, 0, 0, 0, 49, 48, 48, 1, 0, 0, 0, 2, 0, 0, 0, 122, 108, 1, 0, 0, 0, 27,
                  0, 0, 0, 229, 140, 151, 228, 186, 172, 232, 191, 144, 230, 178, 179, 229, 178, 184, 228, 184, 138,
                  231, 154, 1, 32, 233, 153, 162, 229, 173, 144};

    CodecItem1 c1;
    int start = 0;
    int rowCount = readInt(bbb, start);
    printf("read data row count: %d\n", rowCount);
    start = start + 4;
    CodecItem1 result1[rowCount];
    unmarshal(bbb, start, rowCount, result1);
    printf("unmarshal: %p\n", result1);
    printf("unmarshal: %s\n", result1[0].key);
    printf("unmarshal: %s\n", result1[0].value);
    printf("unmarshal: %s\n", result1[1].key);
    printf("unmarshal: %s\n", result1[1].value);
}
