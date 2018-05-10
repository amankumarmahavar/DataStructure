#include <stdio.h>
#include <stdlib.h>
#include "./ExtendedLinkedList.c"

void PrintElem(ElemType e){
	printf("%d ",e);
}

Status Compare(ElemType e, ElemType data){
	return (data>e) ? TRUE:FALSE;
}

int main()
{
    LinkList L;
    Link p, q, s;
    Position r;
    int i;
    ElemType e;

	printf("1.函数 InitList_E 测试...\n");
	{
		printf("初始化扩展的单链表 L ...\n");
		InitList(&L);
		printf("\n");
	}
	PressEnter;

	printf("2.函数 ListEmpty_E 测试...\n");
	{
		ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("3.函数 ListInsert_L_E 测试...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert(&L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("4.函数 ListTraverse_E 测试...\n");
	{
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5.函数 ListLength_E 测试...\n");
	{
		i = ListLength(L);
		printf(" L 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("6.函数 ListDelete_E 测试...\n");
	{
		ListDelete(&L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("7.函数 LocatePos_E 测试...\n");
	{
		LocatePos(L, 3, &p);
		printf(" L 中第 3 个元素 \"%d\" 的地址为 0x%x \n", p->data, p);
		printf("\n");
	}
	PressEnter;

	printf("8.函数 PriorPos_E 测试...\n");
	{
		r = PriorPos(L, p);
		printf("指针 p 指向的元素 \"%d\" 的前驱元素为 \"%d\" \n", p->data, r->data);
		printf("\n");
	}
	PressEnter;

	printf("9.函数 NextPos_E 测试...\n");
	{
		r = NextPos(p);
		printf("指针 p 指向的元素 \"%d\" 的后继元素为 \"%d\" \n", p->data, r->data);
		printf("\n");
	}

	printf("10.函数 LocateElem_E 测试...\n");
	{
		r = LocateElem(L, 7, Compare);
		printf(" L 中第一个元素值大于 7 的元素 \"%d\" 的地址为 0x%x \n", r->data, r);
		printf("\n");
	}
	PressEnter;

	printf("11.函数 MakeNode_E 测试...\n");
	{
		printf("创建结点 p ...\n");
		MakeNode(&p, 101);
		printf("创建结点 q ...\n");
		MakeNode(&q, 202);
		printf("\n");
	}
	PressEnter;

	printf("12.函数 GetCurElem_E 测试...\n");
	{
		e = GetCurElem(p);
		printf("结点 p 的值为 \"%d\" \n", e);
		e = GetCurElem(q);
		printf("结点 q 的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("13.函数 SetCurElem_E 测试...\n");
	{
		printf("用 888 替换 p 结点中的值...\n");
		SetCurElem(p, 888);
		printf("结点 p 的值为 \"%d\" \n", p->data);
		printf("\n");
	}
	PressEnter;

		printf("14.函数 FreeNode_E 测试...\n");
	{
		printf("销毁结点 p 前：");
		p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
		FreeNode(&p);
		printf("销毁结点 p 后：");
		p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
		printf("\n");
	}
	PressEnter;

	printf("15.函数 Append_E 测试...\n");
	{
		printf("将 q 结点插在 L 最后一个结点之后...\n");
		Append(&L, q);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("16.函数 Remove_E 测试...\n");
	{
		printf("删除 L 中最后一个结点，用 p 接收删除的结点...\n");
		Remove(&L, &p);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("17.函数 InsFirst_E 测试...\n");
	{
		printf("创建值为 303 的结点 p ...\n");
		MakeNode(&p, 303);
		printf("令 q 指向 L 中第 4 个元素...\n");
		LocatePos(L, 4, &q);
		printf("将 p 结点插入到以 q 作头结点的链表的第一个结点之前...\n");
		InsFirst(&L, q, p);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("18.函数 DelFirst测试...\n");
	{
		printf("删除 L 中以第4个结点 q 为头结点的链表的第一个结点...\n");
		DelFirst(&L, q, &p);
		printf("当前 L 的值为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("19.函数 GetHead测试...\n");
	{
		p = GetHead(L);
		printf(" L 头指针为 p = L.head = 0x%x \n", p);
		printf("\n");
	}
	PressEnter;

	printf("20.函数 GetLast 测试...\n");
	{
		q = GetLast(L);
		printf(" L 尾指针为 q = L.tail = 0x%x \n", q);
		printf("\n");
	}
	PressEnter;

	printf("21.函数 InsBefore测试...\n");
	{
		printf("创建值为 404 的结点 s ...\n");
		MakeNode(&s, 404);
		printf("将结点 s 插入到尾结点 q 之前...\n");
		InsBefore(&L, &q, s);
		printf("当前 L 的值为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("22.函数 InsAfter测试...\n");
	{
		printf("创建值为 505 的结点 s ...\n");
		MakeNode(&s, 505);
		printf("将结点 s 插入到头结点 p 之后...\n");
		InsAfter(&L, &p, s);
		printf(" L 中的元素为：L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("23.函数 ClearList测试...\n");
	{
		printf("清空 L 前：");
		ListEmpty(L) ? printf(" L 为空") : printf(" L 不为空！");
		ClearList(&L);
		printf("清空 L 后：");
		ListEmpty(L) ? printf(" L 为空") : printf(" L 不为空");
		printf("\n");
	}
	PressEnter;

	printf("24.函数 DestroyList测试...\n");
	{
		printf("销毁 L 前：");
		L.head!=NULL && L.tail!=NULL ? printf(" L 存在") : printf(" L 不存在");
		DestrosyList(&L);
		printf("销毁 L 后：");
		L.head!=NULL && L.tail!=NULL ? printf(" L 存在") : printf(" L 不存在");
		printf("\n");
	}
	PressEnter;
    return 0;
}
