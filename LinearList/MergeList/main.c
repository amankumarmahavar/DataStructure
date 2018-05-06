#include "./MergeList.c"
#define M 6  //The Length of SinglyLinkedList used for Merge

void PrintElem(ElemType e);

int main()
{
	int i;
	LinkList La, Lb, Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	for(i=1; i<=M; i++)
	{
			printf("在 La 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert(La, i, 2*i);
	}
	for(i=1; i<=M; i++)
	{
			printf("在 Lb 第 %d 个位置插入 \"%d\" ...\n", i, 2*i+1);
			ListInsert(Lb, i, 2*i-1);
	}
	printf("\n\nLa = ");
	ListTarverse(La, PrintElem);
	printf("\n\nLb = ");
	ListTarverse(Lb, PrintElem);

    MergeList(&La,&Lb,&Lc);
    printf("\n\nLc = ");
	ListTarverse(Lc, PrintElem);

}


void PrintElem(ElemType e){
    printf("%d ",e);
}
