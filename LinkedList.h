/****************************************************************************
 * File name    : LinkedList.h
 * Author       : Alan Liang
 * Description  : 链表
 * History      :
 *                v0.1  Alan        2018/08/22 建立文件
 ****************************************************************************/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Status.h"

typedef struct Node
{
    ElemType data;      // 数据域
    struct Node *next;  // 指针域
} Node;

typedef struct
{
    Node *head;
    int len;
} LinkedList;

// 初始化链表
Status LinkedList_Init(LinkedList *L);

// 插入
Status LinkedList_Insert(LinkedList *L, int i, ElemType e);

// 删除
Status LinkedList_Delete(LinkedList *L, int i);

// 获取某位置上的元素
Status LinkedList_Get(LinkedList L, int i, ElemType *e);

// 查找某个元素的第一个出现位置
int LinkedList_Find(LinkedList L, ElemType e);

// 遍历
void LinkedList_Traverse(LinkedList L);

#endif // LINKEDLIST_H_INCLUDED
