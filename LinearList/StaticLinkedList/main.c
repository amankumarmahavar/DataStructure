#include "./StaticLinkedList.c"

void PrintElem(ElemType e);
void PressEnter();


int main()
{
	SLinkList H;
	ElemType e;
	int i;


	printf("1.\n����InitSpace����...\n");
		printf("��ʼ����̬����ı��ÿռ� SPACE ...\n");
		InitSpace();
	PressEnter();

	printf("2.\n����Malloc��InitList����...\n");
		printf("��ʼ����̬���� H ����Malloc��������ռ�...\n");
		InitList(&H);

	PressEnter();

	printf("3.\n����ListEmpty����...\n");
		ListEmpty(H) ? printf(" H Ϊ��\n") : printf(" H ��Ϊ��\n");
	PressEnter();

	printf("4.\n����ListInsert����...\n");
		for(i=1; i<=9; i++)
		{
			printf("�� H �� %d ��λ�ò���\"%d\" ...\n", i, 2*i);
			ListInsert(H, i, 2*i);
		}
	PressEnter();

	printf("5.\n����ListTraverse����...\n");
		printf(" H �е�Ԫ��Ϊ��H = ");
		ListTraverse(H, PrintElem);
	PressEnter();

	printf("6.\n����ListLength_SL����...\n");
		printf(" H �ĳ���Ϊ %d \n", ListLength(H));
		printf("\n");
	PressEnter();

	printf("7.\n����Free��ListDelete����...\n");
		ListDelete(H, 6, &e);
		printf("ɾ�� H �е� 6 ��Ԫ�� \"%d\" ����Free�ͷſռ�...\n", e);
		printf(" H ��Ԫ��Ϊ��H = ");
		ListTraverse(H, PrintElem);
	PressEnter();

	printf("8.\n����LocateElem����...\n");
		printf("Ԫ�� \"8\" �� H �е�λ��Ϊ %d \n", LocateElem(H, 8));
	PressEnter();

	printf("9.\n����PriorElem����...\n");
		PriorElem(H, 6, &e);
		printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n", e);
	PressEnter();

	printf("10.\n����NextElem����...\n");
		NextElem(H, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
	PressEnter();

	printf("11.\n����GetElem����...\n");
		GetElem(H, 4, &e);
		printf(" H �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
	PressEnter();

	printf("�м�ڵ��ֵ�Ĳ���");
		ListTraverse(H, PrintElem);
		GetMidNode(H, &e);
		printf("�м�ڵ��ֵ��%d", e);
	PressEnter();

	printf("12.\n����ClearList����...\n");
		printf("��� H ǰ��");
		ListEmpty(H) ? printf(" H Ϊ��\n") : printf(" H ��Ϊ��\n");
		ClearList(H);
		printf("��� H ��");
		ListEmpty(H) ? printf(" H Ϊ��\n") : printf(" H ��Ϊ��\n");
	PressEnter();

	printf("13.\n����DestroyList����...\n");
		printf("���� H ǰ��");
		H ? printf(" H ����\n") : printf(" H ������\n");
		DestroyList(&H);
		printf("���� H ��");
		H ? printf(" H ����\n") : printf(" H ������\n");
		printf("\n");
	PressEnter();

	printf("14.\n����difference����...\n");
	SLinkList S;
	int len_a=3, len_b=5, value;
	ElemType A[MAXSIZE], B[MAXSIZE];
	for(i = 0, value =2; i < len_a; i++)
		A[i] = value++;
	for(i = 0, value =9; i < len_b; i++)
		B[i] = value++;

	printf("A = ");
	for(i = 0; i < len_a; i++)
		PrintElem(A[i]);
	printf("\n");
	printf("B = ");
	for(i = 0; i < len_b; i++)
		PrintElem(B[i]);
	printf("\n");

	printf("S = (A-B)��(B-A) = ");
	difference(&S, A, len_a, B, len_b);
	ListTraverse(S, PrintElem);
	printf("\n\n");

    return 0;
}

void PrintElem(ElemType e){
	printf("%d ", e);
}

void PressEnter(){
	printf("\n\n");
	fflush(stdin);
	printf("Press Enter...");
	getchar();
	fflush(stdin);
	printf("\n\n");
}


