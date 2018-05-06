#include "./StaticLinkedList.c"

void PrintElem(ElemType e);
void PressEnter();


int main()
{
	SLinkList H;
	ElemType e;
	int i;


	printf("1.\n函数InitSpace测试...\n");
		printf("初始化静态链表的备用空间 SPACE ...\n");
		InitSpace();
	PressEnter();

	printf("2.\n函数Malloc，InitList测试...\n");
		printf("初始化静态链表 H ，用Malloc函数申请空间...\n");
		InitList(&H);

	PressEnter();

	printf("3.\n函数ListEmpty测试...\n");
		ListEmpty(H) ? printf(" H 为空\n") : printf(" H 不为空\n");
	PressEnter();

	printf("4.\n函数ListInsert测试...\n");
		for(i=1; i<=9; i++)
		{
			printf("在 H 第 %d 个位置插入\"%d\" ...\n", i, 2*i);
			ListInsert(H, i, 2*i);
		}
	PressEnter();

	printf("5.\n函数ListTraverse测试...\n");
		printf(" H 中的元素为：H = ");
		ListTraverse(H, PrintElem);
	PressEnter();

	printf("6.\n函数ListLength_SL测试...\n");
		printf(" H 的长度为 %d \n", ListLength(H));
		printf("\n");
	PressEnter();

	printf("7.\n函数Free、ListDelete测试...\n");
		ListDelete(H, 6, &e);
		printf("删除 H 中第 6 个元素 \"%d\" ，用Free释放空间...\n", e);
		printf(" H 的元素为：H = ");
		ListTraverse(H, PrintElem);
	PressEnter();

	printf("8.\n函数LocateElem测试...\n");
		printf("元素 \"8\" 在 H 中的位序为 %d \n", LocateElem(H, 8));
	PressEnter();

	printf("9.\n函数PriorElem测试...\n");
		PriorElem(H, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
	PressEnter();

	printf("10.\n函数NextElem测试...\n");
		NextElem(H, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
	PressEnter();

	printf("11.\n函数GetElem测试...\n");
		GetElem(H, 4, &e);
		printf(" H 中第 4 个位置的元素为 \"%d\" \n", e);
	PressEnter();

	printf("中间节点的值的测试");
		ListTraverse(H, PrintElem);
		GetMidNode(H, &e);
		printf("中间节点的值是%d", e);
	PressEnter();

	printf("12.\n函数ClearList测试...\n");
		printf("清空 H 前：");
		ListEmpty(H) ? printf(" H 为空\n") : printf(" H 不为空\n");
		ClearList(H);
		printf("清空 H 后：");
		ListEmpty(H) ? printf(" H 为空\n") : printf(" H 不为空\n");
	PressEnter();

	printf("13.\n函数DestroyList测试...\n");
		printf("销毁 H 前：");
		H ? printf(" H 存在\n") : printf(" H 不存在\n");
		DestroyList(&H);
		printf("销毁 H 后：");
		H ? printf(" H 存在\n") : printf(" H 不存在\n");
		printf("\n");
	PressEnter();

	printf("14.\n函数difference测试...\n");
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

	printf("S = (A-B)∪(B-A) = ");
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


