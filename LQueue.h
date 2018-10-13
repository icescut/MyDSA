/****************************************************************************
 * File name    : LQueue.h
 * Author       : Alan Liang
 * Description  : 队列
 * History      :
 *                v0.1  Alan        2018/10/13 建立文件
 ****************************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include <stdbool.h>
#include <time.h>
#include "Status.h"

typedef struct QNode
{
    ElemType data;      // 数据域
    struct QNode *next;  // 指针域
} QNode;

typedef struct
{
    QNode *head;
    QNode *tail;
    int len;
} LQueue;

// 初始化队列
Status LQueue_Init(LQueue *Q);

// 插入队尾
Status LQueue_Insert(LQueue *Q, ElemType e);

// 删除队头
Status LQueue_Delete(LQueue *Q, ElemType *e);

// 遍历队列
void LQueue_Traverse(LQueue Q);

// 返回队头元素
Status LQueue_Front(LQueue Q, ElemType *e);

// 返回队尾元素
Status LQueue_Back(LQueue Q, ElemType *e);

// 返回长度
int LQueue_Length(LQueue L);

// 是否为空
bool LQueue_Is_Empty(LQueue L);

// 随机建立n个元素的队列
Status Random_Create_LQueue(LQueue *Q, int n);

// 队列演示
void LQueue_Sample();

#endif // LQUEUE_H_INCLUDED
