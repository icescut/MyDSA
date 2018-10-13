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
Status AStack_Push(AStack *S, ElemType e)
{
    if (S->elems == NULL) AStack_Init(S);

    // ����
    if (S->len >= S->size)
    {
        ElemType * new_elems = (ElemType *)realloc(S->elems, (S->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        S->elems = new_elems;
        S->size += INCREMENT;
    }

    S->elems[S->len++] = e;

    return OK;
}

/*
 * Function     : ��ջ
 * Description  :
 * In           : ջ����ջԪ��
 * Out          : ״̬
 */
Status AStack_Pop(AStack *S, ElemType *e)
{
    // ���ջΪ��
    if (S->len == 0) return OUT_OF_RANGE;

    *e = S->elems[S->len-1];

    S->len--;

    return OK;
}

/*
 * Function     : ����ջ��Ԫ��
 * Description  :
 * In           : ջ��ջ��Ԫ��
 * Out          : ״̬
 */
Status AStack_Top(AStack S, ElemType *e)
{
    // ���ջΪ��
    if (S.len == 0) return OUT_OF_RANGE;

    *e = S.elems[S.len-1];

    return OK;
}

/*
 * Function     : ջ�Ƿ�Ϊ��
 * Description  :
 * In           : ջ
 * Out          : bool
 */
bool AStack_Is_Empty(AStack S)
{
    return S.len == 0;
}

/*
 * Function     : ����ջ����
 * Description  :
 * In           : ջ
 * Out          : ����
 */
int AStack_Length(AStack S)
{
    return S.len;
}

/*
 * Function     : ��ӡջ
 * Description  :
 * In           : ջָ��
 * Out          :
 */
void AStack_Traverse(AStack S)
{
    printf("| ");
    for(int i = 0; i < S.len; ++i)
        printf("%d(%d) | ", S.elems[i], i);

    printf("\n");
}

/*
 * Function     : �������n��Ԫ�ص�ջ
 * Description  :
 * In           : ջָ�룬Ԫ�ظ���
 * Out          : ״̬
 */
Status Random_Create_AStack(AStack *S, int n)
{
    int i;
    ArrayList_Init(S);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        AStack_Push(S, rand() % 100);
    }
    return OK;
}

// ջ��ʾ
void AStack_Sample()
{
    AStack S;
    ElemType e;
    printf("# �������3��Ԫ�ص�ջ��\n");
    Random_Create_AStack(&S, 3);
    AStack_Traverse(S);
    printf("ջ�ĳ���Ϊ��%d\n", AStack_Length(S));

    printf("\n# ��-50��ջ��\n");
    AStack_Push(&S, -50);
    AStack_Traverse(S);
    printf("ջ�ĳ���Ϊ��%d\n", AStack_Length(S));

    printf("\n# ��ջ��\n");
    AStack_Pop(&S, &e);
    AStack_Traverse(S);
    printf("��ջԪ��Ϊ��%d\n",e);
    printf("ջ�ĳ���Ϊ��%d\n", AStack_Length(S));
    printf("�ٴγ�ջ��\n");
    AStack_Pop(&S, &e);
    AStack_Traverse(S);
    printf("��ջԪ��Ϊ��%d\n",e);
    printf("ջ�ĳ���Ϊ��%d\n", AStack_Length(S));

    AStack_Top(S, &e);
    printf("\n# ջ��Ԫ��Ϊ��%d\n",e);
    if (AStack_Is_Empty(S) == true)
        printf("\nջΪ��\n");
    else
        printf("\nջ��Ϊ��\n");

    printf("��ջ2�Σ�\n");
    AStack_Pop(&S, &e);
    AStack_Pop(&S, &e);
    if (AStack_Is_Empty(S) == true)
        printf("\nջΪ��\n");
    else
        printf("\nջ��Ϊ��\n");
}
