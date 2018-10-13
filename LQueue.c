/****************************************************************************
 * File name    : LQueue.c
 * Author       : Alan Liang
 * Description  : 队列
 * History      :
 *                v0.1  Alan        2018/10/13 建立文件
 ****************************************************************************/

#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function     : 初始化队列
 * Description  : 分配头结点，初始化长度
 * In           : 队列指针
 * Out          : 状态
 */
Status LQueue_Init(LQueue *Q)
{
    // 分配头结点
    Q->head = (QNode *)malloc(sizeof(QNode));
    if (!Q->head) return ERROR;

    // 头结点的下一个结点为空
    Q->head->next = NULL;
    Q->tail = Q->head;

    Q->len = 0;
    return OK;
}

/*
 * Function     : 插入
 * Description  : 在队尾插入元素
 * In           : 队列指针，待插入元素
 * Out          : 状态
 */
Status LQueue_Insert(LQueue *Q, ElemType e)
{
    // 分配新结点
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;

    // 建立连接，tail指向s
    Q->tail->next = s;
    Q->tail = s;

    ++Q->len;

    return OK;
}

/*
 * Function     : 删除
 * Description  : 在队头删除元素
 * In           : 队列指针，删除的元素
 * Out          : 状态
 */
Status LQueue_Delete(LQueue *Q, ElemType *e)
{
    // 如果队列为空
    if (!Q->len) return OUT_OF_RANGE;

    // q指向第一个结点
    QNode *q = Q->head->next;
    *e = q->data;

    // head指向第二个结点
    Q->head->next = q->next;
    --Q->len;

    // 如果队列为空
    if (!Q->len)
        Q->tail = Q->head;

    free(q);

    return OK;
}

/*
 * Function     : 返回队头元素
 * Description  :
 * In           : 队列，待返回的元素
 * Out          : 状态
 */
Status LQueue_Front(LQueue Q, ElemType *e)
{
    if (Q.len == 0) return OUT_OF_RANGE;

    *e = Q.head->next->data;
    return OK;
}

/*
 * Function     : 返回队尾元素
 * Description  :
 * In           : 队列，待返回的元素
 * Out          : 状态
 */
Status LQueue_Back(LQueue Q, ElemType *e)
{
    if (Q.len == 0) return OUT_OF_RANGE;

    *e = Q.tail->data;
    return OK;
}

/*
 * Function     : 返回长度
 * Description  :
 * In           : 队列
 * Out          : 长度
 */
int LQueue_Length(LQueue Q)
{
    return Q.len;
}

/*
 * Function     : 队列是否为空
 * Description  : 如果队列空则返回true，否则返回false
 * In           : 队列
 * Out          : bool
 */
bool LQueue_Is_Empty(LQueue Q)
{
    return Q.len == 0;
}

/*
 * Function     : 遍历
 * Description  : 从前往后依次打印元素及元素的关系
 * In           : 队列
 * Out          : void
 */
void LQueue_Traverse(LQueue Q)
{
    // 指向第一个结点
    QNode *p = Q.head->next;
    int j = 0;

    // 循环直到结束
    while(p)
    {
        printf("%d(%d) -> ", p->data, j++);
        p = p->next;
    }

    printf("END\n");
}

/*
 * Function     : 随机建立n个元素的队列
 * Description  :
 * In           : 待建立队列，元素个数
 * Out          : 状态
 */
Status Random_Create_LQueue(LQueue *Q, int n)
{
    int i;
    LQueue_Init(Q);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        LQueue_Insert(Q, rand() % 100);
    }
    return OK;
}

/*
 * Function     : 队列演示
 * Description  :
 * In           : void
 * Out          : void
 */
void LQueue_Sample()
{
    LQueue Q;
    ElemType e;
    printf("# 随机建立3个元素的队列：\n");
    Random_Create_LQueue(&Q, 3);
    LQueue_Traverse(Q);
    printf("队列长度为：%d\n", LQueue_Length(Q));

    printf("\n# -50入队：\n");
    LQueue_Insert(&Q, -50);
    LQueue_Traverse(Q);
    printf("队列长度为：%d\n", LQueue_Length(Q));

    printf("\n# 出队：\n");
    LQueue_Delete(&Q, &e);
    LQueue_Traverse(Q);
    printf("删除元素为：%d\n", e);
    printf("队列长度为：%d\n", LQueue_Length(Q));

    LQueue_Front(Q, &e);
    printf("\n# 队头元素为%d：\n",e);

    LQueue_Back(Q, &e);
    printf("\n# 队尾元素为%d：\n",e);

    if (LQueue_Is_Empty(Q) == true)
        printf("\n队列为空\n");
    else
        printf("\n队列不为空\n");

    printf("出队尾3次：\n");
    LQueue_Delete(&Q, &e);
    LQueue_Delete(&Q, &e);
    LQueue_Delete(&Q, &e);

    if (LQueue_Is_Empty(Q) == true)
        printf("\n队列为空\n");
    else
        printf("\n队列不为空\n");

}
