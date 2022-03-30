//单链表
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//带头结点的单链表
bool InitList(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));     //头节点
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool Empty(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

int main(){
    LinkList L;
    int t = InitList(L);
    printf("%d",t);

    system("pause");
    return 0;
    
}