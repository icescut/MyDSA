/****************************************************************************
 * File name    : AStack.h
 * Author       : Alan Liang
 * Description  : ���Ա�
 * History      :
 *                v0.1  Alan        2018/09/24 �����ļ�
 ****************************************************************************/
#ifndef ASTACK_H_INCLUDED
#define ASTACK_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Status.h"

typedef struct
{
    ElemType *elems;    // ����
    int len;            // Ԫ�ظ���
    int size;
} AStack;

// ��ʼ��ջ
Status AStack_Init(AStack *S);

// ��ջ
Status AStack_Push(AStack *S, ElemType e);

// ��ջ
Status AStack_Pop(AStack *S, ElemType *e);

// ����ջ��Ԫ��
Status AStack_Top(AStack S, ElemType *e);

// ջ���Ƿ�Ϊ��
bool AStack_Is_Empty(AStack S);

// ջ����
int AStack_Length(AStack S);

// ��ӡջ
void AStack_Traverse(AStack S);

// �������n��Ԫ�ص����Ա�
Status Random_Create_AStack(AStack *S, int n);

// ���Ա���ʾ
void AStack_Sample();

#endif // ASTACK_H_INCLUDED
