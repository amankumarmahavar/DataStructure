#include <stdio.h>
#include <stdlib.h>
#include "./DoubleLinkedList.c"

#define PressEnter {\
	printf("\n");\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
	printf("\n");\
}

Status Compara(ElemType e, ElemType data);
void PrintElem(ElemType e);

int main()
{
	DLinkedList L;
	int i;
	ElemType e;

	printf("1.���� InitList����...\n");
		printf("��ʼ��˫ѭ������ L ...\n");
		InitList(&L);
		printf("\n");
	PressEnter;

	printf("2.���� ListEmpty����...\n");
		ListEmpty(L) ? printf(" L Ϊ��\n") : printf(" L ��Ϊ��\n");
	PressEnter;

	printf("3.���� ListInsert����...\n");
		for(i=1; i<=6; i++)
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert(L, i, 2*i);
		}
	PressEnter;

	printf("4.���� ListTraverse ����...\n");
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
	PressEnter;

	printf("5.���� ListLength ����...\n");
		printf(" L �ĳ���Ϊ %d \n", ListLength(L));
	PressEnter;

	printf("6.���� ListDelete ����...\n");
		ListDelete(L, 4, &e);
		printf("ɾ�� L �е�4��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
	PressEnter;

	printf("7.���� GetElem ����...\n");
		GetElem(L, 4, &e);
		printf(" L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
	PressEnter;

	printf("8.���� LocateElem ����...\n");
		i = LocateElem(L, 7, Compara);
		printf(" L �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ�ص�λ��Ϊ %d \n", i);
		printf("\n");
	PressEnter;

	printf("9.���� PriorElem ����...\n");
		PriorElem(L, 6, &e);
		printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n", e);
	PressEnter;

	printf("10.���� NextElem ����...\n");
		NextElem(L, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
	PressEnter;

	printf("11.���� GetElem����...\n");
		DLinkedList p;
		p = GetElemPtr(L, 3);
		printf("����� 3 ������ָ��Ϊ 0x%x�����Ӧ��ֵΪ \"%d\" \n", p, *p);
	PressEnter;

	printf("12.���� ClearList ����...\n");
		printf("��� L ǰ��");
		ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		ClearList(L);
		printf("��� L ��");
		ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
	PressEnter;

	printf("13.���� DestroyList ����...\n");
		printf("���� L ǰ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestroyList(&L);
		printf("���� L ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
	PressEnter;

	return OK;
}


Status Compara(ElemType e, ElemType data){
    return data>e?TRUE:FALSE;
}
void PrintElem(ElemType e){
	printf("%d ",e);
}
