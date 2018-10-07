/****************************************************************************
 * File name    : AStack.h
 * Author       : Alan Liang
 * Description  : 线性表
 * History      :
 *                v0.1  Alan        2018/09/24 建立文件
 ****************************************************************************/
#ifndef ASTACK_H_INCLUDED
#define ASTACK_H_INCLUDED

#include <stdlib.h>
#include "Status.h"

typedef struct
{
    ElemType *elems;    // 数组
    int len;            // 元素个数
    int size;
} AStack;

// 初始化栈
Status AStack_Init(AStack *L);

// 入栈
Status AStack_Push(AStack *L, ElemType e);

// 随机建立n个元素的线性表
Status Random_Create_AStack(AStack *L, int n);

// 线性表演示
void AStack_Sample();

#endif // ASTACK_H_INCLUDED
