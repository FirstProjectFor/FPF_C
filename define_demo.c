#include "stdio.h"

/**
 * define 定义字面量，就是一个文本
 * 程序会把对应的地方替换成字面量的值。
 * 比如: int x = TWO; 等价于 int x = 2;
 */
#define TWO 2

#define FOUR TWO*TWO
#define PX printf("X is %d\n", x)
#define FMT "X is %d\n"

int main(void) {
    int x = TWO;
    PX;
    x = FOUR;
    printf(FMT, x);
    return 0;
}
