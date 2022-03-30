//队列的链式实现(cpp)
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct LinkNode{        //链式队列结点
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{                 //链式队列
    LinkNode *front,*rear;      //队列的队头和队尾指针
}LinkQueue;

//初始化（带头结点）
void InitQueue(LinkQueue &Q){
    //初始时front和rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear){
        printf("队列为空!\n");
        return true;
    }else{
        printf("队列非空!\n");
        return false;
    }
}

/*
    不带头结点的初始化就是将队头和队尾指针都指向NULL，判空
    时的判断条件为Q.front == NULL。
*/

//入队（带头结点）
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;   //新结点插入到rear之后
    Q.rear = s;         //修改表尾指针
    printf("元素%d入队成功!\n",x);
}

//入队（不带头结点）
/*void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    //不带头结点的队列，第一个元素入队时需要特别处理
    if(Q.front == NULL){    //在空队列中插入第一个元素
        Q.front = s;        //修改队头队尾指针
        Q.rear = s;
    }else{
        Q.rear->next = s;   //新结点插入到rear结点之后
        Q.rear = s;         //修改rear指针
    }
}*/

//队头元素出队（带头结点）
bool DeQueue(LinkQueue &Q,int x){
    if(Q.front == Q.rear){
        printf("队空!\n");
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;                //用变量x返回队头元素
    Q.front->next = p->next;    //修改头结点的next指针
    if(Q.rear == p)             //此次是最后一个结点出队
        Q.rear = Q.front;       //修改rear指针
    free(p);
    printf("元素%d出队成功!\n",x);
    return true;
}

//队头元素出队（不带头结点）
/*bool DeQueue(LinkQueue &Q,int x){
    if(Q.front == NULL){
        printf("队空!\n");
        return false;
    }
    LinkNode *p = Q.front;      //p指向此次出队的结点
    x = p->data;                //用变量x返回队头元素
    Q.front = p->next;          //修改front指针
    if(Q.rear == p){            //此次是最后一个结点出队
        Q.front = NULL;
        Q.rear =NULL;
    }
    free(p);
    printf("元素%d出队成功!\n",x);
    return true;
}*/

int main(){
    LinkQueue Q;
    int x;
    InitQueue(Q);
    IsEmpty(Q);
    EnQueue(Q,3);
    IsEmpty(Q);
    EnQueue(Q,2);
    DeQueue(Q,x);

    return 0;
}
