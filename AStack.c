/****************************************************************************
 * File name    : AStack.c
 * Author       : Alan Liang
 * Description  : ���Ա�
 * History      :
 *                v0.1  Alan        2018/09/24 �����ļ�
 ****************************************************************************/

#include "AStack.h"

 /*
 * Function     : ��ʼ��ջ
 * Description  :
 * In           : ջָ��
 * Out          : ״̬
 */
Status AStack_Init(AStack *S)
{
    // �����ڴ�ռ�
    S->elems = (ElemType *)malloc(sizeof(ElemType) * CAPACITY);
    if (S->elems == NULL) return ERROR;

    // ��ʼ��������Ԫ�ظ���
    S->size = CAPACITY;
    S->len = 0;
    return OK;
}

/*
 * Function     : ��ջ
 * Description  : ���û�пռ䣬���ݡ�
 * In           : ���Ա�ָ�룬������Ԫ��
 * Out          : ״̬
 */
Status AStack_Insert(AStack *L, ElemType e)
{
    /*
    ElemType * new_elems;

    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos > L->len) return OUT_OF_RANGE;

    if (L->elems == NULL) AStack_Init(L);

    // ����
    if (L->len >= L->size)
    {
        new_elems = (ElemType *)realloc(L->elems, (L->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        L->elems = new_elems;
        L->size += INCREMENT;
    }

    L->elems[L->len++] = e;

    return OK;
    */
}

/*
 * Function     : ��ջ
 * Description  : ���û�пռ䣬���ݡ�
 * In           : ���Ա�ָ�룬������Ԫ��
 * Out          : ״̬
 */
Status Random_Create_AStack(AStack *L, int n);

// ���Ա���ʾ
void AStack_Sample();
