/**
 * @file shell_sort.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 希尔排序
 * @version 0.1
 * @date 2022-06-01 19:57:28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

/**
 * @brief 希尔排序 将待排序列分割为若干子表，对各个子表进行直接插入排序
 * 缩小增量d，重复上述过程，直到d=1为止
 *
 * @param A 待排序列
 * @param n 待排序列长度
 */
void ShellSort(int A[], int n) {
    int d, i, j; // d为增量
    // A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已找到
    for (d = n / 2; d >= 1; d = d / 2) //步长变化
        for (i = d + 1; i <= n; ++i)
            if (A[i] < A[i - d]) { //需将A[i]插入到有序增量子表
                A[0] = A[i];       //暂存在A[0]
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                    A[j + d] = A[j]; //记录后移查找插入的位置
                A[j + d] = A[0];     //插入
            }
}

int main() {
    int A[] = {-1, 10, 3, 25, 9, 47, 1, 5, 69, 25, 71};
    ShellSort(A, 10);
    for (int i = 1; i <= 10; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}

// 不稳定，只适用于顺序表