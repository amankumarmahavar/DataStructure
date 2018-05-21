#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.c"

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc, char *argv[])
{
	BiTree T;

	printf("▼1\n▲函数 InitBiTree 测试...\n");
	{
		printf("初始化一个空二叉树 T ...\n");
		InitBiTree(&T);
		printf("\n");
	}
	PressEnter;

	printf("▼4\n▲函数 BiTreeEmpty 测试...\n");
	{
		BiTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 CreateBiTree_Sq 测试...\n");
	{
		FILE *fp;

		printf("按先序序列创建二叉树...\n");
		printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree(fp, &T);
		fclose(fp);
		//CreateBiTree(&T);
		printf("\n");
	}
	PressEnter;


	printf("▼6、7\n▲函数 BiTreeDepth 测试...\n");
	{
		printf(" T 的深度为 %d \n", BiTreeDepth(T));
		printf("\n");
	}
	PressEnter;
/*
	printf("函数 LevelOrderTraverse 测试...\n");
	{
		printf("层序遍历二叉树 T = ");
		LevelOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
*/
	printf("函数 PreOrderTraverse_1 测试...\n");
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("函数 PreOrderTraverse_2 测试...\n");
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("函数 InOrderTraverse_1 测试...\n");
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("函数 PostOrderTraverse 测试...\n");
	{
		printf("后序遍历二叉树 T = ");
		PostOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	return 0;
}

void PrintElem(TElemType e)
{
	printf("%c ",e);
}

Status PrintElement(TElemType e)
{
	printf("%c ",e);
	return OK;
}
