/**
 * @file select.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 简单选择排序
 * @version 0.1
 * @date 2022-06-02 20:11:30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 交换
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//简单选择排序
void SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {   //一共进行n-1趟
        int min = i;                    //记录最小元素位置
        for (int j = i + 1; j < n; j++) //在A[i...n-1]中选择最小的元素
            if (A[j] < A[min])          //更新最小元素位置
                min = j;
        if (min != i)
            swap(&A[i], &A[min]); //封装的swap()函数共移动元素3次
    }
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    SelectSort(A, 8);
    for (int i = 0; i <= 7; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}

/*
每一趟在待排序元素中选择关键字最小的元素加入有序子序列
必须进行n-1趟处理

空间复杂度O(1)
时间复杂度O(n^2)

不稳定
顺序表、链表都可以
 */