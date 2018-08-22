#include <stdio.h>
#include <stdlib.h>

#include "Status.h"
#include "ArrayList.h"
#include "cs50.h"

int main()
{
    // ���������ѡ��
    Options op;
    ArrayList list;
    Status s;
    int pos, r;
    ElemType e;

    // ��ʼ������
    s = Init(&list);

    while (true)
    {
        printf("******************\n");
        printf("* 0 - �������   *\n");
        printf("* 1 - ����       *\n");
        printf("* 2 - ɾ��       *\n");
        printf("* 3 - ����       *\n");
        printf("* 4 - ����       *\n");
        printf("* 5 - ��ȡ       *\n");
        printf("* 7 - ���       *\n");
        printf("* 9 - �˳�       *\n");
        printf("******************\n");
        printf("ѡ�");

        op = get_int();
        switch (op)
        {
        case APPEND:
            printf("�������");
            e = get_int();
            Append(&list, e);
            // DEBUG: printf("(len, capacity): (%d,%d)\n", list.len, list.size);
            break;
        case INSERT:
            printf("����λ�ã�");
            pos = get_int();
            printf("�������ݣ�");
            e = get_int();
            s = Insert(&list, pos, e);
            if (s == OUT_OF_RANGE) printf("��Χ����!\n");
            break;
        case DELETE:
            printf("ɾ��λ�ã�");
            pos = get_int();
            s = Delete(&list, pos);
            if (s == OUT_OF_RANGE) printf("��Χ����!\n");
            break;
        case UPDATE:
            printf("����λ�ã�");
            pos = get_int();
            printf("����Ϊ��");
            e = get_int();
            s = Set(&list, pos, e);
            if (s == OUT_OF_RANGE) printf("��Χ����!\n");
            break;
        case FIND:
            printf("����Ԫ�أ�");
            e = get_int();
            r = Find(list, e);
            if (r == -1)
                printf("û�и�Ԫ�أ�\n");
            else
                printf("Ԫ��λ��λ��%d\n", r);
            break;
        case READ:
            printf("��ȡλ�ã�");
            pos = get_int();
            s = Get(list, pos, &e);
            if (s == OUT_OF_RANGE) printf("��Χ����!\n");
            else printf("λ��%2d��ֵΪ%d\n", pos, e);
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
