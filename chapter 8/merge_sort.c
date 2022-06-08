/**
 * @file merge_sort.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 归并排序
 * @version 0.1
 * @date 2022-06-07 20:49:09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// A[low...mid]和A[mid...high]各自有序，将两个部分归并
void Merge(int A[], int B[], int low, int mid, int high) {
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //将A中所有元素复制到B中
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (B[i] <= B[j]) //两个元素相等时，优先使用靠前的那个（稳定性）
            A[k] = B[i++]; //将较小值复制到A中
        else
            A[k] = B[j++];
    }
    while (i <= mid)
        A[k++] = B[i++]; //没有归并完的部分复制到尾部
    while (j <= mid)
        A[k++] = B[j++]; //没有归并完的部分复制到尾部
}

void MergeS(int A[], int B[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;  //从中间划分
        MergeS(A, B, low, mid);      //对左半部分归并排序
        MergeS(A, B, mid + 1, high); //对右半部分归并排序
        Merge(A, B, low, mid, high); //归并
    }
}

void MergeSort(int A[], int len) {
    int* B = (int*)malloc(len * sizeof(int)); //辅助数组
    MergeS(A, B, 0, len - 1);
    free(B);
}

int main() {
    int A[] = {12, 3, 21, 32, 1, 34, 12, 35, 34};

    int len = sizeof(A) / sizeof(A[0]);
    MergeSort(A, len);

    for (int i = 0; i < len; i++) {
        printf("A[%d]=%d\n", i, A[i]);
    }

    return 0;
}