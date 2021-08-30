#include <stdio.h>

#ifdef FPF_C_STRUCT_MATH_H

#include "struct_math.h"

#else

#include "struct_math_copy.h"

#endif


int main() {
    struct struct_math structMath;
    printf("%p\n", &structMath);
    //标准
    //设置为 1 表示遵循C标准
    printf("__STDC__ :\t%d\n", __STDC__);
    //本机环境设置为 1， 否则设置为 0
    printf("__STDC_HOSTED__:\t%d\n", __STDC_HOSTED__);
    //C99标准设置为 199901L c11标准设置为201112L
    printf("__STDC_VERSION__:\t%ld\n", __STDC_VERSION__);
    //日期 时间
    printf("__DATE__:\t%s\n", __DATE__);
    printf("__TIMESTAMP__:\t%s\n", __TIMESTAMP__);
    printf("__TIME__:\t%s\n", __TIME__);
    //文件
    printf("__FILE__:\t%s\n", __FILE__);
    //函数名
    printf("__func__:\t%s\n", __func__);
    //行号
    printf("__LINE__:\t%d\n", __LINE__);
    //重置行号
#line 1000
    printf("__LINE__:\t%d\n", __LINE__);
    //重置行号和文件名
#line 2000 "a.c"
    printf("__FILE__:\t%s\n", __FILE__);
    printf("__LINE__:\t%d\n", __LINE__);

    //error 指令
#if __STDC_VERSION__ != 201112L
#error NOT C11
#endif
}
