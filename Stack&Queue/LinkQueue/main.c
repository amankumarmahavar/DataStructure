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


	printf("函数 InitQueue_L 测试...\n");
	{
		printf("初始化链队 Q ...\n");
		InitQueue_L(&Q);
		printf("\n");
	}
	PressEnter;

	printf("函数 QueueEmpty_L 测试...\n");
	{
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("函数 EnQueue_L 测试...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("元素 \"%2d\" 入队，", 2*i);
			EnQueue_L(&Q, 2*i);
			printf("（累计第 %d 个元素）...\n", QueueLength_L(Q));
		}
		printf("\n");
	}
	PressEnter;

	printf("函数 QueueTraverse_L 测试...\n");
	{
		printf(" Q 中的元素为：Q = ");
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("函数 DeQueue_L 测试...\n");
	{
		DeQueue_L(&Q, &e);
		printf("队头元素 \"%d\" 出队...\n", e);
		printf(" Q 中的元素为：Q = ");
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("函数 QueueLength_L 测试...\n");
	{
		i = QueueLength_L(Q);
		printf(" Q 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("函数 GetHead_L 测试...\n");
	{
		GetHead_L(Q, &e);
		printf("队头元素的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("函数 ClearQueue_L 测试...\n");
	{
		printf("清空 Q 前：");
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		ClearQueue_L(&Q);
		printf("清空 Q 后：");
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("函数 DestroyQueue_L 测试...\n");
	{
		printf("销毁 Q 前：");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		DestroyQueue_L(&Q);
		printf("销毁 Q 后：");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}


