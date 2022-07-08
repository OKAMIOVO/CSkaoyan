/**
 * @file seq_2-2_1.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值，
 *        空出的位置由最后一个元素填补，若顺序表为空，则显示出错误信息并推出运行。
 * @version 0.1
 * @date 2022-07-08 21:56:35
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
typedef struct {
    int* data;
    int MaxSize;
    int length;
} SqList;

void InitList(SqList &L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

bool ListInsert(SqList &L, int i, int e) {
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

/**
 * @brief 顺序表查找最小元素并记住其位置，删除最小元素后用最后一个元素填补
 *
 * @param L 顺序表
 * @param value 最小元素值
 * @return true
 * @return false
 */
bool Del_Min(SqList &L, int &value) {
    // 删除顺序表L中最小元素结点，并通过引用型参数value返回其值
    // 若删除成功，则返回true；否则返回false
    if (L.length == 0)
        return false; //表空，种植操作返回
    value = L.data[0];
    int pos = 0;                        //假设0号元素的值最小
    for (int i = 1; i < L.length; i++) //循环寻找具有最小值的元素
        if (L.data[i] < value) { //让value记忆当前具有最小值的元素
            value = L.data[i];
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1]; //空出的位置由最后一个元素填补
    L.length--;
    return true;
}

int main() {
    SqList L;
    InitList(L);
    // bool j;
    /* for (int i = 1; i < InitSize; i++) {
        j = ListInsert(L, i, i);
        if (j == 0) {
            printf("lose!!!\n");
        }
    } */
    ListInsert(L, 1, 101);
    ListInsert(L, 2, 110);
    ListInsert(L, 3, 21);
    ListInsert(L, 4, 121);
    ListInsert(L, 5, 136);
    ListInsert(L, 6, 13);
    ListInsert(L, 7, 19);
    ListInsert(L, 8, 71);
    ListInsert(L, 9, 61);
    ListInsert(L, 10, 31);

    int value = 0;
    int x = Del_Min(L, value);
    if (x == true)
        printf("删除成功，删除元素值为%d\n", value);
    else
        printf("删除失败！\n");
    
    for(int i = 0; i < L.length; i++)
        printf("dara[%d] = %d\n",i,L.data[i]);

    return 0;
}