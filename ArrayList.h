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
#include <time.h>
#include "Status.h"

typedef struct
{
    ElemType *elems;    // ����
    int len;            // Ԫ�ظ���
    int size;           // ����
} ArrayList;

// ��ʼ�����Ա�
Status ArrayList_Init(ArrayList *L);

// �����Ա�������һ��Ԫ��
Status ArrayList_Append(ArrayList *L, ElemType e);

// �����Ա��м����һ��Ԫ��
Status ArrayList_Insert(ArrayList *L, int pos, ElemType e);

// �����Ա��м�ɾ��һ��Ԫ��
Status ArrayList_Delete(ArrayList *L, int pos);

// ��ȡĳλ���ϵ�Ԫ��
Status ArrayList_Get(ArrayList L, int pos, ElemType *e);

// ����ĳλ���ϵ�Ԫ��
Status ArrayList_Set(ArrayList *L, int pos, ElemType e);

// ����ĳ��Ԫ�صĵ�һ������λ��
int ArrayList_Find(ArrayList L, ElemType e);

// ������Ա�
void ArrayList_Clear(ArrayList *L);

// �ж����Ա��Ƿ�Ϊ��
bool ArrayList_Is_Empty(ArrayList L);

// �������Ա�ĳ���
int ArrayList_Length(ArrayList L);

// ��ӡ�б�
void ArrayList_Traverse(ArrayList L);

// �������n��Ԫ�ص����Ա�
Status Random_Create_ArrayList(ArrayList *L, int n);

// ���Ա���ʾ
void ArrayList_Sample();

#endif // ARRAYLIST_H_INCLUDED
