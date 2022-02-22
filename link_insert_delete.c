//单链表的插入、删除
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
LinkList InitList(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));     //头节点
    L->data = 999;
    if(L == NULL){                          //内存分配不足
        printf("L == NULL\n");
        return false;
    }
    L->next = NULL;
    return L;
}

bool Empty(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

//按位序插入
bool LinkInsert(LinkList L,int i,int e){    //在第i个位置上插入元素e
    if(i < 1)
        return false;
    LNode *p;       //指针p指向当前扫描到的节点
    int j = 0;      //指针p指向的是第几个节点
    p = L;          //L指向头节点，头节点是第0个节点
    while(p != NULL && j < i -1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//按位序删除(带头结点)
bool ListDelete(LinkList L,int i,int *e){
    if(i < 1)
        return false;
    LNode *p;       //指针p指向当前扫描到的节点
    int j = 0;      //指针p指向的是第几个节点
    p = L;          //L指向头节点，头节点是第0个节点
    while(p != NULL && j < i -1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
    
}

//删除指定节点
bool DeleteNode(LNode *p){
    if(p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;  //此处有bug  
    p->next = q->next;
    free(q);
    return true;
}

int main(){
    LinkList L;
    L = InitList(L);
    //printf("%d\n",t);

    bool t = LinkInsert(L,1,1);
    if(t == true)
        printf("success!\n");
    else
        printf("fail!\n");
    int e = -1;
    if (ListDelete(L,1,&e))
        printf("已删除元素，删除元素值为%d\n",e);
    else
        printf("位序不合法，删除失败!\n");
        
    
    //system("pause");
    return 0;
    
}