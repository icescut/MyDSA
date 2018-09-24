/****************************************************************************
 * File name    : LinkedList.h
 * Author       : Alan Liang
 * Description  : 链表
 * History      :
 *                v0.1  Alan        2018/08/22 建立文件
 ****************************************************************************/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>
#include <time.h>
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

// 插入第一个元素
Status LinkedList_InsertFirst(LinkedList *L, ElemType e);

// 删除
Status LinkedList_Delete(LinkedList *L, int i);

// 获取某位置上的元素
Status LinkedList_Get(LinkedList L, int i, ElemType *e);

// 更新某位置上的元素
Status LinkedList_Set(LinkedList *L, int i, ElemType e);

// 查找某个元素的第一个出现位置
int LinkedList_Find(LinkedList L, ElemType e);

// 清空链表
void LinkedList_Clear(LinkedList *L);

// 返回长度
int LinkedList_Length(LinkedList L);

// 是否为空
bool LinkedList_Is_Empty(LinkedList L);

// 遍历
void LinkedList_Traverse(LinkedList L);

// 随机建立n个元素的链表
Status Random_Create_LinkedList(LinkedList *L, int n);

// 链表演示
void LinkedList_Sample();

#endif // LINKEDLIST_H_INCLUDED
