/****************************************************************************
 * File name    : StaticLinkedList.c
 * Author       : Alan Liang
 * Description  : 静态链表
 * History      :
 *                v0.1  Alan        2018/09/17 建立文件
 ****************************************************************************/

#include <stdio.h>
#include "StaticLinkedList.h"

/*
 * Function     : 初始化静态链表
 * Description  : 初始化空闲空间，头结点
 * In           : 静态链表指针
 * Out          : 状态
 */
Status SLinkedList_Init(SLinkedList *L)
{
    // 建立空闲空间链表
    for (int i = 0 ; i < MAXSIZE; ++i)
        L->space[i].next = i + 1;

    // 建立头结点
    L->space[MAXSIZE-1].next = L->space[1].next = 0;

    L->free = 0;
    L->head = 1;

    L->space[L->free].next = 2;

    L->len = 0;

    return OK;
}

/*
 * Function     : 获取
 * Description  :
 * In           : 静态链表，位置，获取元素
 * Out          : 状态
 */
Status SLinkedList_Get(SLinkedList L, int pos, ElemType *e)
{
    // 范围判断
    if (pos < 0|| pos >= L.len) return OUT_OF_RANGE;

    int i = L.head;

    // 移动到pos位置
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
 * Function     : 更新
 * Description  :
 * In           : 静态链表，位置，待更新元素
 * Out          : 状态
 */
Status SLinkedList_Set(SLinkedList *L, int pos, ElemType e)
{
    // 范围判断
    if (pos < 0|| pos >= L->len) return OUT_OF_RANGE;

    int i = L->head;

    // 移动到pos位置
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
 * Function     : 查找
 * Description  :
 * In           : 静态链表，查找元素
 * Out          : 状态
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
 * Function     : 插入
 * Description  :
 * In           : 静态链表指针，位置，待插入元素
 * Out          : 状态
 */
Status SLinkedList_Insert(SLinkedList *L, int pos, ElemType e)
{
    // 范围判断
    if (pos < 0|| pos > L->len || L->len >= MAXSIZE) return OUT_OF_RANGE;

    int i = L->head, j, k;

    // 得到空闲位置
    k = L->space[L->free].next;
    if(!k) return OUT_OF_RANGE;

    // 移动到pos-1位置
    while(i && pos > 0)
    {
        i = L->space[i].next;
        pos--;
    }
    j = L->space[i].next;

    // free指向下一个空闲位置
    L->space[L->free].next = L->space[k].next;
    // 插入元素指向当前的pos位置
    L->space[k].data = e;
    L->space[k].next = j;
    //pos-1位置指向插入元素
    L->space[i].next = k;

    ++L->len;

    return OK;
}

/*
 * Function     : 删除
 * Description  :
 * In           : 静态链表指针，位置
 * Out          : 状态
 */
Status SLinkedList_Delete(SLinkedList *L, int pos)
{
    // 范围判断
    if (pos < 0|| pos >= L->len) return OUT_OF_RANGE;

    int i = L->head, j, k;

    // 移动到pos-1位置
    while(i && pos > 0)
    {
        i = L->space[i].next;
        pos--;
    }

    if(!i) return OUT_OF_RANGE;

    j = L->space[i].next;

    if(!j) return OUT_OF_RANGE;

    //pos-1位置指向pos+1
    L->space[i].next = L->space[j].next;

    //将pos位置放入free链表头部
    L->space[j].next = L->space[L->free].next;
    L->space[L->free].next = j;

    --L->len;

    return OK;
}

/*
 * Function     : 返回长度
 * Description  :
 * In           : 静态链表
 * Out          : int
 */
int SLinkedList_Length(SLinkedList L)
{
    return L.len;
}

/*
 * Function     : 是否为空
 * Description  :
 * In           : 静态链表
 * Out          : bool
 */
bool SLinkedList_Is_Empty(SLinkedList L)
{
    return L.len == 0;
}

/*
 * Function     : 清空链表
 * Description  :
 * In           : 静态链表
 * Out          : bool
 */
void SLinkedList_Clear(SLinkedList *L)
{
    while(L->len)
        SLinkedList_Delete(L, 0);
}

/*
 * Function     : 遍历
 * Description  :
 * In           : 静态链表
 * Out          : void
 */
void SLinkedList_Traverse(SLinkedList L)
{
    printf("链表：");
    // 第一个结点
    int idx = L.space[L.head].next;
    SNode n;

    while(idx)
    {
        n = L.space[idx];
        printf("%d(%d) -> ", n.data, idx);
        idx = n.next;
    }

    printf("END\n");

    printf("空闲：");
    // 第一个结点
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
 * Function     : 随机建立n个元素的链表
 * Description  :
 * In           : 静态链表
 * Out          : 状态
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
 * Function     : 随机建立n个元素的链表
 * Description  :
 * In           : 静态链表演示
 * Out          : 状态
 */
void SLinkedList_Sample()
{
    SLinkedList L;
    ElemType e;
    bool b;

    printf("# 随机建立10个元素的链表：\n");
    Random_Create_SLinkedList(&L, 10);
    SLinkedList_Traverse(L);

    printf("\n# 在第5个位置插入-5：\n");
    SLinkedList_Insert(&L, 5, -5);
    SLinkedList_Traverse(L);

    printf("\n# 在头部插入-99：\n");
    SLinkedList_Insert(&L, 0, -99);
    SLinkedList_Traverse(L);

    printf("\n# 在尾部部插入-50：\n");
    SLinkedList_Insert(&L, SLinkedList_Length(L), -50);
    SLinkedList_Traverse(L);

    printf("\n# 删除第8个位置：\n");
    SLinkedList_Delete(&L, 8);
    SLinkedList_Traverse(L);

    printf("\n# 删除头部位置元素：\n");
    SLinkedList_Delete(&L, 0);
    SLinkedList_Traverse(L);

    printf("\n# 删除尾部位置元素：\n");
    SLinkedList_Delete(&L, SLinkedList_Length(L)-1);
    SLinkedList_Traverse(L);

    printf("\n# 第3个位置上的元素为：\n");
    SLinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# 更新第3个位置上的元素为100：\n");
    SLinkedList_Set(&L, 3, 100);
    SLinkedList_Traverse(L);

    printf("\n# 元素-5的位置为：\n");
    printf("%d\n", SLinkedList_Find(L, -5));

    printf("\n# 元素-100是否存在？\n");
    printf("%s\n", SLinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# 链表长度为%d\n", SLinkedList_Length(L));

    printf("\n# 清空链表\n");
    SLinkedList_Clear(&L);
    printf("链表长度为%d\n", SLinkedList_Length(L));
    b = SLinkedList_Is_Empty(L);
    if(b) printf("链表为空\n");
    else printf("链表不为空\n");

    printf("\n# 在尾部部插入99：\n");
    SLinkedList_Insert(&L, SLinkedList_Length(L), 99);
    SLinkedList_Traverse(L);
    printf("链表长度为%d\n", SLinkedList_Length(L));
    b = SLinkedList_Is_Empty(L);
    if(b) printf("链表为空");
    else printf("链表不为空");
}
