/****************************************************************************
 * File name    : LQueue.c
 * Author       : Alan Liang
 * Description  : ����
 * History      :
 *                v0.1  Alan        2018/10/13 �����ļ�
 ****************************************************************************/

#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function     : ��ʼ������
 * Description  : ����ͷ��㣬��ʼ������
 * In           : ����ָ��
 * Out          : ״̬
 */
Status LQueue_Init(LQueue *Q)
{
    // ����ͷ���
    Q->head = (QNode *)malloc(sizeof(QNode));
    if (!Q->head) return ERROR;

    // ͷ������һ�����Ϊ��
    Q->head->next = NULL;
    Q->tail = Q->head;

    Q->len = 0;
    return OK;
}

/*
 * Function     : ����
 * Description  : �ڶ�β����Ԫ��
 * In           : ����ָ�룬������Ԫ��
 * Out          : ״̬
 */
Status LQueue_Insert(LQueue *Q, ElemType e)
{
    // �����½��
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;

    // �������ӣ�tailָ��s
    Q->tail->next = s;
    Q->tail = s;

    ++Q->len;

    return OK;
}

/*
 * Function     : ɾ��
 * Description  : �ڶ�ͷɾ��Ԫ��
 * In           : ����ָ�룬ɾ����Ԫ��
 * Out          : ״̬
 */
Status LQueue_Delete(LQueue *Q, ElemType *e)
{
    // �������Ϊ��
    if (!Q->len) return OUT_OF_RANGE;

    // qָ���һ�����
    QNode *q = Q->head->next;
    *e = q->data;

    // headָ��ڶ������
    Q->head->next = q->next;
    --Q->len;

    // �������Ϊ��
    if (!Q->len)
        Q->tail = Q->head;

    free(q);

    return OK;
}

/*
 * Function     : ���ض�ͷԪ��
 * Description  :
 * In           : ���У������ص�Ԫ��
 * Out          : ״̬
 */
Status LQueue_Front(LQueue Q, ElemType *e)
{
    if (Q.len == 0) return OUT_OF_RANGE;

    *e = Q.head->next->data;
    return OK;
}

/*
 * Function     : ���ض�βԪ��
 * Description  :
 * In           : ���У������ص�Ԫ��
 * Out          : ״̬
 */
Status LQueue_Back(LQueue Q, ElemType *e)
{
    if (Q.len == 0) return OUT_OF_RANGE;

    *e = Q.tail->data;
    return OK;
}

/*
 * Function     : ���س���
 * Description  :
 * In           : ����
 * Out          : ����
 */
int LQueue_Length(LQueue Q)
{
    return Q.len;
}

/*
 * Function     : �����Ƿ�Ϊ��
 * Description  : ������п��򷵻�true�����򷵻�false
 * In           : ����
 * Out          : bool
 */
bool LQueue_Is_Empty(LQueue Q)
{
    return Q.len == 0;
}

/*
 * Function     : ����
 * Description  : ��ǰ�������δ�ӡԪ�ؼ�Ԫ�صĹ�ϵ
 * In           : ����
 * Out          : void
 */
void LQueue_Traverse(LQueue Q)
{
    // ָ���һ�����
    QNode *p = Q.head->next;
    int j = 0;

    // ѭ��ֱ������
    while(p)
    {
        printf("%d(%d) -> ", p->data, j++);
        p = p->next;
    }

    printf("END\n");
}

/*
 * Function     : �������n��Ԫ�صĶ���
 * Description  :
 * In           : ���������У�Ԫ�ظ���
 * Out          : ״̬
 */
Status Random_Create_LQueue(LQueue *Q, int n)
{
    int i;
    LQueue_Init(Q);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        LQueue_Insert(Q, rand() % 100);
    }
    return OK;
}

/*
 * Function     : ������ʾ
 * Description  :
 * In           : void
 * Out          : void
 */
void LQueue_Sample()
{
    LQueue Q;
    ElemType e;
    printf("# �������3��Ԫ�صĶ��У�\n");
    Random_Create_LQueue(&Q, 3);
    LQueue_Traverse(Q);
    printf("���г���Ϊ��%d\n", LQueue_Length(Q));

    printf("\n# -50��ӣ�\n");
    LQueue_Insert(&Q, -50);
    LQueue_Traverse(Q);
    printf("���г���Ϊ��%d\n", LQueue_Length(Q));

    printf("\n# ���ӣ�\n");
    LQueue_Delete(&Q, &e);
    LQueue_Traverse(Q);
    printf("ɾ��Ԫ��Ϊ��%d\n", e);
    printf("���г���Ϊ��%d\n", LQueue_Length(Q));

    LQueue_Front(Q, &e);
    printf("\n# ��ͷԪ��Ϊ%d��\n",e);

    LQueue_Back(Q, &e);
    printf("\n# ��βԪ��Ϊ%d��\n",e);

    if (LQueue_Is_Empty(Q) == true)
        printf("\n����Ϊ��\n");
    else
        printf("\n���в�Ϊ��\n");

    printf("����β3�Σ�\n");
    LQueue_Delete(&Q, &e);
    LQueue_Delete(&Q, &e);
    LQueue_Delete(&Q, &e);

    if (LQueue_Is_Empty(Q) == true)
        printf("\n����Ϊ��\n");
    else
        printf("\n���в�Ϊ��\n");

}
