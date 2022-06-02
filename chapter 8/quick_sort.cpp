/**
 * @file quick_sort.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 快速排序
 * @version 0.1
 * @date 2022-06-02 19:23:47
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[], int low, int high) {
    int pivot = A[low];  //第一个元素作为枢轴
    while (low < high) { //用low,high搜索枢轴的最终位置
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; //比枢轴小的元素移动到左边
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; //比枢轴大的元素移动到右边
    }
    A[low] = pivot; //枢轴元素存放的最终位置
    return low;     //返回存放枢轴的最终位置
}

// 快速排序
void QuickSort(int A[], int low, int high) {
    if (low < high) {                           //递归跳出的条件
        int pivotpos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotpos - 1);        //划分左子表
        QuickSort(A, pivotpos + 1, high);       //划分右子表
    }
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    QuickSort(A, 0, 7);
    for (int i = 0; i <= 7; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}

/* 
算法表现主要取决于递归深度，若每次“划分“越均匀，则递归深度越低。
”划分“越不均匀，递归深度越深

空间复杂度：最好O(n);最坏O(log n)
时间复杂度：最好O(n*n);最坏O(n*log n);平均O(n*log n)

不稳定
 */