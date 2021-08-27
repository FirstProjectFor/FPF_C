#include <stdio.h>
#include <stdlib.h>

void memory_malloc() {
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
    printf("double address:%p\n", PI + 1);
    printf("double   value:%f\n", *(PI + 1));
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

void memoryVariable() {
    //string
    const char *p_const = "hello";
    printf("p_const:%s\n", p_const);

    //char
    char hello[] = "hello";
    char *char_pointer = hello;
    //address增加1
    char_pointer++;
    printf("char      address:%p, %p\n", hello, char_pointer);

    //int array
    int i_val[] = {1, 2, 3, 4};
    int *int_array_pointer = i_val;
    //address增加4
    int_array_pointer += 1;
    printf("int       address:%p, %p\n", i_val, int_array_pointer);

    //two dimension int array
    int arr_val[][2] = {
            {1, 2},
            {3, 4}
    };
    int **two_dimension_int_array_pointer = (int **) arr_val;
    //address增加8
    two_dimension_int_array_pointer++;
    printf("          address:%p, %p\n", arr_val, two_dimension_int_array_pointer);
}

int main() {
    memory_malloc();
    printf("\n");
    memoryVariable();
    printf("\n");
    return 0;
}