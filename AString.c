/****************************************************************************
 * File name    : AString.c
 * Author       : Alan Liang
 * Description  : 字符串操作
 * History      :
 *                v0.1  Alan        2018/10/07 建立文件
 ****************************************************************************/

#include <stdlib.h>
#include "AString.h"

/*
 * Function     : 连接两个字符串
 * Description  :
 * In           : 目标字符串，来源字符串
 * Out          : 目标字符串的副本
 */
char *my_strcat( char *dest, const char *src )
{
    char *res = dest;
    // 循环直到\0
    while(*dest != '\0') dest++;

    while((*dest++ = *src++) != '\0');

    return res;
}

/*
 * Function     : 复制一个字符串给另一个
 * Description  :
 * In           : 目标字符串，来源字符串
 * Out          : 目标字符串的副本
 */
char *my_strcpy(char *dest, const char *src)
{
    char *res = dest;
    while((*dest++ = *src++) != '\0');
    return res;
}

/*
 * Function     : 查找字符的首次出现
 * Description  : 如果没有找到，则返回NULL
 * In           : 字符串，查找字符
 * Out          : 字符指针
 */
char *my_strchr(const char *str, int ch)
{
    while(*str != '\0' && *str != ch) str++;

    if(*str == ch) return str;
    else return NULL;
}

/*
 * Function     : 返回字符串长度
 * Description  : 不包含'\0'在内
 * In           : 字符串
 * Out          : 长度
 */
size_t my_strlen(const char *str)
{
    size_t len = 0;
    while(*str++)len++;
    return len;
}

/*
 * Function     : 比较字符串
 * Description  : 结果的符号是被比较的字符串中首对不同字符的值间的差的符号
 * In           : 字符串
 * Out          : 比较结果
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
