//循环单链表
//循环单链表的表尾结点的next指针指向头结点
/*
循环单链表从一个结点出发可以找到其他任何一个结点
单链表从一个结点出发可以找到后续的各个结点
*/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//初始化一个循环单链表
LinkList InitList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));  //分配一个头结点
    if(L==NULL)     //内存不足，分配失败
        return false;
    L->next = L;    //头结点的next指针指向头结点
    return L;
}

//判断循环单链表是否为空
bool Empty(LinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}

//判断p结点是否为循环单链表的表尾结点
bool isTail(LinkList L,LNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}

int main(){
    LinkList L;
    L = InitList(L);
    if(L!=NULL)
        printf("循环单链表初始化成功!\n");
    else
        printf("内存不足分配失败!\n");
    
    return 0;
}