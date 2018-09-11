/****************************************************************************
 * File name    : Status.h
 * Author       : Alan Liang
 * Description  : 定义常量
 * History      :
 *                v0.1  Alan        2018/08/18 建立文件
 ****************************************************************************/

#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

// 初始化容量大小
#define CAPACITY 10
// 每次扩容的大小
#define INCREMENT 10

typedef int ElemType;

// 返回状态
typedef enum {
    OK,
    OUT_OF_RANGE,
    ERROR
} Status;

typedef enum {
    APPEND,
    INSERT,
    DELETE,
    UPDATE,
    FIND,
    READ,
    CLEAR = 7,
    QUIT = 9
} Options;

#endif // STATUS_H_INCLUDED
