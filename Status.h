/****************************************************************************
 * File name    : Status.h
 * Author       : Alan Liang
 * Description  : ���峣��
 * History      :
 *                v0.1  Alan        2018/08/18 �����ļ�
 ****************************************************************************/

#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

// ��ʼ��������С
#define CAPACITY 10
// ÿ�����ݵĴ�С
#define INCREMENT 10

typedef int ElemType;

// ����״̬
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
