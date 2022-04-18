/**
 * @file kmp_optimization.cpp
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief kmp算法的优化（nextval数组）
 * @version 0.1
 * @date 2022-04-18 19:02:08
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

/**
 * @brief 求模式串T的next数组
 *
 * @param T 模式串T
 * @param next 待求的next数组
 */
int* get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            // 若pi=pj(此处位串的前缀和后缀),则next[j+1]=next[j]+1
            next[i] = j;
        } else
            //否则令j=next[j],循环继续
            j = next[j];
    }
    // 求nextval数组，先求出next数组，令nextval[1]=0
    int nextval[T.length+1];
    nextval[1] = 0;
    for (int k = 2; k <= T.length; k++) {
        if (T.ch[next[k]] == T.ch[k])
            nextval[k] = nextval[next[k]];
        else
            nextval[k] = next[k];
    }

    return nextval;
}
// KMP算法的平均时间复杂度：O(m+n)

/* KMP算法对模式串具有通用性，与主串没有任何关系 */
/**
 * @brief KMP
 *
 * @param S 主串
 * @param T 模式串
 * @param next next数组
 * @return int
 */
/* int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            // 继续比较后继字符
            ++i;
            ++j;
        } else {
            j = next[j]; //模式串向右移动
        }
    }
    if (j > T.length)
        return i - T.length; //匹配成功
    else
        return 0;
} */

/**
 * @brief 改进KMP算法
 *
 * @param S 主串
 * @param T 模式串
 * @return int 返回位置
 */
int Index_KMP(SString S, SString T) {
    int i = 1, j = 1;
    int next[T.length + 1];
    int* nextval = get_next(T, next); //求模式串的next数组 O(m)
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            // 继续比较后继字符
            ++i;
            ++j;
        } else {
            j = nextval[j]; //模式串向右移动
        }
    }
    if (j > T.length)
        return i - T.length; //匹配成功
    else
        return 0;
}

int main() {
    SString S;
    SString T;

    S.ch[0] = '0';
    S.ch[1] = 'a';
    S.ch[2] = 'a';
    S.ch[3] = 'a';
    S.ch[4] = 'a';
    S.ch[5] = 'c';
    S.ch[6] = 'a';
    S.ch[7] = 'a';
    S.ch[8] = 'b';
    S.ch[9] = 'a';
    S.ch[10] = 'a';
    S.ch[11] = 'a';
    S.ch[12] = 'a';
    S.ch[13] = 'a';
    S.ch[14] = 'b';
    S.ch[15] = 'c';
    S.ch[16] = '\0';
    S.length = 15;

    T.ch[0] = '0';
    T.ch[1] = 'a';
    T.ch[2] = 'a';
    T.ch[3] = 'a';
    T.ch[4] = 'a';
    T.ch[5] = 'b';
    T.ch[6] = 'c';
    T.ch[7] = '\0';
    T.length = 6;

    int next[] = {0, 0, 1, 1, 2, 2, 3};
    int i = Index_KMP(S, T);
    if (i != 0) {
        printf("匹配成功，模式串T在主串中的起始位置为%d\n", i);
    } else {
        printf("匹配失败！\n");
    }

    return 0;
}