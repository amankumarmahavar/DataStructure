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

	printf("1.函数 InitList测试...\n");
		printf("初始化双循环链表 L ...\n");
		InitList(&L);
		printf("\n");
	PressEnter;

	printf("2.函数 ListEmpty测试...\n");
		ListEmpty(L) ? printf(" L 为空\n") : printf(" L 不为空\n");
	PressEnter;

	printf("3.函数 ListInsert测试...\n");
		for(i=1; i<=6; i++)
		{
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert(L, i, 2*i);
		}
	PressEnter;

	printf("4.函数 ListTraverse 测试...\n");
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
	PressEnter;

	printf("5.函数 ListLength 测试...\n");
		printf(" L 的长度为 %d \n", ListLength(L));
	PressEnter;

	printf("6.函数 ListDelete 测试...\n");
		ListDelete(L, 4, &e);
		printf("删除 L 中第4个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
	PressEnter;

	printf("7.函数 GetElem 测试...\n");
		GetElem(L, 4, &e);
		printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
	PressEnter;

	printf("8.函数 LocateElem 测试...\n");
		i = LocateElem(L, 7, Compara);
		printf(" L 中第一个元素值大于 \"7\" 的元素的位置为 %d \n", i);
		printf("\n");
	PressEnter;

	printf("9.函数 PriorElem 测试...\n");
		PriorElem(L, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
	PressEnter;

	printf("10.函数 NextElem 测试...\n");
		NextElem(L, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
	PressEnter;

	printf("11.函数 GetElem测试...\n");
		DLinkedList p;
		p = GetElemPtr(L, 3);
		printf("链表第 3 个结点的指针为 0x%x，其对应的值为 \"%d\" \n", p, *p);
	PressEnter;

	printf("12.函数 ClearList 测试...\n");
		printf("清空 L 前：");
		ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		ClearList(L);
		printf("清空 L 后：");
		ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	PressEnter;

	printf("13.函数 DestroyList 测试...\n");
		printf("销毁 L 前：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		DestroyList(&L);
		printf("销毁 L 后：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	PressEnter;

	return OK;
}


Status Compara(ElemType e, ElemType data){
    return data>e?TRUE:FALSE;
}
void PrintElem(ElemType e){
	printf("%d ",e);
}
