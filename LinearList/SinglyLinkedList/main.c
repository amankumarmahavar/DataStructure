#include "./SinglyLinkedList.c"

Status Compara(ElemType e, ElemType data);

void PrintElem(ElemType e);

int main()
{
	LinkList L;
	int i;
	ElemType e;

	printf("1. \n函数 InitList测试...\n");
	{
		printf("初始化单链表 L ...\n");
		InitList(&L);
		printf("\n");
	}
	PressEnter;

	printf("2. \n函数 ListEmpty测试...\n");
	{
		ListEmpty(L) ? printf(" L 为空\n") : printf(" L 不为空\n");
		printf("\n");
	}
	PressEnter;

	printf("3. \n函数 ListInsert测试...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert(L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("4. \n函数 ListTraverse测试...\n");
	{
		printf(" L 中的元素为：L = ");
		ListTarverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5. \n函数 ListLength测试...\n");
	{
		printf(" L 的长度为 %d \n", ListLength(L));
		printf("\n");
	}
	PressEnter;

	printf("6. \n函数 ListDelete测试...\n");
	{
		ListDelete(L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为：L = ");
		ListTarverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("7. \n函数 GetElem 测试...\n");
	{
		GetElem(L, 4, &e);
		printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("8. \n函数 LocateElem 测试...\n");
	{
		i = LocateElem(L, 13,  Compara);
		printf(" L 中第一个元素值大于 \"12\" 的元素的位置为 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("9\n函数 PriorElem 测试...\n");
	{
		PriorElem(L, 4, &e);
		printf("元素 \"4\" 的前驱为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("10\n函数 NextElem 测试...\n");
	{
		NextElem(L, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("11\n函数 ClearList 测试...\n");
	{
		printf("清空 L 前：");
		ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		ClearList(L);
		printf("清空 L 后：");
		ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("12\n函数 DestroyList_L 测试...\n");
	{
		printf("销毁 L 前：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		DestoryList(&L);
		printf("销毁 L 后：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		printf("\n");
	}
	PressEnter;

	printf("13\n函数 CreateList_h测试...\n");
		//LinkList L;
		printf("头插法建立单链表 L = ");
		CreateList_h(&L, 6);
		ListTarverse(L, PrintElem);
		printf("\n\n");
		printf("此时中间节点的值为：");
		GetMiddleNode(L, &e);
		PrintElem(e);
		PressEnter;
		printf("\n\n");

	printf("14\n函数 CreateList_t 测试...\n");
		printf("尾插法建立单链表 L = ");
		CreateList_t(&L, 5);
		ListTarverse(L, PrintElem);
		printf("\n\n");

		printf("此时中间节点的值为：");
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
