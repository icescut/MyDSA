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
#include "Status.h"

typedef struct
{
    ElemType *elems;    // ����
    int len;            // Ԫ�ظ���
    int size;
} AStack;

// ��ʼ��ջ
Status AStack_Init(AStack *L);

// ��ջ
Status AStack_Push(AStack *L, ElemType e);

// �������n��Ԫ�ص����Ա�
Status Random_Create_AStack(AStack *L, int n);

// ���Ա���ʾ
void AStack_Sample();

#endif // ASTACK_H_INCLUDED
