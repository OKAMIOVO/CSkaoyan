/*
静态链表:分配一整片连续的内存空间，各个结点集中安置
    其中，每个数据元素4B，每个游标4B（每个结点共8B）
*/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MaxSize 10      //静态链表的最大长度
struct Node{            //静态链表结构类型的定义
    int data;           //存储数据元素
    int next;           //下一个元素的数组下标
};

typedef struct{         //静态链表结构类型的定义
    int data;           //存储数据元素
    int next;           //下一个元素的数组下标
}SLinkList[MaxSize];

/*
注: SLinkList a;   //此处a是一个静态链表
    struct Node a[MaxSize]  //此处a是一个Node型数组
    上面两者是等价的
*/
//验证
int main(){
    struct Node x;
    printf("sizeX=%d\n",sizeof(x));

    struct Node a[MaxSize];
    printf("sizeA=%d\n",sizeof(a));

    SLinkList b;
    printf("sizeB=%d\n",sizeof(b));

    return 0;
}