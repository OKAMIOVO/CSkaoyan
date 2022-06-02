/**
 * @file bubble_sort.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 冒泡排序
 * @version 0.1
 * @date 2022-06-01 20:37:16
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

/**
 * @brief 冒泡排序
 * 从后往前（或从前往后）两两比较相邻元素的值，若为逆序（即A[i-1]>A[i]），则交换他们，直到
 * 序列比较完。称这样过程为“一趟”冒泡排序。总共进行n-1趟冒泡。
 * 稳定算法，适用于顺序表和链表
 * 时间复杂度：最坏O(n^2),平均O(n^2),最好O(n)
 * @param A 待排序列
 * @param n 长度
 */
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag =
            false; //表示本趟排序是否发生交换的标志；若某趟排序没有发生“交换”，说明此时已经整体有序
        for (int j = n - 1; j > i; j--) //一趟冒泡过程
            if (A[j - 1] > A[j]) {      //若为逆序
                swap(&A[j - 1], &A[j]); //交换
                flag = true;
            }
        if (flag == false) {
            return; //本趟遍历后没有发生交换，说明表已经有序
        }
    }
}

int main() {
    int A[] = {100, 10, 3, 25, 9, 47, 1, 5, 69, 25};
    BubbleSort(A, 10);
    for (int i = 0; i < 10; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}