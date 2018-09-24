/****************************************************************************
 * File name    : ArrayList.h
 * Author       : Alan Liang
 * Description  : 线性表
 * History      :
 *                v0.1  Alan        2018/08/18 建立文件
 ****************************************************************************/

#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include <stdbool.h>
#include <time.h>
#include "Status.h"

typedef struct
{
    ElemType *elems;    // 数组
    int len;            // 元素个数
    int size;           // 容量
} ArrayList;

// 初始化线性表
Status ArrayList_Init(ArrayList *L);

// 在线性表最后插入一个元素
Status ArrayList_Append(ArrayList *L, ElemType e);

// 在线性表中间插入一个元素
Status ArrayList_Insert(ArrayList *L, int pos, ElemType e);

// 在线性表中间删除一个元素
Status ArrayList_Delete(ArrayList *L, int pos);

// 获取某位置上的元素
Status ArrayList_Get(ArrayList L, int pos, ElemType *e);

// 设置某位置上的元素
Status ArrayList_Set(ArrayList *L, int pos, ElemType e);

// 查找某个元素的第一个出现位置
int ArrayList_Find(ArrayList L, ElemType e);

// 清空线性表
void ArrayList_Clear(ArrayList *L);

// 判断线性表是否为空
bool ArrayList_Is_Empty(ArrayList L);

// 返回线性表的长度
int ArrayList_Length(ArrayList L);

// 打印列表
void ArrayList_Traverse(ArrayList L);

// 随机建立n个元素的线性表
Status Random_Create_ArrayList(ArrayList *L, int n);

// 线性表演示
void ArrayList_Sample();

#endif // ARRAYLIST_H_INCLUDED
