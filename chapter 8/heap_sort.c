/**
 * @file heap_sort.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 堆排序
 * @version 0.1
 * @date 2022-06-06 21:21:56
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

// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
    A[0] = A[k];                            // A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) { //沿k较大的子结点向下筛选
        if (i < len && A[i] < A[i + 1])
            i++;
        if (A[0] >= A[i]) //筛选结束
            break;
        else {
            A[k] = A[i]; //将A[i]调整到双亲结点上
            k = i;       //修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0]; //被筛选结点的值放入最终位置
}

// 建立大根堆
void BuildMaxHeap(int A[], int len) {
    for (int i = len / 2; i > 0; i--) //从后往前调整所有非终端结点
        HeadAdjust(A, i, len);
}

// 堆排序的完整逻辑
void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);           //初始建堆
    for (int i = len; i > 1; i--) { // n-1趟交换和建堆过程
        swap(&A[i], &A[1]);         //堆顶元素和堆底元素进行互换
        HeadAdjust(A, 1, i - 1);    //把剩余的待排序元素整理成堆
    }
}

int main() {
    int A[] = {-1, 10, 3, 25, 9, 47, 1, 5, 69, 25};
    HeapSort(A, 9);
    for (int i = 1; i <= 9; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}

/*
空间复杂度：O(1)
时间复杂度：O(n)+O(nlog2n)=O(nlog2n)
不稳定
大根堆排序是递增，小根堆是递减
 */