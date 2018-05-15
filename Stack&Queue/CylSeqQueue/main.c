
#include <stdio.h>
#include <stdlib.h>
#include "CylSeqQueue.c"

void PrintElem(QElemType_CSq e);

void PressEnter(){
	fflush(stdin);
	printf("Press Enter...");
	getchar();
	fflush(stdin);
 }

int main(int argc, char **argv)
{
	SqQueue Q;
	int i;
	QElemType_CSq e;

	printf("���� InitQueue_CSq ����...\n");
	{
		printf("��ʼ��ѭ��˳����� Q ...\n");
		InitQueue_CSq(&Q);
		printf("\n");
	}
	PressEnter();

	printf("���� QueueEmpty_CSq ����...\n");
	{
		QueueEmpty_CSq(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter();

	printf("���� EnQueue_CSq ����...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("Ԫ�� \"%2d\" ���Q��", 2*i);
			EnQueue_CSq(&Q, 2*i);
			printf("���ۼƵ� %d ��Ԫ�أ�...\n", QueueLength_CSq(Q));
		}
		printf("\n");
	}
	PressEnter();

	printf("���� QueueTraverse_CSq ����...\n");
	{
		printf(" Q �е�Ԫ��Ϊ��Q = ");
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter();

	printf("���� DeQueue_CSq ����...\n");
	{
		DeQueue_CSq(&Q, &e);
		printf("��ͷԪ�� \"%d\" ����...\n", e);
		printf(" Q �е�Ԫ��Ϊ��Q = ");
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter();

	printf("���� QueueLength_CSq ����...\n");
	{
		i = QueueLength_CSq(Q);
		printf(" Q �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter();

	printf("���� GetHead_CSq ����...\n");
	{
		GetHead_CSq(Q, &e);
		printf("��ͷԪ�ص�ֵΪ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter();

	printf("���� ClearQueue_CSq ����...\n");
	{
		printf("��� Q ǰ��");
		QueueEmpty_CSq(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		ClearQueue_CSq(&Q);
		printf("��� Q ��");
		QueueEmpty_CSq(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter();

	printf("���� DestroyQueue_CSq ����...\n");
	{
		printf("���� Q ǰ��");
		Q.base!=NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
		DestroyQueue_CSq(&Q);
		printf("���� Q ��");
		Q.base!=NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
		printf("\n");
	}
	PressEnter();

	return 0;
}

void PrintElem(QElemType_CSq e)
{
	printf("%d ", e);
}
