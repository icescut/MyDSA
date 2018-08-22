/****************************************************************************
 * File name    : ArrayList.c
 * Author       : Alan Liang
 * Description  : 线性表
 * History      :
 *                v0.1  Alan        2018/08/18 建立文件
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

/*
 * Function     : 初始化线性表
 * Description  : 线性表分配内存空间，初始化长度
 * In           : 线性表指针
 * Out          : 状态
 */
Status Init(ArrayList *L)
{
    // 分配内存空间
    L->elems = (ElemType *)malloc(sizeof(ElemType) * CAPACITY);
    if (L->elems == NULL) return ERROR;

    // 初始化容量和元素个数
    L->size = CAPACITY;
    L->len = 0;
    return OK;
}

/*
 * Function     : 在末尾插入元素
 * Description  : 如果没有空间，扩容。在末尾插入元素
 * In           : 线性表指针，待插入元素
 * Out          : 状态
 */
Status Append(ArrayList *L, ElemType e)
{
    return Insert(L, L->len, e);
}

/*
 * Function     : 在中间插入元素
 * Description  : 如果没有空间，扩容。最后到插入位置的元素依次后移一位，在插入位置放置待插入元素
 *                可插入位置为[0, len]
 * In           : 线性表指针，待插入位置，待插入元素
 * Out          : 状态
 */
Status Insert(ArrayList *L, int pos, ElemType e)
{
    ElemType * new_elems;

    // 判断位置是否合法
    if (pos < 0 || pos > L->len) return OUT_OF_RANGE;

    if (L->elems == NULL) Init(L);

    // 扩容
    if (L->len >= L->size)
    {
        new_elems = (ElemType *)realloc(L->elems, (L->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        L->elems = new_elems;
        L->size += INCREMENT;
    }

    // 最后到插入位置的元素依次后移一位
    for (int i = L->len - 1; i >= pos; --i)
    {
        L->elems[i+1] = L->elems[i];
    }

    // 在插入位置放置待插入元素
    L->elems[pos] = e;

    L->len++;

    return OK;
}

/*
 * Function     : 在中间删除一个元素
 * Description  : 删除位置+1到最后的元素依次前移一位
 *                可删除位置为[0, len)
 * In           : 线性表指针，待删除位置
 * Out          : 状态
 */
Status Delete(ArrayList *L, int pos)
{
    // 判断位置是否合法
    if (pos < 0 || pos >= L->len) return OUT_OF_RANGE;

    // 删除位置+1到最后的元素依次前移一位
    for (int i = pos+1; i < L->len; ++i)
    {
        L->elems[i-1] = L->elems[i];
    }

    L->len--;

    return OK;
}

/*
 * Function     : 获取某位置上的元素
 * Description  : 使用下标运算符
 * In           : 线性表，位置，保存该元素的变量
 * Out          : 状态
 */
Status Get(ArrayList L, int pos, ElemType *e)
{
    // 判断位置是否合法
    if (pos < 0 || pos >= L.len) return OUT_OF_RANGE;
    *e = L.elems[pos];
    return OK;
}

/*
 * Function     : 设置某位置上的元素
 * Description  : 使用下标运算符
 * In           : 线性表指针，位置，待设置值
 * Out          : 状态
 */
Status Set(ArrayList *L, int pos, ElemType e)
{
    // 判断位置是否合法
    if (pos < 0 || pos >= L->len) return OUT_OF_RANGE;
    L->elems[pos] = e;
    return OK;
}

/*
 * Function     : 查找某个元素的第一个出现位置
 * Description  :
 * In           : 线性表，待查找元素
 * Out          : 状态
 */
int Find(ArrayList L, ElemType e)
{
    for (int i = 0; i < L.len; ++i)
    {
        if (L.elems[i] == e) return i;
    }
    return -1;
}

/*
 * Function     : 清空线性表
 * Description  :
 * In           : 线性表指针
 * Out          : void
 */
void Clear(ArrayList *L)
{
    if (L->elems) free(L->elems);
    L->elems = NULL;
    L->len = 0;
    L->size = 0;
}

/*
 * Function     : 判断线性表是否为空
 * Description  :
 * In           : 线性表
 * Out          : true / false
 */
bool Is_Empty(ArrayList L)
{
    if (L.len) return true;
    return false;
}

/*
 * Function     : 返回线性表的长度
 * Description  :
 * In           : 线性表
 * Out          : 线性表的长度
 */
int Length(ArrayList L)
{
    return L.len;
}

/*
 * Function     : 打印线性表
 * Description  :
 * In           : 线性表
 */
void Traverse(ArrayList L)
{
    int len = 11 + 3 * L.len;
    for (int i = 0; i < len; ++i)
        printf("-");

    // TODO 判断元素的位数
    printf("\n|position |");
    for (int i = 0; i < L.len; ++i)
    {
        printf("%2d|", i);
    }
    //打印长度
    printf("\n|list (%2d)|", L.len);
    for (int i = 0; i < L.len; ++i)
    {
        printf("%2d|", L.elems[i]);
    }
    printf("\n");
    for (int i = 0; i < len; ++i)
        printf("-");
    printf("\n\n");
}
