/****************************************************************************
 * File name    : LinkedList.c
 * Author       : Alan Liang
 * Description  : 链表
 * History      :
 *                v0.1  Alan        2018/08/22 建立文件
 ****************************************************************************/

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function     : 初始化链表
 * Description  : 分配头结点，初始化长度
 * In           : 链表指针
 * Out          : 状态
 */
Status LinkedList_Init(LinkedList *L)
{
    // 分配头结点
    L->head = (Node *)malloc(sizeof(Node));
    if (!L->head) return ERROR;
    // 头结点的下一个结点为空
    L->head->next = NULL;

    L->len = 0;
    return OK;
}

/*
 * Function     : 插入
 * Description  : 在合法的位置[0, len]插入元素
 * In           : 链表指针，位置，待插入元素
 * Out          : 状态
 */
Status LinkedList_Insert(LinkedList *L, int i, ElemType e)
{
    Node *p = L->head;
    int j = 0;  // 实际为下标+1

    // 直到位置i的前一个位置
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // 第i-1个元素不存在或i不合法
    if (!p || j > i) return OUT_OF_RANGE;

    // 分配新结点，指向第i个位置
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;

    // 第i-1个位置指向s
    p->next = s;

    ++L->len;

    return OK;
}

/*
 * Function     : 插入第一个元素
 * Description  :
 * In           : 链表指针，待插入元素
 * Out          : 状态
 */
Status LinkedList_InsertFirst(LinkedList *L, ElemType e)
{
    return LinkedList_Insert(L, 0, e);
}

/*
 * Function     : 删除
 * Description  : 在合法的位置[0, len]删除元素
 * In           : 链表指针，位置
 * Out          : 状态
 */
Status LinkedList_Delete(LinkedList *L, int i)
{
    Node *p = L->head, *q;
    int j = 0;  // 实际为下标+1

    // 直到位置i的前一个位置
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // 第i-1个元素不存在或第i个元素不存在或i不合法
    if (!p || !p->next || j > i) return OUT_OF_RANGE;

    q = p->next;
    p->next = q->next;
    free(q);

    --L->len;

    return OK;
}

/*
 * Function     : 获取
 * Description  : 在合法的位置[0, len]获取元素的值
 * In           : 链表指针，位置，返回的元素
 * Out          : 状态
 */
Status LinkedList_Get(LinkedList L, int i, ElemType *e)
{
    // 指向第一个结点
    Node *p = L.head->next;
    int j = 0;

    // 直到位置i
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // 第i个元素不存在或i不合法
    if (!p || j > i) return OUT_OF_RANGE;

    *e = p->data;

    return OK;
}

/*
 * Function     : 更新
 * Description  : 在合法的位置[0, len]更新元素的值
 * In           : 链表指针，位置，更新的元素值
 * Out          : 状态
 */
Status LinkedList_Set(LinkedList *L, int i, ElemType e)
{
    // 指向第一个结点
    Node *p = L->head->next;
    int j = 0;

    // 直到位置i
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }

    // 第i个元素不存在或i不合法
    if (!p || j > i) return OUT_OF_RANGE;

    p->data = e;

    return OK;
}

/*
 * Function     : 清空链表
 * Description  :
 * In           : 链表指针
 * Out          :
 */
void LinkedList_Clear(LinkedList *L)
{
    while (L->len > 0)
        LinkedList_Delete(L, 0);
}

/*
 * Function     : 查找
 * Description  : 在合法的位置[0, len]查找元素的值，并返回位置
 * In           : 链表指针，待查找的元素
 * Out          : 状态
 */
int LinkedList_Find(LinkedList L, ElemType e)
{
    // 指向第一个结点
    Node *p = L.head->next;
    int j = 0;

    // 直到位置i
    while(p && p->data != e)
    {
        p = p->next;
        ++j;
    }

    if (!p) return -1;

    return j;
}

/*
 * Function     : 返回长度
 * Description  :
 * In           : 链表
 * Out          : 长度
 */
int LinkedList_Length(LinkedList L)
{
    return L.len;
}

/*
 * Function     : 链表是否为空
 * Description  : 如果链表空则返回true，否则返回false
 * In           : 链表
 * Out          : bool
 */
bool LinkedList_Is_Empty(LinkedList L)
{
    return L.len == 0;
}

/*
 * Function     : 遍历
 * Description  : 从前往后依次打印元素及元素的关系
 * In           : 链表指针，位置，待插入元素
 * Out          : 状态
 */
void LinkedList_Traverse(LinkedList L)
{
    // 指向第一个结点
    Node *p = L.head->next;
    int j = 0;

    // 循环直到结束
    while(p)
    {
        printf("%d(%d) -> ", p->data, j++);
        p = p->next;
    }

    printf("END\n");
}

/*
 * Function     : 随机建立n个元素的链表
 * Description  :
 * In           : 待建立链表，元素个数
 * Out          : 状态
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
 * Function     : 链表演示
 * Description  :
 * In           : void
 * Out          : void
 */
void LinkedList_Sample()
{
    LinkedList L;
    ElemType e;
    bool b;

    printf("# 随机建立10个元素的链表：\n");
    Random_Create_LinkedList(&L, 10);
    LinkedList_Traverse(L);

    printf("\n# 在第5个位置插入-5：\n");
    LinkedList_Insert(&L, 5, -5);
    LinkedList_Traverse(L);

    printf("\n# 在头部插入-99：\n");
    LinkedList_InsertFirst(&L, -99);
    LinkedList_Traverse(L);

    printf("\n# 在尾部部插入-50：\n");
    LinkedList_Insert(&L, LinkedList_Length(L), -50);
    LinkedList_Traverse(L);

    printf("\n# 删除第8个位置：\n");
    LinkedList_Delete(&L, 8);
    LinkedList_Traverse(L);

    printf("\n# 删除头部位置元素：\n");
    LinkedList_Delete(&L, 0);
    LinkedList_Traverse(L);

    printf("\n# 删除尾部位置元素：\n");
    LinkedList_Delete(&L, LinkedList_Length(L)-1);
    LinkedList_Traverse(L);

    printf("\n# 第3个位置上的元素为：\n");
    LinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# 更新第3个位置上的元素为100：\n");
    LinkedList_Set(&L, 3, 100);
    LinkedList_Traverse(L);

    printf("\n# 元素-5的位置为：\n");
    printf("%d\n", LinkedList_Find(L, -5));

    printf("\n# 元素-100是否存在？\n");
    printf("%s\n", LinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# 链表长度为%d\n", LinkedList_Length(L));

    printf("\n# 清空链表\n");
    LinkedList_Clear(&L);
    printf("链表长度为%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("链表为空\n");
    else printf("链表不为空\n");

    printf("\n# 在尾部部插入99：\n");
    LinkedList_Insert(&L, LinkedList_Length(L), 99);
    LinkedList_Traverse(L);
    printf("链表长度为%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("链表为空");
    else printf("链表不为空");
}
