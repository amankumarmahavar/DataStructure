#include "./SinglyLinkedList.c"

Status Compara(ElemType e, ElemType data);

void PrintElem(ElemType e);

int main()
{
	LinkList L;
	int i;
	ElemType e;

	printf("1. \n���� InitList����...\n");
	{
		printf("��ʼ�������� L ...\n");
		InitList(&L);
		printf("\n");
	}
	PressEnter;

	printf("2. \n���� ListEmpty����...\n");
	{
		ListEmpty(L) ? printf(" L Ϊ��\n") : printf(" L ��Ϊ��\n");
		printf("\n");
	}
	PressEnter;

	printf("3. \n���� ListInsert����...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert(L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("4. \n���� ListTraverse����...\n");
	{
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTarverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5. \n���� ListLength����...\n");
	{
		printf(" L �ĳ���Ϊ %d \n", ListLength(L));
		printf("\n");
	}
	PressEnter;

	printf("6. \n���� ListDelete����...\n");
	{
		ListDelete(L, 6, &e);
		printf("ɾ�� L �е� 6 ��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTarverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("7. \n���� GetElem ����...\n");
	{
		GetElem(L, 4, &e);
		printf(" L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("8. \n���� LocateElem ����...\n");
	{
		i = LocateElem(L, 13,  Compara);
		printf(" L �е�һ��Ԫ��ֵ���� \"12\" ��Ԫ�ص�λ��Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("9\n���� PriorElem ����...\n");
	{
		PriorElem(L, 4, &e);
		printf("Ԫ�� \"4\" ��ǰ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("10\n���� NextElem ����...\n");
	{
		NextElem(L, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("11\n���� ClearList ����...\n");
	{
		printf("��� L ǰ��");
		ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		ClearList(L);
		printf("��� L ��");
		ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("12\n���� DestroyList_L ����...\n");
	{
		printf("���� L ǰ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestoryList(&L);
		printf("���� L ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		printf("\n");
	}
	PressEnter;

	printf("13\n���� CreateList_h����...\n");
		//LinkList L;
		printf("ͷ�巨���������� L = ");
		CreateList_h(&L, 6);
		ListTarverse(L, PrintElem);
		printf("\n\n");
		printf("��ʱ�м�ڵ��ֵΪ��");
		GetMiddleNode(L, &e);
		PrintElem(e);
		PressEnter;
		printf("\n\n");

	printf("14\n���� CreateList_t ����...\n");
		printf("β�巨���������� L = ");
		CreateList_t(&L, 5);
		ListTarverse(L, PrintElem);
		printf("\n\n");

		printf("��ʱ�м�ڵ��ֵΪ��");
		GetMiddleNode(L, &e);
		PrintElem(e);
		PressEnter;
    return 0;
}








Status Compara(ElemType e, ElemType data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(ElemType e)
{
	printf("%d ", e);
}
