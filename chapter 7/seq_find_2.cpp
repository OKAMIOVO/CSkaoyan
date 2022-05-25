/**
 * @file seq_find_2.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 顺序查找（带哨兵）
 * @version 0.1
 * @date 2022-05-24 21:04:04
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

typedef struct {  //查找表的数据结构（顺序表）
    int* elem;    //动态数组基址
    int Tablelen; //表的长度
} SSTable;

//表的初始化
SSTable* InitList(SSTable* L) {
    L->elem = (int*)malloc(InitSize *sizeof(int));
    if (L->elem == NULL) {
        printf("内存分配失败！\n");
        return false;
    }
    L->Tablelen = 0;
    return L;
}

//插入元素
bool SSTableInsert(SSTable* L, int i, int e) {
    if (i < 1 || i > InitSize) //判断i的值的有效范围
        return false;
    if (L->Tablelen >= InitSize) //当前存储空间已满，不能放入
        return false;
    for (int j = L->Tablelen; j >= i; j--)
        L->elem[j] = L->elem[j - 1];
    L->elem[i] = e;
    L->Tablelen++;

    printf("插入成功！\n");
    return true;
}

//顺序查找
int Search_Seq(SSTable ST, int key) {
    ST.elem[0] = key;
    int i;
    //从后往前找
    for (i = ST.Tablelen;ST.elem[i] != key; --i)
        ;
    //优点：无需判断是否越界，效率更高
    return i;
}

int main() {
    SSTable L;
    SSTable* T = InitList(&L);
    SSTableInsert(T, 1, 55);
    SSTableInsert(T, 2, 21);
    SSTableInsert(T, 3, 50);
    SSTableInsert(T, 4, 36);
    SSTableInsert(T, 5, 520);
    SSTableInsert(T, 6, 57);
    SSTableInsert(T, 7, 25);
    SSTableInsert(T, 8, 15);
    SSTableInsert(T, 9, 28);
    SSTableInsert(T, 10, 16);
    SSTableInsert(T, 11, 99);
    SSTableInsert(T, 12, 100);
    SSTableInsert(T, 13, 87);
    SSTableInsert(T, 14, 34);

    for(int j=1;j<=T->Tablelen;j++)
        printf("%d\n",(T->elem)[j]);

    if ((Search_Seq(*T, 28)) != -1) {
        printf("查找成功，元素下标为%d\n", Search_Seq(*T, 28));
    } else {
        printf("查找失败!\n");
    }

    return 0;
}
