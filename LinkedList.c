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
