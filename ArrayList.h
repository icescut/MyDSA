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
#include "Status.h"

typedef int ElemType;

typedef struct {
    ElemType *elems;    // 数组
    int len;            // 元素个数
    int size;           // 容量
} ArrayList;

// 初始化线性表
Status Init(ArrayList *L);

// 在线性表最后插入一个元素
Status Append(ArrayList *L, ElemType e);

// 在线性表中间插入一个元素
Status Insert(ArrayList *L, int pos, ElemType e);

// 在线性表中间删除一个元素
Status Delete(ArrayList *L, int pos);

// 获取某位置上的元素
Status Get(ArrayList L, int pos, ElemType *e);

// 设置某位置上的元素
Status Set(ArrayList *L, int pos, ElemType e);

// 查找某个元素的第一个出现位置
int Find(ArrayList L, ElemType e);

// 清空线性表
void Clear(ArrayList *L);

// 判断线性表是否为空
bool Is_Empty(ArrayList L);

// 返回线性表的长度
int Length(ArrayList L);

// 打印列表
void Traverse(ArrayList L);

#endif // ARRAYLIST_H_INCLUDED
