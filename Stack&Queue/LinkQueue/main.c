#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.c"

void PrintElem(QElemType_L e){
	printf("%d ", e);
}

int main()
{
	LinkQueue Q;
	int i;
	QElemType_L e;


	printf("���� InitQueue_L ����...\n");
	{
		printf("��ʼ������ Q ...\n");
		InitQueue_L(&Q);
		printf("\n");
	}
	PressEnter;

	printf("���� QueueEmpty_L ����...\n");
	{
		QueueEmpty_L(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("���� EnQueue_L ����...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("Ԫ�� \"%2d\" ��ӣ�", 2*i);
			EnQueue_L(&Q, 2*i);
			printf("���ۼƵ� %d ��Ԫ�أ�...\n", QueueLength_L(Q));
		}
		printf("\n");
	}
	PressEnter;

	printf("���� QueueTraverse_L ����...\n");
	{
		printf(" Q �е�Ԫ��Ϊ��Q = ");
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� DeQueue_L ����...\n");
	{
		DeQueue_L(&Q, &e);
		printf("��ͷԪ�� \"%d\" ����...\n", e);
		printf(" Q �е�Ԫ��Ϊ��Q = ");
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� QueueLength_L ����...\n");
	{
		i = QueueLength_L(Q);
		printf(" Q �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("���� GetHead_L ����...\n");
	{
		GetHead_L(Q, &e);
		printf("��ͷԪ�ص�ֵΪ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("���� ClearQueue_L ����...\n");
	{
		printf("��� Q ǰ��");
		QueueEmpty_L(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		ClearQueue_L(&Q);
		printf("��� Q ��");
		QueueEmpty_L(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("���� DestroyQueue_L ����...\n");
	{
		printf("���� Q ǰ��");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
		DestroyQueue_L(&Q);
		printf("���� Q ��");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}


