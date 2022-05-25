/**
 * @file Binary_search.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 二分查找
 * @version 0.1
 * @date 2022-05-24 21:27:30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define InitSize 100

typedef struct {  //查找表的数据结构(顺序表)
    int* elem;    //动态数组基址
    int TableLen; //表的长度
} SSTable;

//表的初始化
SSTable* InitList(SSTable* L) {
    L->elem = (int*)malloc(InitSize * sizeof(int));
    if (L->elem == NULL) {
        printf("内存分配失败！\n");
        return false;
    }
    L->TableLen = 0;
    return L;
}

//插入元素
bool SSTableInsert(SSTable* L, int i, int e) {
    if (i < 1 || i > InitSize) //判断i的值的有效范围
        return false;
    if (L->TableLen >= InitSize) //当前存储空间已满，不能放入
        return false;
    for (int j = L->TableLen; j >= i; j--)
        (L->elem)[j] = (L->elem)[j - 1];
    (L->elem)[i - 1] = e;
    L->TableLen++;

    printf("插入成功！\n");
    return true;
}

// 折半查找
int Binary_search(SSTable L, int key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2; //取中间位置
        if (L.elem[mid] == key)
            return mid; //查找成功则返回所在位置
        else if (L.elem[mid] > key)
            high = mid - 1; //从前半部分开始查找
        else
            low = mid + 1; //从后半部分开始查找
    }
    return -1; //查找失败，返回-1
}

int main() {
    SSTable L;
    SSTable* T = InitList(&L);
    SSTableInsert(T, 1, 10);
    SSTableInsert(T, 2, 17);
    SSTableInsert(T, 3, 18);
    SSTableInsert(T, 4, 20);
    SSTableInsert(T, 5, 32);
    SSTableInsert(T, 6, 35);
    SSTableInsert(T, 7, 36);
    SSTableInsert(T, 8, 40);
    SSTableInsert(T, 9, 55);
    SSTableInsert(T, 10, 67);
    SSTableInsert(T, 11, 82);
    SSTableInsert(T, 12, 100);
    SSTableInsert(T, 13, 187);
    SSTableInsert(T, 14, 234);

    for (int j = 0; j <= T->TableLen; j++)
        printf("%d\n", (T->elem)[j]);

    if ((Binary_search(*T, 20)) != -1) {
        printf("查找成功，元素下标为%d\n", Binary_search(*T, 20));
    } else {
        printf("查找失败!\n");
    }

    return 0;
}