/****************************************************************************
 * File name    : AStack.c
 * Author       : Alan Liang
 * Description  : 线性表
 * History      :
 *                v0.1  Alan        2018/09/24 建立文件
 ****************************************************************************/

#include "AStack.h"

 /*
 * Function     : 初始化栈
 * Description  :
 * In           : 栈指针
 * Out          : 状态
 */
Status AStack_Init(AStack *S)
{
    // 分配内存空间
    S->elems = (ElemType *)malloc(sizeof(ElemType) * CAPACITY);
    if (S->elems == NULL) return ERROR;

    // 初始化容量和元素个数
    S->size = CAPACITY;
    S->len = 0;
    return OK;
}

/*
 * Function     : 入栈
 * Description  : 如果没有空间，扩容。
 * In           : 线性表指针，待插入元素
 * Out          : 状态
 */
Status AStack_Push(AStack *S, ElemType e)
{
    if (S->elems == NULL) AStack_Init(S);

    // 扩容
    if (S->len >= S->size)
    {
        ElemType * new_elems = (ElemType *)realloc(S->elems, (S->size + INCREMENT) * sizeof(ElemType));
        if (new_elems == NULL) return ERROR;

        S->elems = new_elems;
        S->size += INCREMENT;
    }

    S->elems[S->len++] = e;

    return OK;
}

/*
 * Function     : 出栈
 * Description  :
 * In           : 栈，出栈元素
 * Out          : 状态
 */
Status AStack_Pop(AStack *S, ElemType *e)
{
    // 如果栈为空
    if (S->len == 0) return OUT_OF_RANGE;

    *e = S->elems[S->len-1];

    S->len--;

    return OK;
}

/*
 * Function     : 返回栈顶元素
 * Description  :
 * In           : 栈，栈顶元素
 * Out          : 状态
 */
Status AStack_Top(AStack S, ElemType *e)
{
    // 如果栈为空
    if (S.len == 0) return OUT_OF_RANGE;

    *e = S.elems[S.len-1];

    return OK;
}

/*
 * Function     : 栈是否为空
 * Description  :
 * In           : 栈
 * Out          : bool
 */
bool AStack_Is_Empty(AStack S)
{
    return S.len == 0;
}

/*
 * Function     : 返回栈长度
 * Description  :
 * In           : 栈
 * Out          : 长度
 */
int AStack_Length(AStack S)
{
    return S.len;
}

/*
 * Function     : 打印栈
 * Description  :
 * In           : 栈指针
 * Out          :
 */
void AStack_Traverse(AStack S)
{
    printf("| ");
    for(int i = 0; i < S.len; ++i)
        printf("%d(%d) | ", S.elems[i], i);

    printf("\n");
}

/*
 * Function     : 随机建立n个元素的栈
 * Description  :
 * In           : 栈指针，元素个数
 * Out          : 状态
 */
Status Random_Create_AStack(AStack *S, int n)
{
    int i;
    ArrayList_Init(S);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        AStack_Push(S, rand() % 100);
    }
    return OK;
}

// 栈演示
void AStack_Sample()
{
    AStack S;
    ElemType e;
    printf("# 随机建立3个元素的栈：\n");
    Random_Create_AStack(&S, 3);
    AStack_Traverse(S);
    printf("栈的长度为：%d\n", AStack_Length(S));

    printf("\n# 将-50入栈：\n");
    AStack_Push(&S, -50);
    AStack_Traverse(S);
    printf("栈的长度为：%d\n", AStack_Length(S));

    printf("\n# 出栈：\n");
    AStack_Pop(&S, &e);
    AStack_Traverse(S);
    printf("出栈元素为：%d\n",e);
    printf("栈的长度为：%d\n", AStack_Length(S));
    printf("再次出栈：\n");
    AStack_Pop(&S, &e);
    AStack_Traverse(S);
    printf("出栈元素为：%d\n",e);
    printf("栈的长度为：%d\n", AStack_Length(S));

    AStack_Top(S, &e);
    printf("\n# 栈顶元素为：%d\n",e);
    if (AStack_Is_Empty(S) == true)
        printf("\n栈为空\n");
    else
        printf("\n栈不为空\n");

    printf("出栈2次：\n");
    AStack_Pop(&S, &e);
    AStack_Pop(&S, &e);
    if (AStack_Is_Empty(S) == true)
        printf("\n栈为空\n");
    else
        printf("\n栈不为空\n");
}
