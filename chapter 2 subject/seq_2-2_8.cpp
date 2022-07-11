/**
 * @file seq_2-2_8.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief
 * 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,...,am)和(b1,b2,...,bn)。
 * 试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,...,bn)放在(a1,a2,...,am)的前面。
 * @version 0.1
 * @date 2022-07-11 21:05:44
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// 算法思想：先将数组A[m+n]中的全部元素(a1,a2,...,am,b1,b2,...,bn)原地逆置为(bn,bn-1,...,b1,am,am-1,...,a1)，再对前n个元素和后m个元素分别使用
// 逆置算法，即可得到(b1,b2,...,bn,a1,a2,...,am),从而实现顺序表的位置互换。

typedef int DataType;

void Reverse(DataType A[], int left, int right, int arraySize) {
    // 逆转
    if (left >= right || right >= arraySize)
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++) {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void Exchange(DataType A[], int m, int n, int arraySize) {
    /* 数组A[m+n]中，从0到m-1存放顺序表(a1,a2,...,am)，
    从m到m+n-1存放顺序表(b1,b2,...,bn)，算法将这两个表的位置互换 */
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, m - 1, arraySize);
    Reverse(A, m, m + n - 1, arraySize);
}

int main() {
    int A[20] = {10, 13, 25, 14, 18, 9,  5,  8,  15, 16,
                 11, 63, 36, 54, 25, 78, 14, 85, 98, 56};
    Exchange(A, 10, 10, 20);

    for (int i = 0; i < 20; i++)
        printf("A[%d]=%d\n", i, A[i]);

    return 0;
}
