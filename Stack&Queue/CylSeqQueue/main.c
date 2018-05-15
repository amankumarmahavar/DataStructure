
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

	printf("函数 InitQueue_CSq 测试...\n");
	{
		printf("初始化循环顺序队列 Q ...\n");
		InitQueue_CSq(&Q);
		printf("\n");
	}
	PressEnter();

	printf("函数 QueueEmpty_CSq 测试...\n");
	{
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter();

	printf("函数 EnQueue_CSq 测试...\n");
	{
		for(i=1; i<=6; i++)
		{
			printf("元素 \"%2d\" 入队Q，", 2*i);
			EnQueue_CSq(&Q, 2*i);
			printf("（累计第 %d 个元素）...\n", QueueLength_CSq(Q));
		}
		printf("\n");
	}
	PressEnter();

	printf("函数 QueueTraverse_CSq 测试...\n");
	{
		printf(" Q 中的元素为：Q = ");
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter();

	printf("函数 DeQueue_CSq 测试...\n");
	{
		DeQueue_CSq(&Q, &e);
		printf("队头元素 \"%d\" 出队...\n", e);
		printf(" Q 中的元素为：Q = ");
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter();

	printf("函数 QueueLength_CSq 测试...\n");
	{
		i = QueueLength_CSq(Q);
		printf(" Q 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter();

	printf("函数 GetHead_CSq 测试...\n");
	{
		GetHead_CSq(Q, &e);
		printf("队头元素的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter();

	printf("函数 ClearQueue_CSq 测试...\n");
	{
		printf("清空 Q 前：");
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		ClearQueue_CSq(&Q);
		printf("清空 Q 后：");
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter();

	printf("函数 DestroyQueue_CSq 测试...\n");
	{
		printf("销毁 Q 前：");
		Q.base!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		DestroyQueue_CSq(&Q);
		printf("销毁 Q 后：");
		Q.base!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		printf("\n");
	}
	PressEnter();

	return 0;
}

void PrintElem(QElemType_CSq e)
{
	printf("%d ", e);
}
