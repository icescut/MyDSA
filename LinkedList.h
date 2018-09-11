/****************************************************************************
 * File name    : LinkedList.h
 * Author       : Alan Liang
 * Description  : ����
 * History      :
 *                v0.1  Alan        2018/08/22 �����ļ�
 ****************************************************************************/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Status.h"

typedef struct Node
{
    ElemType data;      // ������
    struct Node *next;  // ָ����
} Node;

typedef struct
{
    Node *head;
    int len;
} LinkedList;

// ��ʼ������
Status LinkedList_Init(LinkedList *L);

// ����
Status LinkedList_Insert(LinkedList *L, int i, ElemType e);

// ɾ��
Status LinkedList_Delete(LinkedList *L, int i);

// ��ȡĳλ���ϵ�Ԫ��
Status LinkedList_Get(LinkedList L, int i, ElemType *e);

// ����ĳ��Ԫ�صĵ�һ������λ��
int LinkedList_Find(LinkedList L, ElemType e);

// ����
void LinkedList_Traverse(LinkedList L);

#endif // LINKEDLIST_H_INCLUDED