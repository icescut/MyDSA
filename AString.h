/****************************************************************************
 * File name    : AString.h
 * Author       : Alan Liang
 * Description  : �ַ�������
 * History      :
 *                v0.1  Alan        2018/10/07 �����ļ�
 ****************************************************************************/

#ifndef ASTRING_H_INCLUDED
#define ASTRING_H_INCLUDED

#include <stdio.h>

//���һ���ַ��Ƿ���Ӣ����ĸ
int isalpha( int ch );

// �����ַ�������
size_t my_strlen(const char *str);

// �Ƚ��ַ���
int my_strcmp(const char *lhs, const char *rhs);

// �����ַ����״γ���
char *my_strchr( const char *str, int ch );

// ����һ���ַ�������һ��
char *my_strcpy( char *dest, const char *src );

// ���������ַ���
char *my_strcat( char *dest, const char *src );

void AString_Sample();


#endif // ASTRING_H_INCLUDED
