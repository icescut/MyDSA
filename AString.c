/****************************************************************************
 * File name    : AString.c
 * Author       : Alan Liang
 * Description  : �ַ�������
 * History      :
 *                v0.1  Alan        2018/10/07 �����ļ�
 ****************************************************************************/

#include <stdlib.h>
#include "AString.h"

/*
 * Function     : ���������ַ���
 * Description  :
 * In           : Ŀ���ַ�������Դ�ַ���
 * Out          : Ŀ���ַ����ĸ���
 */
char *my_strcat( char *dest, const char *src )
{
    char *res = dest;
    // ѭ��ֱ��\0
    while(*dest != '\0') dest++;

    while((*dest++ = *src++) != '\0');

    return res;
}

/*
 * Function     : ����һ���ַ�������һ��
 * Description  :
 * In           : Ŀ���ַ�������Դ�ַ���
 * Out          : Ŀ���ַ����ĸ���
 */
char *my_strcpy(char *dest, const char *src)
{
    char *res = dest;
    while((*dest++ = *src++) != '\0');
    return res;
}

/*
 * Function     : �����ַ����״γ���
 * Description  : ���û���ҵ����򷵻�NULL
 * In           : �ַ����������ַ�
 * Out          : �ַ�ָ��
 */
char *my_strchr(const char *str, int ch)
{
    while(*str != '\0' && *str != ch) str++;

    if(*str == ch) return str;
    else return NULL;
}

/*
 * Function     : �����ַ�������
 * Description  : ������'\0'����
 * In           : �ַ���
 * Out          : ����
 */
size_t my_strlen(const char *str)
{
    size_t len = 0;
    while(*str++)len++;
    return len;
}

/*
 * Function     : �Ƚ��ַ���
 * Description  : ����ķ����Ǳ��Ƚϵ��ַ������׶Բ�ͬ�ַ���ֵ��Ĳ�ķ���
 * In           : �ַ���
 * Out          : �ȽϽ��
 */
int my_strcmp(const char *lhs, const char *rhs)
{
    size_t llen = strlen(lhs);
    size_t rlen = strlen(rhs);

    for(;;lhs++, rhs++)
    {
        if(*lhs != *rhs) return *lhs - *rhs;
    }
    return llen - rlen;
}

void AString_Sample()
{
    const char str[] = "How many characters does this string contain?";

    printf("# strlen:\n");
    printf("origin string:\n%s\n", str);
    printf("without null character: %d\n", my_strlen(str));
    printf("with null character:    %d\n", sizeof str);

    printf("# strcmp:\n");
    const char str1[] = "Hello world";
    const char str2[] = "Hello man";
    printf("origin string:\n%s\n%s\n", str1, str2);
    printf("%d\n", my_strcmp(str1, str2));

    printf("# strchr:\n");
    if(my_strchr(str1, 'e') != NULL)
        printf("Found 'e' in 'Hello world'\n");
    else
        printf("Not found 'e' in 'Hello world'\n");

    if(my_strchr(str1, 'z') != NULL)
        printf("Found 'z' in 'Hello world'\n");
    else
        printf("Not found 'z' in 'Hello world'\n");

    printf("# strcpy:\n");
    char dst[my_strlen(str1)+1];
    my_strcpy(dst, str1);
    printf("source:%s\n",str1);
    printf("dest  :%s\n",dst);

    printf("# strcat:\n");
    char str3[50] = "Hello ";
    char str4[50] = "World!";
    printf("origin string:\n%s\n%s\n", str3, str4);
    my_strcat(str3, str4);
    printf("dest string:\n%s\n", str3);
}
