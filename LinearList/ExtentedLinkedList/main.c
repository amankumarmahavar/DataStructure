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

	printf("1.���� InitList_E ����...\n");
	{
		printf("��ʼ����չ�ĵ����� L ...\n");
		InitList(&L);
		printf("\n");
	}
	PressEnter;

	printf("2.���� ListEmpty_E ����...\n");
	{
		ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("3.���� ListInsert_L_E ����...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert(&L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("4.���� ListTraverse_E ����...\n");
	{
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5.���� ListLength_E ����...\n");
	{
		i = ListLength(L);
		printf(" L �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("6.���� ListDelete_E ����...\n");
	{
		ListDelete(&L, 6, &e);
		printf("ɾ�� L �е� 6 ��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("7.���� LocatePos_E ����...\n");
	{
		LocatePos(L, 3, &p);
		printf(" L �е� 3 ��Ԫ�� \"%d\" �ĵ�ַΪ 0x%x \n", p->data, p);
		printf("\n");
	}
	PressEnter;

	printf("8.���� PriorPos_E ����...\n");
	{
		r = PriorPos(L, p);
		printf("ָ�� p ָ���Ԫ�� \"%d\" ��ǰ��Ԫ��Ϊ \"%d\" \n", p->data, r->data);
		printf("\n");
	}
	PressEnter;

	printf("9.���� NextPos_E ����...\n");
	{
		r = NextPos(p);
		printf("ָ�� p ָ���Ԫ�� \"%d\" �ĺ��Ԫ��Ϊ \"%d\" \n", p->data, r->data);
		printf("\n");
	}

	printf("10.���� LocateElem_E ����...\n");
	{
		r = LocateElem(L, 7, Compare);
		printf(" L �е�һ��Ԫ��ֵ���� 7 ��Ԫ�� \"%d\" �ĵ�ַΪ 0x%x \n", r->data, r);
		printf("\n");
	}
	PressEnter;

	printf("11.���� MakeNode_E ����...\n");
	{
		printf("������� p ...\n");
		MakeNode(&p, 101);
		printf("������� q ...\n");
		MakeNode(&q, 202);
		printf("\n");
	}
	PressEnter;

	printf("12.���� GetCurElem_E ����...\n");
	{
		e = GetCurElem(p);
		printf("��� p ��ֵΪ \"%d\" \n", e);
		e = GetCurElem(q);
		printf("��� q ��ֵΪ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("13.���� SetCurElem_E ����...\n");
	{
		printf("�� 888 �滻 p ����е�ֵ...\n");
		SetCurElem(p, 888);
		printf("��� p ��ֵΪ \"%d\" \n", p->data);
		printf("\n");
	}
	PressEnter;

		printf("14.���� FreeNode_E ����...\n");
	{
		printf("���ٽ�� p ǰ��");
		p ? printf(" p ���ڣ�\n") : printf(" p �����ڣ���\n");
		FreeNode(&p);
		printf("���ٽ�� p ��");
		p ? printf(" p ���ڣ�\n") : printf(" p �����ڣ���\n");
		printf("\n");
	}
	PressEnter;

	printf("15.���� Append_E ����...\n");
	{
		printf("�� q ������ L ���һ�����֮��...\n");
		Append(&L, q);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("16.���� Remove_E ����...\n");
	{
		printf("ɾ�� L �����һ����㣬�� p ����ɾ���Ľ��...\n");
		Remove(&L, &p);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("17.���� InsFirst_E ����...\n");
	{
		printf("����ֵΪ 303 �Ľ�� p ...\n");
		MakeNode(&p, 303);
		printf("�� q ָ�� L �е� 4 ��Ԫ��...\n");
		LocatePos(L, 4, &q);
		printf("�� p �����뵽�� q ��ͷ��������ĵ�һ�����֮ǰ...\n");
		InsFirst(&L, q, p);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("18.���� DelFirst����...\n");
	{
		printf("ɾ�� L ���Ե�4����� q Ϊͷ��������ĵ�һ�����...\n");
		DelFirst(&L, q, &p);
		printf("��ǰ L ��ֵΪ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("19.���� GetHead����...\n");
	{
		p = GetHead(L);
		printf(" L ͷָ��Ϊ p = L.head = 0x%x \n", p);
		printf("\n");
	}
	PressEnter;

	printf("20.���� GetLast ����...\n");
	{
		q = GetLast(L);
		printf(" L βָ��Ϊ q = L.tail = 0x%x \n", q);
		printf("\n");
	}
	PressEnter;

	printf("21.���� InsBefore����...\n");
	{
		printf("����ֵΪ 404 �Ľ�� s ...\n");
		MakeNode(&s, 404);
		printf("����� s ���뵽β��� q ֮ǰ...\n");
		InsBefore(&L, &q, s);
		printf("��ǰ L ��ֵΪ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("22.���� InsAfter����...\n");
	{
		printf("����ֵΪ 505 �Ľ�� s ...\n");
		MakeNode(&s, 505);
		printf("����� s ���뵽ͷ��� p ֮��...\n");
		InsAfter(&L, &p, s);
		printf(" L �е�Ԫ��Ϊ��L = ");
		ListTraverse(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("23.���� ClearList����...\n");
	{
		printf("��� L ǰ��");
		ListEmpty(L) ? printf(" L Ϊ��") : printf(" L ��Ϊ�գ�");
		ClearList(&L);
		printf("��� L ��");
		ListEmpty(L) ? printf(" L Ϊ��") : printf(" L ��Ϊ��");
		printf("\n");
	}
	PressEnter;

	printf("24.���� DestroyList����...\n");
	{
		printf("���� L ǰ��");
		L.head!=NULL && L.tail!=NULL ? printf(" L ����") : printf(" L ������");
		DestrosyList(&L);
		printf("���� L ��");
		L.head!=NULL && L.tail!=NULL ? printf(" L ����") : printf(" L ������");
		printf("\n");
	}
	PressEnter;
    return 0;
}
