#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Status.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "cs50.h"

// �������n��Ԫ�ص����Ա�
Status Random_Create_ArrayList(ArrayList *L, int n);

int main()
{
    ArrayList L;
    ElemType e;
    printf("# �������10��Ԫ�ص����Ա�\n");
    Random_Create_ArrayList(&L, 10);
    ArrayList_Traverse(L);

    printf("\n# �ڵ�5��λ�ò���-5��\n");
    ArrayList_Insert(&L, 5, -5);
    ArrayList_Traverse(L);

    printf("\n# ��ͷ������-99��\n");
    ArrayList_Insert(&L, 0, -99);
    ArrayList_Traverse(L);

    printf("\n# ��β��������-50��\n");
    ArrayList_Insert(&L, ArrayList_Length(L), -50);
    ArrayList_Traverse(L);

    printf("\n# ɾ����8��λ�ã�\n");
    ArrayList_Delete(&L, 8);
    ArrayList_Traverse(L);

    printf("\n# ɾ��ͷ��λ��Ԫ�أ�\n");
    ArrayList_Delete(&L, 0);
    ArrayList_Traverse(L);

    printf("\n# ɾ��β��λ��Ԫ�أ�\n");
    ArrayList_Delete(&L, ArrayList_Length(L)-1);
    ArrayList_Traverse(L);

    printf("\n# ��3��λ���ϵ�Ԫ��Ϊ��\n");
    ArrayList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# ���µ�3��λ���ϵ�Ԫ��Ϊ100��\n");
    ArrayList_Set(&L, 3, 100);
    ArrayList_Traverse(L);

    printf("\n# Ԫ��-5��λ��Ϊ��\n");
    printf("%d\n", ArrayList_Find(L, -5));

    printf("\n# Ԫ��-100�Ƿ���ڣ�\n");
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
    printf("��2��Ԫ��Ϊ%d\n", e);
    pos = LinkedList_Find(L, 11);
    printf("11��λ��Ϊ%d\n", pos);
    */
    /*
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
    */
    return 0;
}

/*
 * Function     : �������n��Ԫ�ص����Ա�
 * Description  :
 * In           : ���������Ա�Ԫ�ظ���
 * Out          : ״̬
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
