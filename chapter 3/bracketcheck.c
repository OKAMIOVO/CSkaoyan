//栈的应用－括号匹配
/*
    最后出现的左括号最先被匹配（LIFO）
    每出现一个右括号，就“消耗”（出栈）一个左括号
*/
//遇到左括号就入栈
//遇到右括号就“消耗”一个左括号

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MaxSize 10
typedef struct{
    char data[MaxSize];     //静态数组存放栈中元素
    int top;                //栈顶指针
}SqStack;

//初始化栈
SqStack* InitStack(SqStack *S){
    S = (SqStack*)malloc(sizeof(SqStack));
    if(S==NULL)          //内存不足，分配失败
        return false;
    S->top = -1;         //初始化栈顶指针
    return S;
}

//判断栈空
bool StackEmpty(SqStack *S){
    if(S->top == -1){
        printf("栈空!\n");
        return true;
    }
    else{
        printf("栈非空!\n");
        return false;
    }
}

//新元素入栈
bool Push(SqStack *S,char x){
    if(S->top == MaxSize-1)      //栈满，报错
        return false;
    S->top = S->top + 1;          //指针先加1
    S->data[S->top] = x;          //新元素入栈
    //等价写法 S.data[++S.top] = x;
    printf("元素%c入栈成功!\n",x);
    return true;
}

//出栈操作
bool Pop(SqStack *S,char *x){
    if(S->top == -1)             //栈空，报错
        return false;
    *x = S->data[S->top];          //元素先出栈
    S->top = S->top - 1;           //指针再减1
    //等价:x = S.data[S.top--]
    printf("元素%c出栈成功!\n",*x);
    return true; 
    //也可以用返回值返回x的值，修改函数返回值类型为char，然后return，就不需要用指针了
}

//读栈顶元素
bool GetTop(SqStack *S,char x){
    if(S->top == -1)               //栈空,报错
        return false;
    x = S->data[S->top];          //x记录栈顶元素
    printf("栈顶元素为%c\n",x);
    return true;
}

//括号匹配
bool bracketCheck(char str[],int length){
    SqStack* S;
    S = InitStack(S);      //初始化一个栈
    for(int i = 0; i < length; i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S,str[i]); //扫描到左括号，入栈
        }else{
            if(StackEmpty(S)){  //扫描到右括号，且当前栈空
                printf("匹配失败!\n");
                return false;   //匹配失败
            }
            char c = 'c';
            char* topElem = &c;
            Pop(S,topElem);     //栈顶元素出栈
            if(str[i]==')'&&*topElem!='('){
                printf("匹配失败!\n");
                return false;
            }
            if(str[i]==']'&&*topElem!='['){
                printf("匹配失败!\n");
                return false;
            }
            if(str[i]=='}'&&*topElem!='{'){
                printf("匹配失败!\n");
                return false;
            }
            
               
        }
    }
    printf("匹配成功!\n");
    return StackEmpty(S);       //检索完全部括号后，栈空说明匹配成功

}

int main(){
    char str[7] = {'{','[','(',')',']','}','\0'};
    bracketCheck(str,6);
    return 0;
}