/**
 * @file linkstring.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 串的链式存储
 * @version 0.1
 * @date 2022-03-26 19:03:58
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXLEN 255 //预定义最大串长为255
//动态数组(堆分配存储)
typedef struct{
	char *ch;			//按串长分配存储区，ch指向串的基地址
	int length;			//串长
}HString;

//求串长，返回串S的元素个数
int StrLength(HString &S){
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
	S.length = i-1;
	return i-1;
}

//求子串
//用sub返回串S的第pos个字符起长度为len的子串
bool SubString(HString &Sub, HString S, int pos, int len)
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
int StrCompare(HString S, HString T)
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
int Index(HString S,HString T){
	int i = 1,n = StrLength(S),m = StrLength(T);
	HString sub;		//用于暂存字符串
	while(i<=n-m+1){	//此表达式是递推出来的，详见课件4.1.2
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			++i;
		else
			return i;	//返回子串在主串中的位置
	}
	return 0;			//S中不存在与T相等的子串
}

int main(){
	HString S;
	S.length = 0;
	/* 注意字符数组和字符串常量的区别 详见C语言小白变怪兽p349*/
	/* 字符数组在定义后可以读取和修改每个字符 字符串常量定义后只能读取不能修改 否则运行时会出现段错误 */
	/* 两者最根本区别是在内存中的存储区域不一样 详见pdf */
	/* 由于常量一旦被创建后其值就不能再改变，所以常量必须在定义的同时赋值（初始化），后面的任何赋值行为都将引发错误。 */
	char str[] = "0wangdao";
	S.ch = str;
	int l = StrLength(S);
	printf("字符串长度为%d\n",l);
	
	HString Sub;
	Sub.ch = (char *)malloc(MAXLEN * sizeof(char));
	SubString(Sub, S, 2, 4);
	for (int i = 1; i < 5; i++)
		printf("匹配%c\n", Sub.ch[i]);

	HString T;
	T.length = 0;
	char str1[] = "0gda";
	T.ch = str1;
	StrLength(T);

	int x = StrCompare(S, T);
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

	int i = Index(S,T);
	if(i!=0){
		printf("子串在主串的起始位置为%d\n",i);
	}else{
		printf("S中不存在与T相等的子串!\n");
	}

	free(Sub.ch);
	Sub.ch = NULL;

	return 0;
}