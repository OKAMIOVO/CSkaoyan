//循环双链表
/*
循环双链表:
    表头结点的prior指向表尾结点
    表尾结点的next指向头结点
*/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct DNode{   //定义循环双链表结点类型
    int data;   //数据域
    struct DNode *prior,*next; //前驱和后继指针
}DNode,*DLinklist;

//初始化空的循环双链表
DLinklist InitDLinkList(DLinklist L){
    L = (DNode*)malloc(sizeof(DNode));  //分配一个头结点
    if(L==NULL)     //内存不足，分配失败
        return false;
    L->prior = L;   //头结点的prior指向头结点
    L->next = L;    //头结点的next指向头结点
    return L;
}

//判断循环双链表是否为空
bool Empty(DLinklist L){
    if(L->next == L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L,DNode *p){
    if(p->next == L)
        return true;
    else
        return false;
}

int main(){
    DLinklist L;
    L = InitDLinkList(L);
    if(L!=NULL)
        printf("循环双链表初始化成功!\n");
    else
        printf("内存不足分配失败!\n");
    
    return 0;
}