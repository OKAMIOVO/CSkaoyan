//顺序栈
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MaxSize 10      //定义栈中元素的最大个数
typedef struct{
    int data[MaxSize];  //静态数组存放栈中元素
    int top;            //栈顶指针
}SqStack;

//初始化栈
SqStack* InitStack(SqStack *S){
    S = (SqStack*)malloc(sizeof(SqStack));
    S->top = -1;         //初始化栈顶指针
    return S;
}

//判断栈空
bool StackEmpty(SqStack *S){
    if(S->top == -1)
        return true;
    else
        return false;
}

//新元素入栈
bool Push(SqStack *S,int *x){
    if(S->top == MaxSize-1)      //栈满，报错
        return false;
    S->top = S->top + 1;          //指针先加1
    S->data[S->top] = *x;          //新元素入栈
    //等价写法 S.data[++S.top] = x;
    return true;
}

//出栈操作
bool Pop(SqStack *S,int *x){
    if(S->top == -1)             //栈空，报错
        return false;
    *x = S->data[S->top];          //元素先出栈
    S->top = S->top - 1;          //指针再减1
    return true; 
}

//读栈顶元素
bool GetTop(SqStack *S,int *x){
    if(S->top == -1)             //栈空,报错
        return false;
    *x = S->data[S->top];          //x记录栈顶元素
    return true;
}
/*
此外还有另一种方式令初始top＝0，也就是让其指向下一个可以插入的位置
这时，栈满的条件为top＝＝MaxSize
*/

int main(){
    SqStack *S;
    S = InitStack(S);
    if(StackEmpty(S) == true)
        printf("栈空!\n");
    else
        printf("栈非空!\n");

    int x = 3;
    if(Push(S,&x) == true)
        printf("入栈成功，入栈元素=%d\n",x);
    else
        printf("入栈失败!\n");
    
    int e = -1;
    if(Pop(S,&e)==true)
        printf("出栈成功，出栈元素=%d\n",e);
    else
        printf("出栈失败!\n");

    int r = -1;
    if(GetTop(S,&r)==true)
        printf("栈顶元素＝%d\n",r);
    else
        printf("栈空!\n");

    return 0;

}