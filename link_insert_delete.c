//�������Ĳ��롢ɾ��
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//��ͷ���ĵ�����
LinkList InitList(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));     //ͷ�ڵ�
    L->data = 999;
    if(L == NULL){                          //�ڴ���䲻��?
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

//��λ�����?
bool LinkInsert(LinkList L,int i,int e){    
    if(i < 1)
        return false;
    LNode *p;       //ָ��pָ��ǰɨ�赽�Ľڵ�
    int j = 0;      //ָ��pָ����ǵڼ����ڵ�?
    p = L;          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ�
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

//��λ��ɾ��(��ͷ���?)
bool ListDelete(LinkList L,int i,int *e){
    if(i < 1)
        return false;
    LNode *p;       //ָ��pָ��ǰɨ�赽�Ľڵ�
    int j = 0;      //ָ��pָ����ǵڼ����ڵ�?
    p = L;          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ�
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

//ɾ��ָ���ڵ�p
bool DeleteNode(LNode *p){
    if(p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;    
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
    if (ListDelete(L,3,&e))
        printf("��ɾ��Ԫ�ؿ�ɾ��Ԫ��ֵΪ%d\n",e);
    else
        printf("λ�򲻺Ϸ���ɾ��ʧ��!\n");
        
    
    //system("pause");
    return 0;
    
}