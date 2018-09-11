/****************************************************************************
 * File name    : LinkedList.c
 * Author       : Alan Liang
 * Description  : ����
 * History      :
 *                v0.1  Alan        2018/08/22 �����ļ�
 ****************************************************************************/

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function     : ��ʼ������
 * Description  : ����ͷ��㣬��ʼ������
 * In           : ����ָ��
 * Out          : ״̬
 */
Status LinkedList_Init(LinkedList *L)
{
    // ����ͷ���
    L->head = (Node *)malloc(sizeof(Node));
    if (!L->head) return ERROR;
    // ͷ������һ�����Ϊ��
    L->head->next = NULL;

    L->len = 0;
    return OK;
}

/*
 * Function     : ����
 * Description  : �ںϷ���λ��[0, len]����Ԫ��
 * In           : ����ָ�룬λ�ã�������Ԫ��
 * Out          : ״̬
 */
Status LinkedList_Insert(LinkedList *L, int i, ElemType e)
{
    Node *p = L->head;
    int j = 0;  // ʵ��Ϊ�±�+1

    // ֱ��λ��i��ǰһ��λ��
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // ��i-1��Ԫ�ز����ڻ�i���Ϸ�
    if (!p || j > i) return OUT_OF_RANGE;

    // �����½�㣬ָ���i��λ��
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;

    // ��i-1��λ��ָ��s
    p->next = s;

    ++L->len;

    return OK;
}

/*
 * Function     : ɾ��
 * Description  : �ںϷ���λ��[0, len]ɾ��Ԫ��
 * In           : ����ָ�룬λ��
 * Out          : ״̬
 */
Status LinkedList_Delete(LinkedList *L, int i)
{
    Node *p = L->head, *q;
    int j = 0;  // ʵ��Ϊ�±�+1

    // ֱ��λ��i��ǰһ��λ��
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // ��i-1��Ԫ�ز����ڻ��i��Ԫ�ز����ڻ�i���Ϸ�
    if (!p || !p->next || j > i) return OUT_OF_RANGE;

    q = p->next;
    p->next = q->next;
    free(q);

    --L->len;

    return OK;
}

/*
 * Function     : ��ȡ
 * Description  : �ںϷ���λ��[0, len]��ȡԪ�ص�ֵ
 * In           : ����ָ�룬λ�ã����ص�Ԫ��
 * Out          : ״̬
 */
Status LinkedList_Get(LinkedList L, int i, ElemType *e)
{
    // ָ���һ�����
    Node *p = L.head->next;
    int j = 0;

    // ֱ��λ��i
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // ��i��Ԫ�ز����ڻ�i���Ϸ�
    if (!p || j > i) return OUT_OF_RANGE;

    *e = p->data;

    return OK;
}

/*
 * Function     : ����
 * Description  : �ںϷ���λ��[0, len]����Ԫ�ص�ֵ��������λ��
 * In           : ����ָ�룬�����ҵ�Ԫ��
 * Out          : ״̬
 */
int LinkedList_Find(LinkedList L, ElemType e)
{
    // ָ���һ�����
    Node *p = L.head->next;
    int j = 0;

    // ֱ��λ��i
    while(p && p->data != e)
    {
        p = p->next;
        ++j;
    }

    if (!p) return -1;

    return j;
}

/*
 * Function     : ����
 * Description  : ��ǰ�������δ�ӡԪ�ؼ�Ԫ�صĹ�ϵ
 * In           : ����ָ�룬λ�ã�������Ԫ��
 * Out          : ״̬
 */
void LinkedList_Traverse(LinkedList L)
{
    // ָ���һ�����
    Node *p = L.head->next;
    int j = 0;

    // ѭ��ֱ������
    while(p)
    {
        printf("%d(%d) -> ", p->data, j++);
        p = p->next;
    }

    printf("END\n");
}
