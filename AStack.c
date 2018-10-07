/****************************************************************************
 * File name    : AStack.c
 * Author       : Alan Liang
 * Description  : 线性表
 * History      :
 *                v0.1  Alan        2018/09/24 建立文件
 ****************************************************************************/

#include "AStack.h"

 /*
 * Function     : 初始化栈
 * Description  :
 * In           : 栈指针
 * Out          : 状态
 */
Status AStack_Init(AStack *S)
{
    // 分配内存空间
    S->elems = (ElemType *)malloc(sizeof(ElemType) * CAPACITY);
    if (S->elems == NULL) return ERROR;

    // 初始化容量和元素个数
    S->size = CAPACITY;
    S->len = 0;
    return OK;
}

/*
 * Function     : 入栈
 * Description  : 如果没有空间，扩容。
 * In           : 线性表指针，待插入元素
 * Out          : 状态
 */
Status AStack_Insert(AStack *L, ElemType e)
{
    /*
    ElemType * new_elems;

    // 判断位置是否合法
    if (pos < 0 || pos > L->len) return OUT_OF_RANGE;

    if (L->elems == NULL) AStack_Init(L);

    // 扩容
    if (L->len >= L->size)
    {
        new_elems = (ElemType *)realloc(L->elems, (L->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        L->elems = new_elems;
        L->size += INCREMENT;
    }

    L->elems[L->len++] = e;

    return OK;
    */
}

/*
 * Function     : 入栈
 * Description  : 如果没有空间，扩容。
 * In           : 线性表指针，待插入元素
 * Out          : 状态
 */
Status Random_Create_AStack(AStack *L, int n);

// 线性表演示
void AStack_Sample();
