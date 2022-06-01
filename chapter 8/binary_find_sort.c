/**
 * @file binary_find_sort.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 折半插入排序（直接插入排序优化版）
 * @version 0.1
 * @date 2022-05-31 20:49:51
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 折半插入排序
/*
当low>high时折半查找停止，应该将[low,i-1]内的元素全部右移，并将A[0]复制到low所指位置；
当A[mid]==A[0]时，为了保证算法的“稳定性”，应该继续在mid所指位置右边寻找插入位置
 */
void InsertSort(int A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) { //依次将A[2]~A[n]插入前面的已排序序列
        A[0] = A[i];           //将A[i]暂存到A[0]
        low = 1;
        high = i - 1;               //设置折半查找范围
        while (low <= high) {       //折半查找（默认递增有序）
            mid = (low + high) / 2; //取中间点
            if (A[mid] > A[0])
                high = mid - 1; //查找左半子表
            else
                low = mid + 1; //查找右半子表
        }
        for (j = i - 1; j >= high; --j)
            A[j + 1] = A[j]; //统一后移元素，空出插入位置
        A[high + 1] = A[0];  //插入操作
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
比起”直接插入排序“，比较次数减少，但是移动次数没变，
时间复杂度仍为O(n^2)
 */