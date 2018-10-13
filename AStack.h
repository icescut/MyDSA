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
#include <stdbool.h>
#include <time.h>
#include "Status.h"

typedef struct
{
    ElemType *elems;    // 数组
    int len;            // 元素个数
    int size;
} AStack;

// 初始化栈
Status AStack_Init(AStack *S);

// 入栈
Status AStack_Push(AStack *S, ElemType e);

// 出栈
Status AStack_Pop(AStack *S, ElemType *e);

// 返回栈顶元素
Status AStack_Top(AStack S, ElemType *e);

// 栈顶是否为空
bool AStack_Is_Empty(AStack S);

// 栈长度
int AStack_Length(AStack S);

// 打印栈
void AStack_Traverse(AStack S);

// 随机建立n个元素的线性表
Status Random_Create_AStack(AStack *S, int n);

// 线性表演示
void AStack_Sample();

#endif // ASTACK_H_INCLUDED
