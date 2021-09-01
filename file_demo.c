# include <stdio.h>

int main() {
    printf("Hello C!\n");

    //w 写 r 读  a 追加
    FILE *data_file = fopen("./data.txt", "a");
    fprintf(data_file, "%d", 1);
    fclose(data_file);
    return 0;
    return 0;
}