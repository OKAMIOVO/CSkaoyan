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
//动态数组(堆分配存储)
typedef struct{
	char *ch;			//按串长分配存储区，ch指向串的基地址
	int length;			//串长
}HString;

int Index(HString S,HString T)