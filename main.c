#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Status.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "cs50.h"

// 随机建立n个元素的线性表
Status Random_Create_ArrayList(ArrayList *L, int n);

// 随机建立n个元素的链表
Status Random_Create_LinkedList(LinkedList *L, int n);

// 线性表演示
void ArrayList_Sample();

// 链表演示
void LinkedList_Sample();

int main()
{
    ArrayList_Sample();
    // LinkedList_Sample();

    return 0;
}

/*
 * Function     : 随机建立n个元素的线性表
 * Description  :
 * In           : 待建立线性表，元素个数
 * Out          : 状态
 */
Status Random_Create_ArrayList(ArrayList *L, int n)
{
    int i;
    ArrayList_Init(L);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        ArrayList_Append(L, rand() % 100);
    }
    return OK;
}

/*
 * Function     : 随机建立n个元素的链表
 * Description  :
 * In           : 待建立链表，元素个数
 * Out          : 状态
 */
Status Random_Create_LinkedList(LinkedList *L, int n)
{
    int i;
    LinkedList_Init(L);
    srand((int)time(NULL));
    for (i = 0; i < n; i++)
    {
        LinkedList_InsertFirst(L, rand() % 100);
    }
    return OK;
}

/*
 * Function     : 线性表演示
 * Description  :
 * In           : void
 * Out          : void
 */
void ArrayList_Sample()
{
    ArrayList L;
    ElemType e;
    bool b;
    printf("# 随机建立10个元素的线性表：\n");
    Random_Create_ArrayList(&L, 10);
    ArrayList_Traverse(L);

    printf("\n# 在第5个位置插入-5：\n");
    ArrayList_Insert(&L, 5, -5);
    ArrayList_Traverse(L);

    printf("\n# 在头部插入-99：\n");
    ArrayList_Insert(&L, 0, -99);
    ArrayList_Traverse(L);

    printf("\n# 在尾部部插入-50：\n");
    ArrayList_Insert(&L, ArrayList_Length(L), -50);
    ArrayList_Traverse(L);

    printf("\n# 删除第8个位置：\n");
    ArrayList_Delete(&L, 8);
    ArrayList_Traverse(L);

    printf("\n# 删除头部位置元素：\n");
    ArrayList_Delete(&L, 0);
    ArrayList_Traverse(L);

    printf("\n# 删除尾部位置元素：\n");
    ArrayList_Delete(&L, ArrayList_Length(L)-1);
    ArrayList_Traverse(L);

    printf("\n# 第3个位置上的元素为：\n");
    ArrayList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# 更新第3个位置上的元素为100：\n");
    ArrayList_Set(&L, 3, 100);
    ArrayList_Traverse(L);

    printf("\n# 元素-5的位置为：\n");
    printf("%d\n", ArrayList_Find(L, -5));

    printf("\n# 元素-100是否存在？\n");
    printf("%s\n", ArrayList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# 线性表长度为%d\n", ArrayList_Length(L));

    printf("\n# 清空线性表\n");
    ArrayList_Clear(&L);
    printf("线性表长度为%d\n", ArrayList_Length(L));
    b = ArrayList_Is_Empty(L);
    if(b) printf("线性表为空\n");
    else printf("线性表不为空\n");

    printf("\n# 在尾部部插入99：\n");
    ArrayList_Insert(&L, ArrayList_Length(L), 99);
    ArrayList_Traverse(L);
    printf("线性表长度为%d\n", ArrayList_Length(L));
    b = ArrayList_Is_Empty(L);
    if(b) printf("线性表为空");
    else printf("线性表不为空");
}

/*
 * Function     : 链表演示
 * Description  :
 * In           : void
 * Out          : void
 */
void LinkedList_Sample()
{
    LinkedList L;
    ElemType e;
    bool b;

    printf("# 随机建立10个元素的链表：\n");
    Random_Create_LinkedList(&L, 10);
    LinkedList_Traverse(L);

    printf("\n# 在第5个位置插入-5：\n");
    LinkedList_Insert(&L, 5, -5);
    LinkedList_Traverse(L);

    printf("\n# 在头部插入-99：\n");
    LinkedList_InsertFirst(&L, -99);
    LinkedList_Traverse(L);

    printf("\n# 在尾部部插入-50：\n");
    LinkedList_Insert(&L, LinkedList_Length(L), -50);
    LinkedList_Traverse(L);

    printf("\n# 删除第8个位置：\n");
    LinkedList_Delete(&L, 8);
    LinkedList_Traverse(L);

    printf("\n# 删除头部位置元素：\n");
    LinkedList_Delete(&L, 0);
    LinkedList_Traverse(L);

    printf("\n# 删除尾部位置元素：\n");
    LinkedList_Delete(&L, LinkedList_Length(L)-1);
    LinkedList_Traverse(L);

    printf("\n# 第3个位置上的元素为：\n");
    LinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# 更新第3个位置上的元素为100：\n");
    LinkedList_Set(&L, 3, 100);
    LinkedList_Traverse(L);

    printf("\n# 元素-5的位置为：\n");
    printf("%d\n", LinkedList_Find(L, -5));

    printf("\n# 元素-100是否存在？\n");
    printf("%s\n", LinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# 线性表长度为%d\n", LinkedList_Length(L));

    printf("\n# 清空线性表\n");
    LinkedList_Clear(&L);
    printf("线性表长度为%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("线性表为空\n");
    else printf("线性表不为空\n");

    printf("\n# 在尾部部插入99：\n");
    LinkedList_Insert(&L, LinkedList_Length(L), 99);
    LinkedList_Traverse(L);
    printf("线性表长度为%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("线性表为空");
    else printf("线性表不为空");
}
