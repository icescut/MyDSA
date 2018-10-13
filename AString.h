/****************************************************************************
 * File name    : AString.h
 * Author       : Alan Liang
 * Description  : 字符串操作
 * History      :
 *                v0.1  Alan        2018/10/07 建立文件
 ****************************************************************************/

#ifndef ASTRING_H_INCLUDED
#define ASTRING_H_INCLUDED

#include <stdio.h>

//检查一个字符是否是英文字母
int isalpha( int ch );

// 返回字符串长度
size_t my_strlen(const char *str);

// 比较字符串
int my_strcmp(const char *lhs, const char *rhs);

// 查找字符的首次出现
char *my_strchr( const char *str, int ch );

// 复制一个字符串给另一个
char *my_strcpy( char *dest, const char *src );

// 连接两个字符串
char *my_strcat( char *dest, const char *src );

void AString_Sample();


#endif // ASTRING_H_INCLUDED
