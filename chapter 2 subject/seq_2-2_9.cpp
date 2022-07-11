/**
 * @file seq_2-2_9.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 9.线性表(a1,a2,a3,..,an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
 * 完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
 * @version 0.1
 * @date 2022-07-11 22:03:45
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 算法思想：顺序存储的线性表递增有序，可以顺序查找，也可以折半查找。
// 题目要求“用最少的时间在表中查找数值为x的元素”，这里应该使用折半查找发。

void SearchExchangeInsert(int A[], int x) {
    int n = 10;
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2; //取中间位置
        if (A[mid] == x)
            break; //查找成功则返回所在位置
        else if (A[mid] > x)
            high = mid - 1; //从前半部分开始查找
        else
            low = mid + 1; //从后半部分开始查找
    }

    // 下面两个if语句只会执行一个
    if (A[mid] == x &&
        mid != n - 1) { //若最后一个元素与x相等，则不存在与其后继交换的操作
        int t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (low > high) {
        int i;
        for (i = n - 1; i > high; i--) //查找失败，插入数据元素x
            A[i + 1] = A[i];           //后移元素
        A[i + 1] = x;                  //插入x
    }
    /* for (int i = 0; i < 10; i++)
        printf("A[%d]=%d\n", i, A[i]); */
}

int main() {
    int A[11] = {2, 5, 98, 17, 52, 63, 54, 55, 19, 63};

    SearchExchangeInsert(A, 7);
    for (int i = 0; i < 10; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}