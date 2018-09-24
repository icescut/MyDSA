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
 * Function     : �����һ��Ԫ��
 * Description  :
 * In           : ����ָ�룬������Ԫ��
 * Out          : ״̬
 */
Status LinkedList_InsertFirst(LinkedList *L, ElemType e)
{
    return LinkedList_Insert(L, 0, e);
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
 * Description  : �ںϷ���λ��[0, len]����Ԫ�ص�ֵ
 * In           : ����ָ�룬λ�ã����µ�Ԫ��ֵ
 * Out          : ״̬
 */
Status LinkedList_Set(LinkedList *L, int i, ElemType e)
{
    // ָ���һ�����
    Node *p = L->head->next;
    int j = 0;

    // ֱ��λ��i
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // ��i��Ԫ�ز����ڻ�i���Ϸ�
    if (!p || j > i) return OUT_OF_RANGE;

    p->data = e;

    return OK;
}

/*
 * Function     : �������
 * Description  :
 * In           : ����ָ��
 * Out          :
 */
void LinkedList_Clear(LinkedList *L)
{
    while (L->len > 0)
        LinkedList_Delete(L, 0);
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
 * Function     : ���س���
 * Description  :
 * In           : ����
 * Out          : ����
 */
int LinkedList_Length(LinkedList L)
{
    return L.len;
}

/*
 * Function     : �����Ƿ�Ϊ��
 * Description  : ���������򷵻�true�����򷵻�false
 * In           : ����
 * Out          : bool
 */
bool LinkedList_Is_Empty(LinkedList L)
{
    return L.len == 0;
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

/*
 * Function     : �������n��Ԫ�ص�����
 * Description  :
 * In           : ����������Ԫ�ظ���
 * Out          : ״̬
 */
Status Random_Create_LinkedList(LinkedList *L, int n)
{
    int i;
    LinkedList_Init(L);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        LinkedList_InsertFirst(L, rand() % 100);
    }
    return OK;
}

/*
 * Function     : ������ʾ
 * Description  :
 * In           : void
 * Out          : void
 */
void LinkedList_Sample()
{
    LinkedList L;
    ElemType e;
    bool b;

    printf("# �������10��Ԫ�ص�����\n");
    Random_Create_LinkedList(&L, 10);
    LinkedList_Traverse(L);

    printf("\n# �ڵ�5��λ�ò���-5��\n");
    LinkedList_Insert(&L, 5, -5);
    LinkedList_Traverse(L);

    printf("\n# ��ͷ������-99��\n");
    LinkedList_InsertFirst(&L, -99);
    LinkedList_Traverse(L);

    printf("\n# ��β��������-50��\n");
    LinkedList_Insert(&L, LinkedList_Length(L), -50);
    LinkedList_Traverse(L);

    printf("\n# ɾ����8��λ�ã�\n");
    LinkedList_Delete(&L, 8);
    LinkedList_Traverse(L);

    printf("\n# ɾ��ͷ��λ��Ԫ�أ�\n");
    LinkedList_Delete(&L, 0);
    LinkedList_Traverse(L);

    printf("\n# ɾ��β��λ��Ԫ�أ�\n");
    LinkedList_Delete(&L, LinkedList_Length(L)-1);
    LinkedList_Traverse(L);

    printf("\n# ��3��λ���ϵ�Ԫ��Ϊ��\n");
    LinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# ���µ�3��λ���ϵ�Ԫ��Ϊ100��\n");
    LinkedList_Set(&L, 3, 100);
    LinkedList_Traverse(L);

    printf("\n# Ԫ��-5��λ��Ϊ��\n");
    printf("%d\n", LinkedList_Find(L, -5));

    printf("\n# Ԫ��-100�Ƿ���ڣ�\n");
    printf("%s\n", LinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# ������Ϊ%d\n", LinkedList_Length(L));

    printf("\n# �������\n");
    LinkedList_Clear(&L);
    printf("������Ϊ%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("����Ϊ��\n");
    else printf("����Ϊ��\n");

    printf("\n# ��β��������99��\n");
    LinkedList_Insert(&L, LinkedList_Length(L), 99);
    LinkedList_Traverse(L);
    printf("������Ϊ%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("����Ϊ��");
    else printf("����Ϊ��");
}
