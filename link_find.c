//单链表的查找
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
//按位查找，返回第i个元素（带头结点）
LNode*  GetElem(LinkList L,int i){
    if(i<0)
       return NULL;
    LNode *p; //指针p指向当前当前扫描到的节点
    int j=0;  //当前p指向的是第几个结点
    p=L;    //L指向头结点，头结点是第0个结点（不存数据）
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;


}

//按值查找，找到数据域＝＝e的结点
LNode * LocateElem(LinkList L, int e){
    LNode *p=L->next;   //从第一个结点开始查找数据域为e的结点
    while (p!=NULL && p->data!=e)
        p=p->next;
    return p;   //找到后返回该结点指针，否则返回NULL
}

//求表长度
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

int main(){
    LinkList L;
    L = InitList(L);
    //printf("%d\n",t);

    bool t = LinkInsert(L,1,3);
    if(t == true)
        printf("success!\n");
    else
        printf("fail!\n");
    LNode *p = GetElem(L,1);
    printf("该位置结点值为%d\n",p->data);
    LNode *n = LocateElem(L,3);

    int len = Length(L);
    printf("表的长度为%d\n",len);

	
    return 0;
}