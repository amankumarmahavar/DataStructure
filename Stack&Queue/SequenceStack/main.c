#include <stdio.h>
#include <stdlib.h>
#include "./SequenceStack.c"

void PrintElem(ElemType e);
	//���Ժ�������ӡ����

int main(int argc, char **argv)
{
	SqStack S;
	int i;
	ElemType e;

	printf("���� InitStack ����...\n");			
	{
		printf("��ʼ��˳��ջ S ...\n");
		InitStack_Sq(&S);
		printf("\n");
	}
	PressEnter;

	printf("���� StackEmpty ����...\n");			
	{
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("���� Push ����...\n");					
	{
		for(i=1; i<=6; i++)
		{
			printf("�� \"%2d\" ѹ��ջ S ", 2*i);
			Push_Sq(&S, 2*i);
			printf("���ۼƵ� %d ��Ԫ�أ�...\n", S.top-S.base);
		}
		printf("\n");
	}
	PressEnter;

	printf("���� StackTraverse ����...\n");		
	{
		printf(" S �е�Ԫ��Ϊ��S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� Pop ����...\n");					
	{
		Pop_Sq(&S, &e);
		printf("ջ��Ԫ�� \"%d\" ��ջ...\n", e);
		printf(" S �е�Ԫ��Ϊ��S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� StackLength ����...\n");			
	{
		i = StackLength_Sq(S);
		printf(" S �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("���� GetTop ����...\n");				
	{
		GetTop_Sq(S, &e);
		printf("ջ��Ԫ�ص�ֵΪ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("���� ClearStack ����...\n");			
	{
		printf("��� S ǰ��");
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		ClearStack_Sq(&S);
		printf("��� S ��");
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("���� DestroyStack ����...\n");			
	{
		printf("���� S ǰ��");
		S.base!=NULL && S.top!=NULL ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
		DestroyStack_Sq(&S);
		printf("���� S ��");
		S.base!=NULL && S.top!=NULL ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

void PrintElem(ElemType e)
{
	printf("%d ", e);
}
