/****************************************************************************
 * File name    : ArrayList.c
 * Author       : Alan Liang
 * Description  : ���Ա�
 * History      :
 *                v0.1  Alan        2018/08/18 �����ļ�
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

/*
 * Function     : ��ʼ�����Ա�
 * Description  : ���Ա�����ڴ�ռ䣬��ʼ������
 * In           : ���Ա�ָ��
 * Out          : ״̬
 */
Status ArrayList_Init(ArrayList *L)
{
    // �����ڴ�ռ�
    L->elems = (ElemType *)malloc(sizeof(ElemType) * CAPACITY);
    if (L->elems == NULL) return ERROR;

    // ��ʼ��������Ԫ�ظ���
    L->size = CAPACITY;
    L->len = 0;
    return OK;
}

/*
 * Function     : ��ĩβ����Ԫ��
 * Description  : ���û�пռ䣬���ݡ���ĩβ����Ԫ��
 * In           : ���Ա�ָ�룬������Ԫ��
 * Out          : ״̬
 */
Status ArrayList_Append(ArrayList *L, ElemType e)
{
    return ArrayList_Insert(L, L->len, e);
}

/*
 * Function     : ���м����Ԫ��
 * Description  : ���û�пռ䣬���ݡ���󵽲���λ�õ�Ԫ�����κ���һλ���ڲ���λ�÷��ô�����Ԫ��
 *                �ɲ���λ��Ϊ[0, len]
 * In           : ���Ա�ָ�룬������λ�ã�������Ԫ��
 * Out          : ״̬
 */
Status ArrayList_Insert(ArrayList *L, int pos, ElemType e)
{
    ElemType * new_elems;

    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos > L->len) return OUT_OF_RANGE;

    if (L->elems == NULL) ArrayList_Init(L);

    // ����
    if (L->len >= L->size)
    {
        new_elems = (ElemType *)realloc(L->elems, (L->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        L->elems = new_elems;
        L->size += INCREMENT;
    }

    // ��󵽲���λ�õ�Ԫ�����κ���һλ
    for (int i = L->len - 1; i >= pos; --i)
    {
        L->elems[i+1] = L->elems[i];
    }

    // �ڲ���λ�÷��ô�����Ԫ��
    L->elems[pos] = e;

    L->len++;

    return OK;
}

/*
 * Function     : ���м�ɾ��һ��Ԫ��
 * Description  : ɾ��λ��+1������Ԫ������ǰ��һλ
 *                ��ɾ��λ��Ϊ[0, len)
 * In           : ���Ա�ָ�룬��ɾ��λ��
 * Out          : ״̬
 */
Status ArrayList_Delete(ArrayList *L, int pos)
{
    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos >= L->len) return OUT_OF_RANGE;

    // ɾ��λ��+1������Ԫ������ǰ��һλ
    for (int i = pos+1; i < L->len; ++i)
    {
        L->elems[i-1] = L->elems[i];
    }

    L->len--;

    return OK;
}

/*
 * Function     : ��ȡĳλ���ϵ�Ԫ��
 * Description  : ʹ���±������
 * In           : ���Ա�λ�ã������Ԫ�صı���
 * Out          : ״̬
 */
Status ArrayList_Get(ArrayList L, int pos, ElemType *e)
{
    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos >= L.len) return OUT_OF_RANGE;
    *e = L.elems[pos];
    return OK;
}

/*
 * Function     : ����ĳλ���ϵ�Ԫ��
 * Description  : ʹ���±������
 * In           : ���Ա�ָ�룬λ�ã�������ֵ
 * Out          : ״̬
 */
Status ArrayList_Set(ArrayList *L, int pos, ElemType e)
{
    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos >= L->len) return OUT_OF_RANGE;
    L->elems[pos] = e;
    return OK;
}

/*
 * Function     : ����ĳ��Ԫ�صĵ�һ������λ��
 * Description  :
 * In           : ���Ա�������Ԫ��
 * Out          : ״̬
 */
int ArrayList_Find(ArrayList L, ElemType e)
{
    for (int i = 0; i < L.len; ++i)
    {
        if (L.elems[i] == e) return i;
    }
    return -1;
}

/*
 * Function     : ������Ա�
 * Description  :
 * In           : ���Ա�ָ��
 * Out          : void
 */
void ArrayList_Clear(ArrayList *L)
{
    if (L->elems) free(L->elems);
    L->elems = NULL;
    L->len = 0;
    L->size = 0;
}

/*
 * Function     : �ж����Ա��Ƿ�Ϊ��
 * Description  :
 * In           : ���Ա�
 * Out          : true / false
 */
bool ArrayList_Is_Empty(ArrayList L)
{
    return L.len ? true : false;
}

/*
 * Function     : �������Ա�ĳ���
 * Description  :
 * In           : ���Ա�
 * Out          : ���Ա�ĳ���
 */
int ArrayList_Length(ArrayList L)
{
    return L.len;
}

/*
 * Function     : ��ӡ���Ա�
 * Description  :
 * In           : ���Ա�
 */
void ArrayList_Traverse(ArrayList L)
{
    printf("| ");
    for(int i = 0; i < L.len; ++i)
        printf("%d(%d) | ", L.elems[i], i);

    printf("\n");
}
