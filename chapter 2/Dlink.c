//双链表
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct DNode{   //定义双链表结点类型
    int data;   //数据域
    struct DNode *prior,*next; //前驱和后继指针
}DNode,*DLinklist;

//初始化双链表（带头结点）
DLinklist InitDLinkList(DLinklist L){
    L = (DNode*)malloc(sizeof(DNode));      //分配一个头结点
    if(L==NULL)     //内存不足分配失败
        return false;
    L->prior = NULL;    //头结点的prior永远指向NULL
    L->next = NULL;     //头结点之后暂时还没有结点
    return L;
}

//判断双链表是否为空（带头结点）
bool Empty(DLinklist L){
    if(L->next==NULL)
        return true;
    else
        return false;
}

//双链表的插入,在p结点之后插入s结点
bool InsertNextDnode(DNode *p,DNode *s){
    if(p==NULL||s==NULL)    //非法参数
        return false;
    s->next = p->next;
    if(p->next!=NULL)   //如果p结点有后继结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode *p){
    if(p==NULL)
        return false;
    DNode *q  =  p->next;       //找到p的后继结点q
    if(q == NULL)   //p没有后继
        return false;
    p->next =  q->next;
    if(q->next!=NULL)   //q结点不是最后一个结点
        q->next->prior = p;
    free(q);    //释放结点空间
    return true;
}

//双链表的删除
bool DestoryList(DLinklist L){
    //循环释放各个数据结点
    bool d;
    while(L->next!=NULL)
        d = DeleteNextDNode(L);
    free(L);    //释放头结点
    L == NULL;  //头指针指向NULL
    return d;
}
int main(){
    DLinklist L;
    L = InitDLinkList(L);
    /*if(i==true)
        printf("双链表初始化成功!\n");
    else
        printf("内存不足，初始化失!\n");*/
    DNode *p,*s;
    s = (DNode*)malloc(sizeof(DNode));
    p = L;
    bool t = InsertNextDnode(p,s);
    if(t==true)
        printf("插入结点成功!\n");
    else
        printf("插入失败!\n");
    bool d = DestoryList(L);
    if(d==true)
        printf("删除双链表成功!\n");
    else
        printf("删除双链表失败!\n");
    
    return 0;
}