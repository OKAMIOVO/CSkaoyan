/**
 * @file file_1.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief C语言文件操作
 * @version 0.1
 * @date 2022-04-29 19:41:49
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
  操作文件的正确流程为：打开文件-->读写文件-->关闭文件。文件在进行读写操作之前要先打开，使用完毕后要关闭。
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
    FILE* fp;
    char str[N + 1];

    //  判断文件是否打开失败
    if ((fp = fopen("CSkaoyan/chapter 1/demo.txt", "rt")) == NULL) {
        puts("打开文件失败！");
        exit(0);
    }

    // 循环读取文件的每一行数据
    while (fgets(str, N, fp) != NULL)
        printf("%s", str);

    // 操作结束后关闭文件
    fclose(fp);

    return 0;
}