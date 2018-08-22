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
Status Init(ArrayList *L)
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
Status Append(ArrayList *L, ElemType e)
{
    return Insert(L, L->len, e);
}

/*
 * Function     : ���м����Ԫ��
 * Description  : ���û�пռ䣬���ݡ���󵽲���λ�õ�Ԫ�����κ���һλ���ڲ���λ�÷��ô�����Ԫ��
 *                �ɲ���λ��Ϊ[0, len]
 * In           : ���Ա�ָ�룬������λ�ã�������Ԫ��
 * Out          : ״̬
 */
Status Insert(ArrayList *L, int pos, ElemType e)
{
    ElemType * new_elems;

    // �ж�λ���Ƿ�Ϸ�
    if (pos < 0 || pos > L->len) return OUT_OF_RANGE;

    if (L->elems == NULL) Init(L);

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
Status Delete(ArrayList *L, int pos)
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
Status Get(ArrayList L, int pos, ElemType *e)
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
Status Set(ArrayList *L, int pos, ElemType e)
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
int Find(ArrayList L, ElemType e)
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
void Clear(ArrayList *L)
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
bool Is_Empty(ArrayList L)
{
    if (L.len) return true;
    return false;
}

/*
 * Function     : �������Ա�ĳ���
 * Description  :
 * In           : ���Ա�
 * Out          : ���Ա�ĳ���
 */
int Length(ArrayList L)
{
    return L.len;
}

/*
 * Function     : ��ӡ���Ա�
 * Description  :
 * In           : ���Ա�
 */
void Traverse(ArrayList L)
{
    int len = 11 + 3 * L.len;
    for (int i = 0; i < len; ++i)
        printf("-");

    // TODO �ж�Ԫ�ص�λ��
    printf("\n|position |");
    for (int i = 0; i < L.len; ++i)
    {
        printf("%2d|", i);
    }
    //��ӡ����
    printf("\n|list (%2d)|", L.len);
    for (int i = 0; i < L.len; ++i)
    {
        printf("%2d|", L.elems[i]);
    }
    printf("\n");
    for (int i = 0; i < len; ++i)
        printf("-");
    printf("\n\n");
}
