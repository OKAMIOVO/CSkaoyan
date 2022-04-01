/**
 * @file simpleMatch.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 朴素模式匹配算法
 * @version 0.1
 * @date 2022-03-28 18:27:01
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
//静态数组(定长顺序存储)
typedef struct {
    char ch[MAXLEN]; //每个分量存储一个字符
    int length;      //串的实际长度
} SString;

/* 与串的链式存储代码相同 用字符串的基本操作实现*/
//定位操作：若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数值为0
/* int Index(HString S,HString T){
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
} */

/**
 * @brief 朴素模式匹配算法-数组下标实现
 *
 * @param S 主串
 * @param T 模式串
 * @return int 返回当前子串第一个字符的位置
 */
int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            //继续比较后续字符
            ++i;
            ++j;
        } else {
            i = i - j + 2; //若当前子串匹配失败，则主串指针i指向下一个子串的第一个位置，模式串指针j回到模式串的第一个位置
            j = 1; //指针后退重新开始匹配
        }
    }
    //若j>T.length,则当前子串匹配成功，返回当前子串第一个字符的位置--i-T.length
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main() {
    SString S;
    S.ch[0] = '0';
    S.ch[1] = 'a';
    S.ch[2] = 'b';
    S.ch[3] = 'a';
    S.ch[4] = 'a';
    S.ch[5] = 'b';
    S.ch[6] = 'a';
    S.ch[7] = 'a';
    S.ch[8] = 'b';
    S.ch[9] = 'c';
    S.ch[10] = 'a';
    S.ch[11] = 'b';
    S.ch[12] = 'a';
    S.ch[13] = 'a';
    S.ch[14] = 'b';
    S.ch[15] = 'c';
    S.ch[16] = '\0';
    S.length = 15;
    SString T;
    T.ch[0] = '0';
    T.ch[1] = 'a';
    T.ch[2] = 'b';
    T.ch[3] = 'a';
    T.ch[4] = 'a';
    T.ch[5] = 'b';
    T.ch[6] = 'b';
    T.ch[7] = '\0';
    T.length = 6;

    int i = Index(S, T);
    if (i != 0) {
        printf("匹配成功，模式串T在主串中的起始位置为%d\n", i);
    } else {
        printf("匹配失败！\n");
    }

    return 0;
}