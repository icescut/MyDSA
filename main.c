#include <stdio.h>
#include <stdlib.h>

#include "Status.h"
#include "ArrayList.h"
#include "cs50.h"

int main()
{
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
    return 0;
}
