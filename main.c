#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Status.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "cs50.h"

// �������n��Ԫ�ص����Ա�
Status Random_Create_ArrayList(ArrayList *L, int n);

// �������n��Ԫ�ص�����
Status Random_Create_LinkedList(LinkedList *L, int n);

// ���Ա���ʾ
void ArrayList_Sample();

// ������ʾ
void LinkedList_Sample();

int main()
{
    ArrayList_Sample();
    // LinkedList_Sample();

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

/*
 * Function     : �������n��Ԫ�ص�����
 * Description  :
 * In           : ����������Ԫ�ظ���
 * Out          : ״̬
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
 * Function     : ���Ա���ʾ
 * Description  :
 * In           : void
 * Out          : void
 */
void ArrayList_Sample()
{
    ArrayList L;
    ElemType e;
    bool b;
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

    printf("\n# ���Ա���Ϊ%d\n", ArrayList_Length(L));

    printf("\n# ������Ա�\n");
    ArrayList_Clear(&L);
    printf("���Ա���Ϊ%d\n", ArrayList_Length(L));
    b = ArrayList_Is_Empty(L);
    if(b) printf("���Ա�Ϊ��\n");
    else printf("���Ա�Ϊ��\n");

    printf("\n# ��β��������99��\n");
    ArrayList_Insert(&L, ArrayList_Length(L), 99);
    ArrayList_Traverse(L);
    printf("���Ա���Ϊ%d\n", ArrayList_Length(L));
    b = ArrayList_Is_Empty(L);
    if(b) printf("���Ա�Ϊ��");
    else printf("���Ա�Ϊ��");
}

/*
 * Function     : ������ʾ
 * Description  :
 * In           : void
 * Out          : void
 */
void LinkedList_Sample()
{
    LinkedList L;
    ElemType e;
    bool b;

    printf("# �������10��Ԫ�ص�����\n");
    Random_Create_LinkedList(&L, 10);
    LinkedList_Traverse(L);

    printf("\n# �ڵ�5��λ�ò���-5��\n");
    LinkedList_Insert(&L, 5, -5);
    LinkedList_Traverse(L);

    printf("\n# ��ͷ������-99��\n");
    LinkedList_InsertFirst(&L, -99);
    LinkedList_Traverse(L);

    printf("\n# ��β��������-50��\n");
    LinkedList_Insert(&L, LinkedList_Length(L), -50);
    LinkedList_Traverse(L);

    printf("\n# ɾ����8��λ�ã�\n");
    LinkedList_Delete(&L, 8);
    LinkedList_Traverse(L);

    printf("\n# ɾ��ͷ��λ��Ԫ�أ�\n");
    LinkedList_Delete(&L, 0);
    LinkedList_Traverse(L);

    printf("\n# ɾ��β��λ��Ԫ�أ�\n");
    LinkedList_Delete(&L, LinkedList_Length(L)-1);
    LinkedList_Traverse(L);

    printf("\n# ��3��λ���ϵ�Ԫ��Ϊ��\n");
    LinkedList_Get(L, 3, &e);
    printf("%d\n", e);

    printf("\n# ���µ�3��λ���ϵ�Ԫ��Ϊ100��\n");
    LinkedList_Set(&L, 3, 100);
    LinkedList_Traverse(L);

    printf("\n# Ԫ��-5��λ��Ϊ��\n");
    printf("%d\n", LinkedList_Find(L, -5));

    printf("\n# Ԫ��-100�Ƿ���ڣ�\n");
    printf("%s\n", LinkedList_Find(L, -100) != -1 ? "true" : "false");

    printf("\n# ���Ա���Ϊ%d\n", LinkedList_Length(L));

    printf("\n# ������Ա�\n");
    LinkedList_Clear(&L);
    printf("���Ա���Ϊ%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("���Ա�Ϊ��\n");
    else printf("���Ա�Ϊ��\n");

    printf("\n# ��β��������99��\n");
    LinkedList_Insert(&L, LinkedList_Length(L), 99);
    LinkedList_Traverse(L);
    printf("���Ա���Ϊ%d\n", LinkedList_Length(L));
    b = LinkedList_Is_Empty(L);
    if(b) printf("���Ա�Ϊ��");
    else printf("���Ա�Ϊ��");
}
