#include <stdio.h>


void function_scope_function(int function_scope) {
    //方法内部有效
    printf("function_1:%d\n", function_scope);
}

//全局变量 可以被引用的文件使用
int file_scope = 1;
//单个文件内有效
int file_static_scope = 1;

void file_scope_function() {
    printf("function_2:%d\n", file_scope);
}

int main() {
    //代码块内有效
    int code_block_scope = 2;
    printf("function scope:%d\n", code_block_scope);

    function_scope_function(3);
    file_scope_function();
}

