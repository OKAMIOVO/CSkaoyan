//队列（顺序实现）
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MaxSize 10      //定义队列中元素的最大个数
typedef struct{
    int data[MaxSize];  //用静态数组存放队列元素
    int front,rear;     //队头指针和队尾指针
}SqQueue;

//