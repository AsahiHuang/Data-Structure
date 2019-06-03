/*
 * =====================================================================================
 *
 *       Filename:  SqList.c
 *
 *    Description:  线性表的顺序存储结构
 *
 *        Version:  1.0
 *        Created:  2019年05月26日 10时20分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AsahiHuang (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
typedef int Status;
#define MAXSIZE 20 /* 存储空间初始分配 */
typedef int ElemType; /* ElemType类型根据实际情况而定,假设为int */
typedef struct 
{
	ElemType data[MAXSIZE];		/*数组存储数据元素,最大值为MAXSIZE*/
	int length;					/*线性表当前长度*/
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/* Status 是函数的类型,其值是函数结构状态代码,如OK */
/* 1 <= i <= ListLength(L) */


/* 用e返回L中第i个数据元素的值*/

Status GetElem(SqList L , int i , ElemType * e)
{
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

/*插入元素*/

Status ListInsert(SqList * L , int i , ElemType e)
{
	//线性表已满
	if (L -> length == MAXSIZE)
		return ERROR;
	//i不在范围内
	if (i < 1 || i > L -> length + 1)
		return ERROR;
	//i不在表尾
	if (i < L -> length)
	{
		for (int j = L -> length - 1; j >= i - 1; j--)
			L -> data[j + 1] = L -> data[j]; 
	}
	L -> data[i - 1] = e;
	L -> length++;
	return OK;
}

/*删除元素*/
Status ListDelete(SqList * L ,int i, ElemType * e)
{
	//线性表已满
	if (L -> length == 0)
		return ERROR;
	//i不再范围
	if (i < 1 || i > L -> length)
		return ERROR;
	//i不在表尾
	if (i < L -> length)
		for (int j = i; j < L -> length; j++)
			L -> data[j - 1] = L -> data[j];
	*e = L -> data[i - 1];
	L -> length--;
	return OK;
}




