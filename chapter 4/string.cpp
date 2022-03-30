//串的顺序存储
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXLEN 255 //预定义最大串长为255
//静态数组(定长顺序存储)
typedef struct
{
	char ch[MAXLEN]; //每个分量存储一个字符
	int length;		 //串的实际长度
} SString;

/*
//动态数组(堆分配存储)
typedef struct{
	char *ch;			//按串长分配存储区，ch指向串的基地址
	int length;			//串长
}HString;
HString S;
S.ch = (char*)malloc(MAXLEN*sizeof(char));	//用完记得free
S.length = 0;
*/

//求串长，返回串S的元素个数
int StrLength(SString S){
	//int sum = 1;
	int i = 1;
/* 	for(i=0; i<MAXLEN; i++){
		if(S.ch[i]!='\0'){
			sum += i;
		}
	} */
	while(S.ch[i]!='\0'){
		i++;
	}
	return i-1;
}

//求子串
//用sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
	//子串范围越界
	if (pos+len-1 > S.length)
	{
		printf("越界!\n");
		return false;
	}
	for (int i=pos; i<pos+len; i++)
		// ch[0]废弃不用
		Sub.ch[i-pos+1] = S.ch[i];
	Sub.length = len;
	return true;
}

// 比较操作 若S>T，则返回值>0;若S=T,则返回=0;若S<T，则返回值<0
int StrCompare(SString S, SString T)
{
	for (int i=1; i<=S.length && i<=T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//扫描过的所有字符都相同，则长度长的串更大
	return S.length - T.length;
}

//定位操作：若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数值为0
int Index(SString S,SString T){
	int i = 1,n = StrLength(S),m = StrLength(T);
	SString sub;		//用于暂存字符串
	while(i<=n-m+1){	//此表达式是递推出来的，详见课件4.1.2
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			++i;
		else
			return i;	//返回子串在主串中的位置
	}
	return 0;			//S中不存在与T相等的子串
}

int main()
{
	SString S;
	S.ch[0] = '7';
	S.ch[1] = 'w';
	S.ch[2] = 'a';
	S.ch[3] = 'n';
	S.ch[4] = 'g';
	S.ch[5] = 'd';
	S.ch[6] = 'a';
	S.ch[7] = 'o';
	S.ch[8] = '\0';
	S.length = 7;
	SString Sub;
/* 	int l = StrLength(S);
	printf("S串长为%d\n",l);
	SubString(Sub, S, 2, 4);
	for (int i = 1; i < 5; i++)
		printf("匹配%c\n", Sub.ch[i]); */
	// printf("%s\n",S.ch);
	SString T;
	T.ch[0] = '3';
	T.ch[1] = 'g';
	T.ch[2] = 'd';
	T.ch[3] = 'a';
	T.ch[4] = '\0';
	T.length = 3;
/* 	printf("T串长为%d\n",StrLength(T)); */
/* 	int x = StrCompare(S, T);
	if (x > 0)
	{
		printf("S>T!\n");
	}else if(x < 0)
	{
		printf("S<T!\n");
	}else
	{
		printf("S=T!\n");
	}
	 */
	int i = Index(S,T);
	if(i!=0){
		printf("子串在主串的起始位置为%d\n",i);
	}else{
		printf("S中不存在与T相等的子串!\n");
	}

	return 0;
}