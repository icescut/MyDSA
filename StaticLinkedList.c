/****************************************************************************
 * File name    : StaticLinkedList.c
 * Author       : Alan Liang
 * Description  : ��̬����
 * History      :
 *                v0.1  Alan        2018/09/17 �����ļ�
 ****************************************************************************/

#include <stdio.h>
#include "StaticLinkedList.h"

/*
 * Function     : ��ʼ����̬����
 * Description  : ��ʼ�����пռ䣬ͷ���
 * In           : ��̬����ָ��
 * Out          : ״̬
 */
Status SLinkedList_Init(SLinkedList *L)
{
    // �������пռ�����
    for (int i = 0 ; i < MAXSIZE; ++i)
        L->space[i].next = i + 1;

    // ����ͷ���
    L->space[MAXSIZE-1].next = L->space[1].next = 0;

    L->free = 0;
    L->head = 1;

    L->space[L->free].next = 2;

    L->len = 0;

    return OK;
}

/*
 * Function     : ��ȡ
 * Description  :
 * In           : ��̬����λ�ã���ȡԪ��
 * Out          : ״̬
 */
Status SLinkedList_Get(SLinkedList L, int pos, ElemType *e)
{
    // ��Χ�ж�
    if (pos < 0|| pos >= L.len) return OUT_OF_RANGE;

    int i = L.head;

    // �ƶ���posλ��
    while(i && pos >= 0)
    {
        i = L.space[i].next;
        pos--;
    }

    if (!i) return OUT_OF_RANGE;

    *e = L.space[i].data;

    return OK;
}

/*
 * Function     : ����
 * Description  :
 * In           : ��̬����λ�ã�������Ԫ��
 * Out          : ״̬
 */
Status SLinkedList_Set(SLinkedList *L, int pos, ElemType e)
{
    // ��Χ�ж�
    if (pos < 0|| pos >= L->len) return OUT_OF_RANGE;

    int i = L->head;

    // �ƶ���posλ��
    while(i && pos >= 0)
    {
        i = L->space[i].next;
        pos--;
    }

    if (!i) return OUT_OF_RANGE;

    L->space[i].data = e;

    return OK;
}

/*
 * Function     : ����
 * Description  :
 * In           : ��̬��������Ԫ��
 * Out          : ״̬
 */
int SLinkedList_Find(SLinkedList L, ElemType e)
{
    int i = L.space[L.head].next;
    int j = 0;
    while(i)
    {
        if(L.space[i].data == e) return j;
        i = L.space[i].next;
        ++j;
    }

    return -1;
}

/*
 * Function     : ����
 * Description  :
 * In           : ��̬����ָ�룬λ�ã�������Ԫ��
 * Out          : ״̬
 */
Status SLinkedList_Insert(SLinkedList *L, int pos, ElemType e)
{
    // ��Χ�ж�
    if (pos < 0|| pos > L->len || L->len >= MAXSIZE) return OUT_OF_RANGE;

    int i = L->head, j, k;

    // �õ�����λ��
    k = L->space[L->free].next;
    if(!k) return OUT_OF_RANGE;

    // �ƶ���pos-1λ��
    while(i && pos > 0)
    {
        i = L->space[i].next;
        pos--;
    }
    j = L->space[i].next;

    // freeָ����һ������λ��
    L->space[L->free].next = L->space[k].next;
    // ����Ԫ��ָ��ǰ��posλ��
    L->space[k].data = e;
    L->space[k].next = j;
    //pos-1λ��ָ�����Ԫ��
    L->space[i].next = k;

    ++L->len;

    return OK;
}

/*
 * Function     : ɾ��
 * Description  :
 * In           : ��̬����ָ�룬λ��
 * Out          : ״̬
 */
Status SLinkedList_Delete(SLinkedList *L, int pos)
{
    // ��Χ�ж�
    if (pos < 0|| pos >= L->len) return OUT_OF_RANGE;

    int i = L->head, j, k;

    // �ƶ���pos-1λ��
    while(i && pos > 0)
    {
        i = L->space[i].next;
        pos--;
    }

    if(!i) return OUT_OF_RANGE;

    j = L->space[i].next;

    if(!j) return OUT_OF_RANGE;

    //pos-1λ��ָ��pos+1
    L->space[i].next = L->space[j].next;

    //��posλ�÷���free����ͷ��
    L->space[j].next = L->space[L->free].next;
    L->space[L->free].next = j;

    --L->len;

    return OK;
}

/*
 * Function     : ���س���
 * Description  :
 * In           : ��̬����
 * Out          : int
 */
int SLinkedList_Length(SLinkedList L)
{
    return L.len;
}

/*
 * Function     : �Ƿ�Ϊ��
 * Description  :
 * In           : ��̬����
 * Out          : bool
 */
bool SLinkedList_Is_Empty(SLinkedList L)
{
    return L.len == 0;
}

/*
 * Function     : �������
 * Description  :
 * In           : ��̬����
 * Out          : bool
 */
void SLinkedList_Clear(SLinkedList *L)
{
    while(L->len)
        SLinkedList_Delete(L, 0);
}

/*
 * Function     : ����
 * Description  :
 * In           : ��̬����
 * Out          : void
 */
void SLinkedList_Traverse(SLinkedList L)
{
    printf("����");
    // ��һ�����
    int idx = L.space[L.head].next;
    SNode n;

    while(idx)
    {
        n = L.space[idx];
        printf("%d(%d) -> ", n.data, idx);
        idx = n.next;
    }

    printf("END\n");

    printf("���У�");
    // ��һ�����
    idx = L.space[L.free].next;

    while(idx)
    {
        n = L.space[idx];
        printf("(%d) -> ", idx);
        idx = n.next;
    }
    printf("END\n");
}

/*
 * Function     : �������n��Ԫ�ص�����
 * Description  :
 * In           : ��̬����
 * Out          : ״̬
 */
Status Random_Create_SLinkedList(SLinkedList *L, int n)
{
    int i;
    SLinkedList_Init(L);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        SLinkedList_Insert(L, i, rand() % 100);
    }
    return OK;
}

/*
 * Function     : �������n��Ԫ�ص�����
 * Description  :
 * In           : ��̬������ʾ
 * Out          : ״̬
 */
void SLinkedList_Sample()
{
    SLinkedList L;
    ElemType e;
    bool b;

    printf("# �������10��Ԫ�ص�����\n");
    Random_Create_SLinkedList(&L, 10);
    SLinkedList_Traverse(L);

    printf("\n# �ڵ�5��λ�ò���-5��\n");
    SLinkedList_Insert(&L, 5, -5);
    SLinkedList_Traverse(L);

    printf("\n# ��ͷ������-99��\n");
    SLinkedList_Insert(&L, 0, -99);
    SLinkedList_Traverse(L);

    printf("\n# ��β��������-50��\n");
    SLinkedList_Insert(&L, SLinkedList_Length(L), -50);
    SLinkedList_Traverse(L);

    printf("\n# ɾ����8��λ�ã�\n");
    SLinkedList_Delete(&L, 8);
    SLinkedList_Traverse(L);

    printf("\n# ɾ��ͷ��λ��Ԫ�أ�\n");
    SLinkedList_Delete(&L, 0);
    SLinkedList_Traverse(L);

    printf("\n# ɾ��β��λ��Ԫ�أ�\n");
    SLinkedList_Delete(&L, SLinkedList_Length(L)-1);
    SLinkedList_Traverse(L);

    printf("\n# ��3��λ���ϵ�Ԫ��Ϊ��\n");
    SLinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# ���µ�3��λ���ϵ�Ԫ��Ϊ100��\n");
    SLinkedList_Set(&L, 3, 100);
    SLinkedList_Traverse(L);

    printf("\n# Ԫ��-5��λ��Ϊ��\n");
    printf("%d\n", SLinkedList_Find(L, -5));

    printf("\n# Ԫ��-100�Ƿ���ڣ�\n");
    printf("%s\n", SLinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# ������Ϊ%d\n", SLinkedList_Length(L));

    printf("\n# �������\n");
    SLinkedList_Clear(&L);
    printf("������Ϊ%d\n", SLinkedList_Length(L));
    b = SLinkedList_Is_Empty(L);
    if(b) printf("����Ϊ��\n");
    else printf("����Ϊ��\n");

    printf("\n# ��β��������99��\n");
    SLinkedList_Insert(&L, SLinkedList_Length(L), 99);
    SLinkedList_Traverse(L);
    printf("������Ϊ%d\n", SLinkedList_Length(L));
    b = SLinkedList_Is_Empty(L);
    if(b) printf("����Ϊ��");
    else printf("����Ϊ��");
}
