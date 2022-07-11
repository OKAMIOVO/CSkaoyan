/**
 * @file seq_2-2_7.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 * @version 0.1
 * @date 2022-07-11 20:13:58
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define InitSize 10

//算法思想：首先，按顺序不断取下两个顺序表表头较小的结点存入新的顺序表中。然后，看那个表
//还有剩余，将剩下的部分加到新的顺序表后面。

typedef struct {
    int* data;
    int MaxSize;
    int length;
} SqList;

void InitList(SqList& L) {
    L.data = (int*)malloc(2 * InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize * 2;
}

bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > InitSize) //判断i的值的有效范围
        return false;
    if (L.length >= InitSize) //当前存储空间已满，不能放入
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;

    return true;
}

bool Merge(SqList A, SqList B, SqList& C) {
    // 将有序顺序表A与B合并为一个新的有序顺序表C
    if (A.length + B.length > C.MaxSize) //大于顺序表的最大长度
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) { //循环，两两比较，小者存入结果表
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length) //还剩一个没有比较完的顺序表
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

int main() {
    SqList A, B, C;
    InitList(A);
    InitList(B);
    InitList(C);

    bool j;
    for (int i = 1; i <= InitSize; i++) {
        j = ListInsert(A, i, i);
        if (j == 0) {
            printf("lose!!!\n");
        }
    }

    bool t;
    int k = 2;
    for (int i = 1; i <= InitSize; i++) {
        j = ListInsert(B, i, k);
        if (t == 0) {
            printf("lose!!!\n");
        }
        k *= 2;
    }

    Merge(A, B, C);

    for (int i = 0; i < C.MaxSize; i++)
        printf("C.data[%d]=%d\n", i, C.data[i]);

    return 0;
}