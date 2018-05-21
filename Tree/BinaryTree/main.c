#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.c"

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc, char *argv[])
{
	BiTree T;

	printf("��1\n������ InitBiTree ����...\n");
	{
		printf("��ʼ��һ���ն����� T ...\n");
		InitBiTree(&T);
		printf("\n");
	}
	PressEnter;

	printf("��4\n������ BiTreeEmpty ����...\n");
	{
		BiTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ CreateBiTree_Sq ����...\n");
	{
		FILE *fp;

		printf("���������д���������...\n");
		printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree(fp, &T);
		fclose(fp);
		//CreateBiTree(&T);
		printf("\n");
	}
	PressEnter;


	printf("��6��7\n������ BiTreeDepth ����...\n");
	{
		printf(" T �����Ϊ %d \n", BiTreeDepth(T));
		printf("\n");
	}
	PressEnter;
/*
	printf("���� LevelOrderTraverse ����...\n");
	{
		printf("������������� T = ");
		LevelOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
*/
	printf("���� PreOrderTraverse_1 ����...\n");
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� PreOrderTraverse_2 ����...\n");
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("���� InOrderTraverse_1 ����...\n");
	{
		printf("������������� T = ");
		InOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("���� PostOrderTraverse ����...\n");
	{
		printf("������������� T = ");
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
