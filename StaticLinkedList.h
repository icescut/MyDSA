/****************************************************************************
 * File name    : StaticLinkedList.h
 * Author       : Alan Liang
 * Description  : ��̬����
 * History      :
 *                v0.1  Alan        2018/09/17 �����ļ�
 ****************************************************************************/

#ifndef STATICLINKEDLIST_H_INCLUDED
#define STATICLINKEDLIST_H_INCLUDED

#include <stdbool.h>
#include <time.h>
#include "Status.h"

#define MAXSIZE 15

typedef struct
{
    ElemType data;
    int next;
} SNode;    // ���

typedef struct
{
    SNode space[MAXSIZE];   // ���ռ�
    int head;               // ͷ���
    int free;               // ���пռ俪ʼ���
    int len;
} SLinkedList;

// ��ʼ��
Status SLinkedList_Init(SLinkedList *L);

// ��ȡ
Status SLinkedList_Get(SLinkedList L, int pos, ElemType *e);

// ����
Status SLinkedList_Set(SLinkedList *L, int pos, ElemType e);

// ����
int SLinkedList_Find(SLinkedList L, ElemType e);

// ����
Status SLinkedList_Insert(SLinkedList *L, int pos, ElemType e);

// ɾ��
Status SLinkedList_Delete(SLinkedList *L, int pos);

// ���س���
int SLinkedList_Length(SLinkedList L);

// �Ƿ�Ϊ��
bool SLinkedList_Is_Empty(SLinkedList L);

// �������
void SLinkedList_Clear(SLinkedList *L);

// �������
void SLinkedList_Traverse(SLinkedList L);

// �������n��Ԫ�ص�����
Status Random_Create_SLinkedList(SLinkedList *L, int n);

// ������ʾ
void SLinkedList_Sample();

#endif // STATICLINKEDLIST_H_INCLUDED
