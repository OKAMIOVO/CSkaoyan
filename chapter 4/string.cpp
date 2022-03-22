//串的顺序存储
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXLEN 255		//预定义最大串长为255
//静态数组(定长顺序存储)
typedef struct{
	char ch[MAXLEN];	//每个分量存储一个字符
	int length;			//串的实际长度
}SString;

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

//求子串
//用sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString &Sub,SString S,int pos,int len){
	//子串范围越界
	if(pos + len-1 > S.length){
		printf("越界!\n");
		return false;
	}
	for(int i = pos;i < pos+len;i++)
		//ch[0]废弃不用
		Sub.ch[i-pos+1] = S.ch[i];
	Sub.length = len;
	return true;
}


int main(){
	SString S;
	char c[8] = "wangdao";
	S.ch[0] = 'w';
	S.ch[1] = 'a';
	S.ch[2] = 'n';
	S.ch[3] = 'g';
	S.ch[4] = 'd';
	S.ch[5] = 'a';
	S.ch[6] = 'o';
	S.length = 7;
	SString Sub;
	SubString(Sub,S,2,4);
	for(int i=1;i<5;i++)
	printf("匹配%c\n",Sub.ch[i]);
	//printf("%s\n",S.ch);

	return 0;

}