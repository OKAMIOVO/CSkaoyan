//头／尾插法建立单链表
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

//尾插法建立单链表
//后插操作，在p结点之后插入元素e
bool InsertNextNode(LNode *p,int e){
    if(p == NULL)
		return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)		//内存分配失败
		return false;
	s->data = e;	//用结点s保存数据元素e
	s->next = p->next;
	p->next = s;	//将结点s连接到p之后

	return true;

}

//尾插法正向建立单链表
LinkList List_TailInsert(LinkList L){
	int x;
	L=(LinkList)malloc(sizeof(LNode));	//建立头结点
	LNode *s,*r = L;	//r作为表尾指针
	scanf("%d",&x);		//输入结点的值
	while(x!=9999){		//输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;		//在r结点之后插入元素x
		r=s;			//永远保持r指向最后一个结点
		scanf("%d",&x); 
	}
	r->next =  NULL;		//尾结点指针置空
	return L;
}

//头插法建立单链表(逆向)
bool List_HeadInsert(LinkList L){
	LNode *s;
	int x;
	L->next = NULL;		//初始化为空链表
	scanf("%d",&x);		//输入结点的值
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));		//创建新结点
		s->data = x;
		s->next = L->next;
		L->next = s;	//将新结点插入表中，L 为头指针
		scanf("%d",&x);
	}
	return true;

}
/*
头插法和尾插法的一个小细节:
	尾插法最后需要返回指针是因为尾插法在其函数体中新建立了一个L，指向一个头结点，
	和初始化的L指向不一样，main函数中的L是初始化的L，和尾插法的L不一样，所以需要返回L
	而头插法没有建立新的头结点，所以不需要返回L。
*/
int main(){
    LinkList L;
    L = InitList(L);
    //printf("%d\n",t);
	LinkList p = List_TailInsert(L);
	while(p->next != NULL){
		p = p->next;
		printf("%d ",p->data);
	}
	/*List_HeadInsert(L);
	while(L->next != NULL){
		L = L->next;
		printf("%d ",L->data);
	}*/
	printf("\n"); 

	return 0;
}
