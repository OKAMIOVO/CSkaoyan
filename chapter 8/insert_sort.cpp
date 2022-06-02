/**
 * @file insert_sort.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 直接插入排序
 * @version 0.1
 * @date 2022-05-31 20:12:06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 直接插入排序（带哨兵）
void InsertSort(int A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) //依次将A[2]~A[n]插入到前面已排序序列
        if (A[i] < A[i - 1]) { //若A[i]关键码小于其前驱，将A[i]插入有序表
            A[0] = A[i]; //复制为哨兵，A[0]不存放元素
            for (j = i - 1; A[0] < A[j]; --j) //从后往前查找待插入位置
                A[j + 1] = A[j];              //向后挪位
            A[j + 1] = A[0];                  //复制到插入位置
        }
}

int main() {
    int A[] = {-1, 10, 3, 25, 9, 47, 1, 5, 69, 25};
    InsertSort(A, 9);
    for (int i = 1; i <= 9; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}

/*
时间复杂度为O(n^2)
 */