/****************************************************************************
 * File name    : ArrayList.h
 * Author       : Alan Liang
 * Description  : ���Ա�
 * History      :
 *                v0.1  Alan        2018/08/18 �����ļ�
 ****************************************************************************/

#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include <stdbool.h>
#include "Status.h"

typedef int ElemType;

typedef struct {
    ElemType *elems;    // ����
    int len;            // Ԫ�ظ���
    int size;           // ����
} ArrayList;

// ��ʼ�����Ա�
Status Init(ArrayList *L);

// �����Ա�������һ��Ԫ��
Status Append(ArrayList *L, ElemType e);

// �����Ա��м����һ��Ԫ��
Status Insert(ArrayList *L, int pos, ElemType e);

// �����Ա��м�ɾ��һ��Ԫ��
Status Delete(ArrayList *L, int pos);

// ��ȡĳλ���ϵ�Ԫ��
Status Get(ArrayList L, int pos, ElemType *e);

// ����ĳλ���ϵ�Ԫ��
Status Set(ArrayList *L, int pos, ElemType e);

// ����ĳ��Ԫ�صĵ�һ������λ��
int Find(ArrayList L, ElemType e);

// ������Ա�
void Clear(ArrayList *L);

// �ж����Ա��Ƿ�Ϊ��
bool Is_Empty(ArrayList L);

// �������Ա�ĳ���
int Length(ArrayList L);

// ��ӡ�б�
void Traverse(ArrayList L);

#endif // ARRAYLIST_H_INCLUDED
