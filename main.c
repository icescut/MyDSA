#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Status.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "cs50.h"

// 随机建立n个元素的线性表
Status Random_Create_ArrayList(ArrayList *L, int n);

int main()
{
    ArrayList L;
    ElemType e;
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

    /*
    LinkedList L;
    ElemType e;
    int pos;
    LinkedList_Init(&L);
    //printf("%d\n", L.len);
    LinkedList_Insert(&L, 0, 10);
    LinkedList_Insert(&L, 1, 11);
    LinkedList_Insert(&L, 2, 12);
    LinkedList_Insert(&L, 0, 9);
    LinkedList_Traverse(L);
    LinkedList_Delete(&L, 1);
    LinkedList_Traverse(L);
    LinkedList_Get(L, 2, &e);
    printf("第2个元素为%d\n", e);
    pos = LinkedList_Find(L, 11);
    printf("11的位置为%d\n", pos);
    */
    /*
    // 接收输入的选项
    Options op;
    ArrayList list;
    Status s;
    int pos, r;
    ElemType e;

    // 初始化数组
    s = Init(&list);

    while (true)
    {
        printf("******************\n");
        printf("* 0 - 插入最后   *\n");
        printf("* 1 - 插入       *\n");
        printf("* 2 - 删除       *\n");
        printf("* 3 - 更新       *\n");
        printf("* 4 - 查找       *\n");
        printf("* 5 - 读取       *\n");
        printf("* 7 - 清空       *\n");
        printf("* 9 - 退出       *\n");
        printf("******************\n");
        printf("选项：");

        op = get_int();
        switch (op)
        {
        case APPEND:
            printf("插入最后：");
            e = get_int();
            Append(&list, e);
            // DEBUG: printf("(len, capacity): (%d,%d)\n", list.len, list.size);
            break;
        case INSERT:
            printf("插入位置：");
            pos = get_int();
            printf("插入内容：");
            e = get_int();
            s = Insert(&list, pos, e);
            if (s == OUT_OF_RANGE) printf("范围错误!\n");
            break;
        case DELETE:
            printf("删除位置：");
            pos = get_int();
            s = Delete(&list, pos);
            if (s == OUT_OF_RANGE) printf("范围错误!\n");
            break;
        case UPDATE:
            printf("更新位置：");
            pos = get_int();
            printf("更新为：");
            e = get_int();
            s = Set(&list, pos, e);
            if (s == OUT_OF_RANGE) printf("范围错误!\n");
            break;
        case FIND:
            printf("查找元素：");
            e = get_int();
            r = Find(list, e);
            if (r == -1)
                printf("没有该元素！\n");
            else
                printf("元素位于位置%d\n", r);
            break;
        case READ:
            printf("读取位置：");
            pos = get_int();
            s = Get(list, pos, &e);
            if (s == OUT_OF_RANGE) printf("范围错误!\n");
            else printf("位置%2d的值为%d\n", pos, e);
            break;
        case CLEAR:
            Clear(&list);
            break;
        case QUIT:
            break;
        default:
            break;
        }
        if (op == QUIT) break;
        Traverse(list);
    }
    */
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
