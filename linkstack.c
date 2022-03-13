//链栈
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct LinkNode{
    int data;               //数据域
    struct LinkNode *next;  //指针域
}LinkNode,*LinkStack;

//初始化链栈(不带头结点)
LinkStack InitStack(LinkStack top){
   top = NULL;  //空栈
   return top;
}

//判断链栈是否为空
bool Empty(LinkStack top){
    if(top == NULL){
        printf("栈空!\n");
        return true;
    }else{
        printf("栈非空!\n");
        return false;
    }  
}

//元素入栈
LinkStack Push(LinkStack top,int e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = top;
    top = s;
    return top;
}
//元素出栈
LinkStack Pop(LinkStack top,int e){
    if(top == NULL){    //栈空
        printf("栈已空");
        return false;
    }
    LinkNode *p = top;  //创建一个指向栈顶的指针
    e = p->data;  
    top = p->next;      //栈顶指针下移
    printf("出栈元素值为%d\n",e);
    free(p);
    return top;  
}

//读栈顶操作
bool GetTop(LinkStack top,int e){
    if(top == NULL){
        printf("栈为空!\n");
        return false;
    }
    e = top->data;
    printf("栈顶元素为%d\n",e);

}

//调用函数时，只要是top指针的指向发生了变化，就要返回其值
int main(){
    LinkStack top;
    top = InitStack(top);
    //Empty(top);
    int e = -1; 
    top = Push(top,e);
    int x = 0;
    GetTop(top,x);
    int t = -2;
    top = Pop(top,t);
    GetTop(top,x);

    return 0;

}