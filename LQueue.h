/****************************************************************************
 * File name    : LQueue.h
 * Author       : Alan Liang
 * Description  : ����
 * History      :
 *                v0.1  Alan        2018/10/13 �����ļ�
 ****************************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include <stdbool.h>
#include <time.h>
#include "Status.h"

typedef struct QNode
{
    ElemType data;      // ������
    struct QNode *next;  // ָ����
} QNode;

typedef struct
{
    QNode *head;
    QNode *tail;
    int len;
} LQueue;

// ��ʼ������
Status LQueue_Init(LQueue *Q);

// �����β
Status LQueue_Insert(LQueue *Q, ElemType e);

// ɾ����ͷ
Status LQueue_Delete(LQueue *Q, ElemType *e);

// ��������
void LQueue_Traverse(LQueue Q);

// ���ض�ͷԪ��
Status LQueue_Front(LQueue Q, ElemType *e);

// ���ض�βԪ��
Status LQueue_Back(LQueue Q, ElemType *e);

// ���س���
int LQueue_Length(LQueue L);

// �Ƿ�Ϊ��
bool LQueue_Is_Empty(LQueue L);

// �������n��Ԫ�صĶ���
Status Random_Create_LQueue(LQueue *Q, int n);

// ������ʾ
void LQueue_Sample();

#endif // LQUEUE_H_INCLUDED
