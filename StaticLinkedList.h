/****************************************************************************
 * File name    : StaticLinkedList.h
 * Author       : Alan Liang
 * Description  : 静态链表
 * History      :
 *                v0.1  Alan        2018/09/17 建立文件
 ****************************************************************************/

#ifndef STATICLINKEDLIST_H_INCLUDED
#define STATICLINKEDLIST_H_INCLUDED

#include <stdbool.h>
#include <time.h>
#include "Status.h"

#define MAXSIZE 15

typedef struct
{
    ElemType data;
    int next;
} SNode;    // 结点

typedef struct
{
    SNode space[MAXSIZE];   // 结点空间
    int head;               // 头结点
    int free;               // 空闲空间开始结点
    int len;
} SLinkedList;

// 初始化
Status SLinkedList_Init(SLinkedList *L);

// 获取
Status SLinkedList_Get(SLinkedList L, int pos, ElemType *e);

// 更新
Status SLinkedList_Set(SLinkedList *L, int pos, ElemType e);

// 查找
int SLinkedList_Find(SLinkedList L, ElemType e);

// 插入
Status SLinkedList_Insert(SLinkedList *L, int pos, ElemType e);

// 删除
Status SLinkedList_Delete(SLinkedList *L, int pos);

// 返回长度
int SLinkedList_Length(SLinkedList L);

// 是否为空
bool SLinkedList_Is_Empty(SLinkedList L);

// 清空链表
void SLinkedList_Clear(SLinkedList *L);

// 遍历结点
void SLinkedList_Traverse(SLinkedList L);

// 随机建立n个元素的链表
Status Random_Create_SLinkedList(SLinkedList *L, int n);

// 链表演示
void SLinkedList_Sample();

#endif // STATICLINKEDLIST_H_INCLUDED
