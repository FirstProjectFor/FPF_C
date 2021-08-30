#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//在assert.h 之前,关闭代码里面的断言
#define NDEBUG

#include <assert.h>

int compare(const void *a, const void *b);

int compare(const void *a, const void *b) {
    const int *a_pointer = (const int *) a;
    const int *b_pointer = (const int *) b;
    if (*a_pointer > *b_pointer) {
        return 1;
    } else if (*a_pointer < *b_pointer) {
        return -1;
    }
    return 0;
}

struct names {
    char first[40];
    char last[40];
};

struct names staff[400];

int compare_names(const void *a, const void *b);

int compare_names(const void *a, const void *b) {
    const struct names *a_pointer = (const struct names *) a;
    const struct names *b_pointer = (const struct names *) b;
    int cmp_result;
    if ((cmp_result = strcmp(a_pointer->last, b_pointer->last)) != 0) {
        return cmp_result;
    } else {
        return strcmp(a_pointer->first, b_pointer->first);
    }
}


int main() {
    assert(1 != 1);
    //sort int
    int length = 7;
    int data[] = {1, 9, 7, 2, 6, 5, 7};
    int data_copy[7];
    //copy data
    memcpy(data_copy, data, sizeof(int) * 7);
    qsort(data_copy, length, sizeof(int), compare);

    for (int i = 0; i < length; ++i) {
        printf("%d ", data_copy[i]);
    }
    printf("\n");

    //sort struct
    length = 400;
    for (int i = 0; i < length; ++i) {
        struct names temp;
        itoa(i, temp.first, 10);
        itoa(i, temp.last, 10);
        strcat(temp.first, ":first");
        strcat(temp.last, ":last");
        staff[i] = temp;
    }
    qsort(staff, 400, sizeof(struct names), compare_names);
    for (int i = 0; i < length; ++i) {
        printf("%s:%s\n", staff[i].last, staff[i].first);
    }
    printf("\n");
}