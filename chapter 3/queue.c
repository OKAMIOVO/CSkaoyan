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

//初始化队列
void InitQueue(SqQueue *Q){
    //初始时 队头，队尾指针指向0
    Q->front = Q->rear = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear == Q.front){      //队空条件
        printf("队列为空!\n");
        return true;
    }else{
        printf("队列非空!\n");
        return false;
    }     
}

//入队（只能从队尾入队）
bool EnQueue(SqQueue *Q,int x){
    /*
      队列已满的条件:队尾指针的再下一个位置是队头，即
      （Q.rear+1）%MaxSize==Q.front
      这样做的代价是牺牲一个存储单元（详见课件3.2.2）
    */
   if((Q->rear+1)%MaxSize==Q->front){   //判断队满条件
       printf("队已满!\n");
       return false;
   }
   Q->data[Q->rear] = x;                //新元素插入队尾
   Q->rear = (Q->rear+1)%MaxSize;       //队尾指针加一取模 用模运算将存储空间在逻辑上变成了环状
   printf("元素%d入队成功!\n",x);
   return true;
}

//出队操作（删除一个队头元素，并用x返回）
bool DeQueue(SqQueue *Q,int x){
    if(Q->front==Q->rear){
        printf("队空!\n");
        return false;
    }
    x = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxSize;    //队头指针后移
    printf("元素%d出队成功!\n",x);
    return true;
}

//获得队头元素的值，用x返回
bool GetHead(SqQueue Q,int x){
    if(Q.rear == Q.front){
        printf("队空!\n");
        return false;
    }
    x = Q.data[Q.front];
    printf("队头元素为%d\n",x);
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(&Q);
    QueueEmpty(Q);
    EnQueue(&Q,3);
    EnQueue(&Q,5);
    QueueEmpty(Q);
    DeQueue(&Q,0);
    GetHead(Q,-1);

    return 0;
}